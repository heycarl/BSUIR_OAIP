// Copyright (c) Alexandr Efimchik 2022
// Group 150702

// Найти и вывести на экран самое большое симметричное слово текста.
// Если симметричных слов в тексте нет, вывести соответствующее сообщение.
// В программе используйте подпрограммы.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitWords(FILE *file, int *return_num_words);
int checkIfLetter(char sym);
int checkPalindrom(char *s);

int main()
{
    printf("Lecture task 2 by Efimchik Alexandr from GROUP 150702 \n");
    FILE *f1;
    if ((f1 = fopen("F1.txt", "r")) == NULL)
        printf("File could not be opened\n");

    int num_words;
    char **words;
    words = splitWords(f1, &num_words);
    fclose(f1);
    int max_palindrom_index = 0;
    for (int i = 0; i < num_words; i++)
    {
        max_palindrom_index = (checkPalindrom(words[i]) && strlen(words[i]) >= strlen(words[max_palindrom_index])) ? i : max_palindrom_index;
    }
    if (max_palindrom_index == 0 && !checkPalindrom(words[0])) {
        printf("No palindromes in text\n");
    } else {
        printf("The largest palindrome is: %s\n", words[max_palindrom_index]);
    }

    return 0;
}

char **splitWords(FILE *file, int *return_num_words)
{
    char **words;
    words = (char **)calloc(sizeof(char *), 1);

    char current_char = getc(file);
    int num_words = 0;
    words[0] = calloc(sizeof(char), 1);
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
                words[num_words] = realloc(words[num_words], sizeof(char) * (len + 1));
                words[num_words][len] = current_char;
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
        words[num_words] = realloc(words[num_words], sizeof(char) * (len + 2));
        words[num_words][len + 1] = '\0';

        num_words++;
        words = (char **)realloc(words, sizeof(char *) * (num_words + 1));
        words[num_words] = calloc(sizeof(char), 1);
        last_was_char = 0;
    } while (!feof(file));
    *return_num_words = num_words;
    return words;
}

int checkIfLetter(char sym)
{
    return (sym > 64 && sym < 91) || (sym > 96 && sym < 123);
}

int checkPalindrom(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != s[strlen(s) - i - 1])
        {
            return 0;
        }
    }
    return 1;
}