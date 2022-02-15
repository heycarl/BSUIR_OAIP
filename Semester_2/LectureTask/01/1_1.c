// Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию.
// Скопировать в файл F2 только четные строки из F1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** splitLines(FILE *file, int *return_num_words);

int main()
{
    FILE *f1;
    if ((f1 = fopen("F1.txt", "w")) == NULL)
        printf("File could not be opened\n");
    for (int i = 0; i < 12; i++)
    {
        fprintf(f1, "%d row\n", i);
    }
    fclose(f1);

    // осуждаем 256 символов
    // char a[256];
    // fgets(a, sizeof(a), f2);
    // printf("%s", a);

    f1 = NULL;
    if ((f1 = fopen("F1.txt", "r+")) == NULL)
        printf("File could not be opened\n");

    int num_words;
    char **lines;
    lines = splitLines(f1, &num_words);
    fclose(f1);

    FILE *f2;
    if ((f2 = fopen("F2.txt", "w")) == NULL)
        printf("File could not be opened\n");
    for (int i = 0; i < num_words; i++)
    {
        if (i % 2 == 0)
        {
            fprintf(f2, "%s\n", lines[i]);
        }
    }
    fclose(f2);

    return 0;
}

char ** splitLines(FILE *file, int *return_num_words)
{
    char **lines;
    lines = (char **)calloc(sizeof(char *), 1);

    char t = getc(file);
    int num_words = 0;
    lines[0] = calloc(sizeof(char), 1);
    int len;

    do
    {
        len = -1;
        do
        {
            len++;
            lines[num_words] = realloc(lines[num_words], sizeof(char) * (len + 1));
            lines[num_words][len] = t;
            t = getc(file);
        } while (t != '\n' && t != '\0');

        lines[num_words] = realloc(lines[num_words], sizeof(char) * (len + 2));
        lines[num_words][len + 1] = '\0';

        num_words++;
        lines = (char **)realloc(lines, sizeof(char *) * (num_words + 1));
        lines[num_words] = calloc(sizeof(char), 1);
        t = getc(file);
    } while (!feof(file));
    *return_num_words = num_words;
    return lines;
}