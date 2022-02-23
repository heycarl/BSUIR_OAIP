// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// 1. Структура содержит информацию о геометрических фигурах: площадь (число),
// название (указатель), вложенную структуру – периметр (вещественное число)
// и цвет (строка фиксированной длины). Найти фигуры с площадью, меньше заданной.
// Удалить фигуры с заданным названием.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString();

struct figure
{
    int Square;
    char *Name;

    struct Params
    {
        float Perimeter;
        char Color[6];
    } params;
};

int main()
{
    printf("LAB 1.2 by Efimchik Alexandr from GROUP 150702 \n");
    printf("Enter figures num: ");
    int num;
    scanf("%d", &num);

    struct figure *figures;

    figures = calloc(sizeof(struct figure), num);

    for (int i = 0; i < num; i++)
    {
        printf("Enter %d figure name: ", i + 1);
        figures[i].Name = inputString();
        printf("Enter %d figure square: ", i + 1);
        scanf("%d", &figures[i].Square);
    }

    int menu;
    while (1)
    {
        
        printf("\nSuperStructSoftware\n");
        printf("1) Filter figures by square\n");
        printf("2) Delete figures by name\n");
        printf("3) View structs\n");
        printf("4) Exit\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            printf("Enter filter square: ");
            int filter_square;
            scanf("%d", &filter_square);
            printf("Figures, with square smaller than %d: \n", filter_square);
            printf(" ==============================\n");
            for (int i = 0; i < num; i++)
            {

                if (figures[i].Square < filter_square)
                {
                    printf("| Name: %6s | Square: %5d |\n", figures[i].Name, figures[i].Square);
                }
            }
            printf(" ==============================\n");
            break;
        case 2:
            printf("Specify delete filter: ");
            char *filter_name = inputString();
            printf("FIltered structs by name(%s): \n", filter_name);
            printf(" ==============================\n");
            for (int i = 0; i < num; i++)
            {

                if (!strcmp(filter_name, figures[i].Name))
                {
                    for (int j = i; j < num; j++)
                    {
                        figures[j] = figures[j+1];
                    }
                    num--;
                    figures = realloc(figures, sizeof(struct figure) * num);
                } else {
                    printf("| Name: %6s | Square: %5d |\n", figures[i].Name, figures[i].Square);
                }
            }
            printf(" ==============================\n");
            break;
        case 3:
            printf(" ==============================\n");
            for (int i = 0; i < num; i++)
            {
                printf("| Name: %6s | Square: %5d |\n", figures[i].Name, figures[i].Square);
            }
            printf(" ==============================\n");
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

char *inputString()
{
    char *current_word;
    current_word = calloc(sizeof(char), 1);
    int word_size = 0;
    char current_char = 0;
    getchar();
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

    return current_word;
}