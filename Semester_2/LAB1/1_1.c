// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// 1. Найти и вывести остаток от деления целого числа на 2, не выполняя деления
// и не используя операцию взятия остатка от деления.

#include <stdio.h>
#include <stdlib.h>

union number
{
    int dword;
    struct
    {
        unsigned mod : 1;
    }
    digits;
};

int main()
{
    printf("LAB 1.1 by Efimchik Alexandr from GROUP 150702 \n");
    printf("Enter num: ");
    union number n;
    scanf("%d", &n.dword);

    printf("Remainer afer division: %d\n", (n.digits.mod));
    
    return 0;
}