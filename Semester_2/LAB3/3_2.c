// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// С клавиатуры заполнить файл целыми числами.
// Посчитать, сколько в файле элементов, которые больше суммы всех предыдущих.
// Из двух бинарных файлов, заполненных по убыванию сформировать третий, заполненный по убыванию.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *generateFile(int *dataPointer, size_t dataSize, char *filename);
int main()
{
    printf("LAB 3.2 by Efimchik Alexandr from GROUP 150702 \n");

    int a[] = {9, 7, 5, 1};
    FILE *f1 = generateFile(a, sizeof(a), "f1");

    int b[] = {8, 6, 4, 2, 0};
    FILE *f2 = generateFile(b, sizeof(b), "f2");

    FILE *f3;
    if ((f3 = fopen("f3",  "w+b")) == NULL)
        printf("File could not be opened\n");

    int a_num, b_num;
    while (fread(&a_num, 4, 1, f1))
    {
        fseek(f1, -4, SEEK_CUR);
        fread(&a_num, sizeof(int), 1, f1);
        fread(&b_num, sizeof(int), 1, f2);
        if (a_num > b_num)
        {
            fwrite(&a_num, sizeof(int), 1, f3);
            fseek(f2, -1 * sizeof(int), SEEK_CUR);
        }
        else
        {
            fwrite(&b_num, sizeof(int), 1, f3);
            fseek(f1, -1 * sizeof(int), SEEK_CUR);
        }
    };

    while (fread(&b_num, 4, 1, f2))
    {
        fseek(f2, -4, SEEK_CUR);
        fread(&b_num, sizeof(int), 1, f2);
        fwrite(&b_num, sizeof(int), 1, f3);
    };

    int number;
    fseek(f3, 0, SEEK_SET);
    fread(&number, sizeof(int), 1, f3);
    while (!feof(f3))
    {
        printf("Num: %d\n", number);
        fread(&number, sizeof(int), 1, f3);
    };

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}

FILE *generateFile(int *dataPointer, size_t dataSize, char *filename) {
    FILE *file;
    if ((file = fopen(filename, "w+b")) == NULL)
        printf("source file could not be opened\n");
    fwrite(dataPointer, dataSize, 1, file);
    fseek(file, 0, SEEK_SET);
    return file;
}