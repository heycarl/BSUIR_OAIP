// Copyright (c) Alexandr Efimchik 2022 13/03/2022
// Group 150702

// Создать очередь для целых (положительных и отрицательных) чисел.
// Максимальный размер очереди вводится с экрана.
// Создать функции для ввода, вывода и определения размера очереди.
// Ввести 6 элементов. Вывести 2 первых элемента очереди. Вывести размер оставшейся очереди.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef Node *NodePtr;

void pushElement(NodePtr *srcRoot, int element);
int popElement(NodePtr *srcRoot);
void printList(NodePtr current);
int queueSize(NodePtr current);

int main()
{
    NodePtr root = NULL;

    int items_num;
    printf("Enter person num: ");
    scanf("%d", &items_num);

    int d;
    for (int i = 0; i < items_num; i++)
    {
        printf("Enter %d num: ", i);
        scanf("%d", &d);
        pushElement(&root, d);
    }
    printf("Queue size: %d\n", queueSize(root));

    popElement(&root);
    popElement(&root);

    printList(root);
    printf("New queue size: %d\n", queueSize(root));

    return 0;
}

void pushElement(NodePtr *srcRoot, int element)
{
    NodePtr newElement = (NodePtr)calloc(sizeof(Node), 1);
    newElement->value = element;
    newElement->next = NULL;
    NodePtr *temp = srcRoot;
    if ((*srcRoot) == NULL)
    {
        *srcRoot = newElement;
        return;
    }
    while ((*temp)->next != NULL)
    {
        temp = &(*temp)->next;
    }
    (*temp)->next = newElement;
}

int popElement(NodePtr *srcRoot)
{
    int value;
    if ((*srcRoot)->next == NULL)
    {
        value = (*srcRoot)->value;
        (*srcRoot) = NULL;
        return value;
    }
    value = (*srcRoot)->value;
    NodePtr backupRoot = *srcRoot;
    (*srcRoot) = backupRoot->next;
    free(backupRoot);
    return value;
}

void printList(NodePtr current)
{
    printf("Printed list: \n");
    if (current == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("\nlist end\n");
}

int queueSize(NodePtr current)
{
    if (current == NULL)
    {
        printf("Empty list\n");
        return 0;
    }
    int size = 0;
    while (current != NULL)
    {
        current = current->next;
        size++;
    }
    return size;
}
