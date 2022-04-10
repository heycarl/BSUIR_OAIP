// Copyright (c) Alexandr Efimchik 2022 18/03/2022
// Group 150702

// Структура содержит информацию о геометрических фигурах: площадь (число), 
// название (указатель), вложенное объединение – периметр (вещественное число) 
// и цвет (строка фиксированной длины). 
// Найти фигуры с максимальным периметром. Удалить фигуры заданного цвета.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
    long double ms_price = 5.0 / (80 * 60 * 1000);
    // long double ms_price = 4.0 / (80);
    printf("Enter minutes already spent: ");
    int m = 0;
    scanf("%d", &m);

    long double elapsed = ms_price * 1000 * 60 * m;
    while (1)
    {

        printf("Spent %10Lf on this LAB\n", elapsed);
        elapsed += ms_price * 50;
        Sleep(500);
        system("clear");
    }
    return 0;
}
