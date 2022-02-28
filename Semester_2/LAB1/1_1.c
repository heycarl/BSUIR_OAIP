// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// 1. Найти и вывести остаток от деления целого числа на 2, не выполняя деления
// и не используя операцию взятия остатка от деления.

#include <stdio.h>
#include <stdlib.h>

struct mod
{
    unsigned a : 1;
};

int main()
{
    printf("LAB 1.1 by Efimchik Alexandr from GROUP 150702 \n");
    
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    struct mod* mod = (struct mod*) &num;
    printf("%d", mod->a);    
    return 0;
}