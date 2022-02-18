// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// Обязательно:
// Вводимые с клавиатуры данные записать в бинарный файл, вывести данные из файла на экран (см. задачу №1). (2 балла, 20 мин).
// Найти данные в файле и вывести на экран (см. задачу №2). (+3 балла, 20 мин).

// Желательно:
// Поменять местами элементы в файле (см. задачу №3). (+3 балла, 15 мин).
// Имя файла задаётся с клавиатуры, предусмотрена защита от ввода некорректных данных (+2 балла, 15 мин).

// С клавиатуры заполнить файл целыми числами.
// Посчитать, сколько в файле элементов, которые больше суммы всех предыдущих.
// Из двух бинарных файлов, заполненных по убыванию сформировать третий, заполненный по убыванию.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateFilename(char *name);

int main()
{
    printf("LAB3.1 by Efimchik Alexandr from GROUP 150702 \n");
    FILE *f1;
    printf("Enter filename: \n");

    char filename[20];

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

    if ((f1 = fopen(filename, "wb")) == NULL)
        printf("File could not be opened\n");

    printf("Enter nums (STOP num = 15070014): \n");
    int entered_num;
    do
    {
        scanf("%d", &entered_num);
        if (entered_num == 15070014)
            break;
        fwrite(&entered_num, sizeof(int), 1, f1);
    } while (1);

    fclose(f1);

    FILE *f2;
    f2 = fopen(filename, "rb");
    int num;
    int sum = 0;
    long start_address;
    start_address = ftell(f2);
    fread(&num, sizeof(int), 1, f2);
    do
    {
        sum += num;
        fread(&num, sizeof(int), 1, f2);
    } while (!feof(f2));

    int num_greater = 0;
    fseek(f2, -sizeof(int), SEEK_END);
    do
    {
        fread(&num, sizeof(int), 1, f2);
        sum -= num;
        if (sum < num)
            num_greater++;

        fseek(f2, -sizeof(int) * 2, SEEK_CUR);
    } while (ftell(f2) != start_address);

    fread(&num, sizeof(int), 1, f2);
    if (sum - num < num)
        num_greater++;

    printf("There are %d nums, that bigger than previous item sum\n", num_greater);
    fclose(f2);
    return 0;
}

int validateFilename(char *name)
{
    if (strlen(name) > 20)
        return 0;
    return 1;
}
