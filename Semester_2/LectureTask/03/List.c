#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int value;
    struct NODE* next;
    struct NODE* previous;
} NODE;

void appendElement(NODE** Head, int element) {
    NODE* newItem = (NODE*)calloc(1, sizeof(NODE));
    newItem->value = element;
    newItem->previous = NULL;
    // Blank list
    if (*Head == NULL)
    {
        newItem->next = NULL;
        *Head = newItem;
        return;
    }
    newItem->next = *Head;
    (*Head)->previous = newItem;
    *Head = newItem;
}

void printList(NODE* current)
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

void swapNodes(NODE* Node1, NODE* Node2)
{
    int t = Node1->value;
    Node1->value = Node2->value;
    Node2->value = t;
    return;
}