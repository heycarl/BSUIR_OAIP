// Copyright (c) Alexandr Efimchik 2022 12/04/2022
// Group 150702

// Структура содержит информацию о геометрических фигурах: площадь (число), 
// название (указатель), вложенное объединение – периметр (вещественное число) 
// и цвет (строка фиксированной длины). 
// Найти фигуры с максимальным периметром. Удалить фигуры заданного цвета.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"
#include "Struct.h"

int main()
{
    printf("LAB 2.2 by Efimchik Alexandr from GROUP 150702 \n");
    printf("Enter figures num: ");
    int num;
    scanf("%d", &num);

    struct figure *figures;

    figures = calloc(num, sizeof(struct figure));

    for (int i = 0; i < num; i++)
    {
        printf("Enter %d figure name: ", i + 1);
        figures[i].Name = inputString();
        printf("What would you like to enter: \n1)Perimeter\n2)Color\n?\n");
        int d;
        scanf("%d", &d);
        switch (d)
        {
        case 1:
            printf("Enter %d figure perimeter: ", i + 1);
            scanf("%f", &figures[i].params.Perimeter);
            break;
        case 2:
            printf("Enter %d figure color: ", i + 1);
            char buffer[7];
            while (1)
            {
                fflush(stdin);
                scanf("%s", buffer);
                if (strlen(buffer) != 6)
                {
                    printf("Invald color (need to be hex)\n");
                    continue;
                } else {
                    strcpy(figures[i].params.Color, buffer);
                    figures[i].params.Color[6] = '\0';
                    break;
                } 
            }
            printf("Entered: %s\n", figures[i].params.Color);
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }

    int menu;
    while (1)
    {

        printf("\nSuperStructSoftware\n");
        printf("1) Filter figures by perimeter\n");
        printf("2) Delete figures by color\n");
        printf("3) View structs\n");
        printf("4) Exit\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            printf("Enter filter perimeter: ");
            float filter_perimeter;
            scanf("%f", &filter_perimeter);
            printf("Figures, with perimeter smaller than %f: \n", filter_perimeter);
            printf(" ==============================\n");
            for (int i = 0; i < num; i++)
            {
                if (figures[i].params.flag)
                    continue; 
                if (figures[i].params.Perimeter < filter_perimeter)
                {
                    printf("| Name: %6s | Perimeter: %5.5f |\n", figures[i].Name, figures[i].params.Perimeter);
                }
            }
            printf(" ==============================\n");
            break;
        case 2:
            printf("Specify delete filter: ");
            char buffer[7];
            while (1)
            {
                fflush(stdin);
                scanf("%s", buffer);
                if (strlen(buffer) != 6)
                {
                    printf("Invald color (need to be hex)\n");
                } else {
                    buffer[6] = '\0';
                    break;
                }
            }
            for (int i = 0; i < num; i++)
            {
                if (!figures[i].params.flag)
                    continue; 
                if (!strcmp(buffer, figures[i].params.Color))
                {
                    for (int j = i + 1; j < num; j++)
                    {
                        figures[j - 1] = figures[j];
                    }
                    num--;
                    figures = realloc(figures, sizeof(struct figure) * num);
                }
            }
            viewData(figures, num);
            break;
        case 3:
            viewData(figures, num);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid menu index\n");
            break;
        }
    }
    return 0;
}