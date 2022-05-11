// Copyright (c) Alexandr Efimchik 2022 13/03/2022
// Group 150702

// Написать функции для добавления, удаления, вывода на экран стека

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int number;
    struct Node *next;
} Node;

typedef Node *NodePtr;

void printList(NodePtr);
void pushElement(NodePtr *current, int item);
int popElement(NodePtr *srcRoot);

int main()
{
    NodePtr root1 = NULL;

    int items_num;
    printf("Enter item num: ");
    scanf("%d", &items_num);

    int n;

    for (int i = 0; i < items_num; i++)
    {
        scanf("%d", &n);
        pushElement(&root1, n);
    }

    for (int i = 0; i < items_num; i++)
    {
        n = popElement(&root1);
        printf("%d\n", n);
    }

    return 0;
}

void pushElement(NodePtr *srcRoot, int element)
{
    NodePtr newRoot = (NodePtr)calloc(sizeof(Node), 1);
    newRoot->number = element;
    newRoot->next = *srcRoot;
    *srcRoot = newRoot;
}

int popElement(NodePtr *srcRoot)
{
    int value = (*srcRoot)->number;
    NodePtr backupRoot = *srcRoot;
    (*srcRoot) = backupRoot->next;
    free(backupRoot);
    return value;
}