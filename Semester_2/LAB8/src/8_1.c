// Copyright (c) Alexandr Efimchik 2022 12/04/2022
// Group 150702

// Написать функцию для добавления элементов в дерево.
// Написать функцию для удаления всех элементов дерева(должна выполняться перед выходом из программы).
// Вывести дерево на консоль.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"
#include "Tree.h"

int main()
{
    printf("LAB 8.1 by Efimchik Alexandr from GROUP 150702 \n");
    printf("Enter nodes num: ");
    int num;
    scanf("%d", &num);

    struct Node *Root = NULL;

    for (int i = 0; i < num; i++)
    {
        printf("Enter %d node value: \n", i + 1);
        int n;
        scanf("%d", &n);
        addTreeElement(&Root, n);
    }
    printf("\nPrinted Tree:\n");
    printTree(Root, 5);
    deleteTreeElement(Root);

    return 0;
}