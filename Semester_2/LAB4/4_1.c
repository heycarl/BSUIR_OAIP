// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// 1. С клавиатуры заполнить файл словами. Вывести содержимое файла на экран.
// 2. Найти в файле слова, длина которых равна числу, введённому с клавиатуры.
// 3. Сделать реверс всех слов с длиной больше заданной.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(FILE *file, int length_filter, FILE *writeFile);
void writeReversedWord(FILE *writeFile, char *word, int word_len);
int validateFilename(char *name);
int checkIfLetter(char sym);
FILE *generateFile(char *mode);

int main()
{
    printf("LAB 4.1 by Efimchik Alexandr from GROUP 150702 \n");
    int find_length;
    printf("Enter word length for filer: ");
    scanf("%d", &find_length);
    FILE *f1 = generateFile("w+");

    char *current_word;
    while (1)
    {
        current_word = calloc(sizeof(char), 1);
        int word_size = 0;
        char current_char = 0;
        printf("Enter word: ");
        while (1)
        {
            current_char = getc(stdin);
            if (current_char == '\n')
            {
                break;
            }
            current_word = realloc(current_word, sizeof(char) * (word_size + 1));
            current_word[word_size] = current_char;
            word_size++;
        };
        current_word = realloc(current_word, sizeof(char) * (word_size + 1));
        current_word[word_size] = '\0';

        printf("Entered word: %s, len: %d\n", current_word, strlen(current_word));

        if (strcmp(current_word, "15070014") == 0)
        {
            printf("saved\n");
            break;
        }
        else
        {
            fprintf(f1, "%s ", current_word);
        }
    }

    int counted_words;
    FILE *f2 = generateFile("w");
    counted_words = countWords(f1, find_length, f2);
    printf("Num of words with length %d is %d\n", find_length, counted_words);
    fclose(f1);

    return 0;
}

int countWords(FILE *file, int length_filter, FILE *writeFile)
{
    fseek(file, 0, SEEK_SET);
    char *word = calloc(sizeof(char), 1);

    int filtered_count = 0;
    char current_char = getc(file);
    int len;
    int last_was_char = 0;

    do
    {
        len = -1;
        do
        {
            if (checkIfLetter(current_char))
            {
                len++;
                word = realloc(word, sizeof(char) * (len + 1));
                word[len] = current_char;
                current_char = getc(file);
                last_was_char = 1;
            }
            else
            {
                current_char = getc(file);
                break;
            }
        } while (checkIfLetter(current_char));
        if (!last_was_char)
        {
            continue;
        }
        len++;
        word = realloc(word, sizeof(char) * (len + 2));
        word[len + 1] = '\0';
        printf("Word %s is %d length\n", word, len);
        if (len > length_filter)
            writeReversedWord(writeFile, word, len);
        if (len == length_filter)
            filtered_count++;
        last_was_char = 0;
    } while (!feof(file));
    return filtered_count;
}

void writeReversedWord(FILE *writeFile, char *word, int word_len)
{
    printf("Reversing %s word\n", word);
    fseek(writeFile, 0, SEEK_SET);
    for (int i = word_len - 1; i > -1; i--)
    {
        fprintf(writeFile, "%c", word[i]);
    }
    printf(" ");
}

int validateFilename(char *name)
{
    if (strlen(name) > 20)
        return 0;
    return 1;
}

int checkIfLetter(char sym)
{
    return (sym > 64 && sym < 91) || (sym > 96 && sym < 123);
}

FILE *generateFile(char *mode)
{
    printf("Enter filename: ");

    char filename[20];
    FILE *file;

    while (1)
    {
        scanf("%s", filename);
        if (!validateFilename(filename))
        {
            printf("Invalid file name\n");
            continue;
        }
        else
        {
            break;
        }
    }
    if ((file = fopen(filename, mode)) == NULL)
        printf("File could not be opened\n");
    fseek(file, 0, SEEK_SET);
    getchar();
    return file;
}
