// Copyright (c) Alexandr Efimchik 2022 18/02/2022
// Group 150702

// Написать программу, содержащую процедуру, которая вставляет новый элемент
// за каждым вхождением заданного элемента. Если элементы не найдены, то выдать
// на экран соответствующие сообщение.

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
void appendList(NodePtr *srcRoot);
void appendElement(NodePtr *current, int item);
void appendElementAfterElement(NodePtr *srcRoot, int filter, int element);

int main()
{
    printf("LAB 7.1 by Efimchik Alexandr from GROUP 150702 \n");

    NodePtr root = NULL;

    printf("********************************\n");
    printf("*      Choose menu option:     *\n");
    printf("* 1) Append list               *\n");
    printf("* 2) Add num after num         *\n");
    printf("* 3) Exit                      *\n");
    printf("********************************\n");

    int menu;
    while (1)
    {
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            appendList(&root);
            printList(root);
            break;
        case 2:
            int filter_num;
            printf("Enter filter element: ");
            scanf("%d", &filter_num);

            int element;
            printf("Enter element: ");
            scanf("%d", &element);

            appendElementAfterElement(&root, filter_num, element);
            printList(root);
            break;
        case 3:
            return 0;

        default:
            printf("Invalid menu option");
            break;
        }
    }

    return 0;
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
        printf("%d -> ", current->number);
        current = current->next;
    }
    printf("\nlist end\n");
}

void appendList(NodePtr *srcRoot)
{
    int num;
    printf("Enter list nums (STOP 15070014): \n");
    scanf("%d", &num);
    do
    {
        appendElement(srcRoot, num);
        scanf("%d", &num);
    } while (num != 15070014);
}

void appendElement(NodePtr *srcRoot, int element)
{
    NodePtr newRoot = (NodePtr)calloc(sizeof(Node), 1);
    newRoot->number = element;
    newRoot->next = *srcRoot;
    *srcRoot = newRoot;
}

void appendElementAfterElement(NodePtr *srcRoot, int filter, int element)
{
    NodePtr current, previous;
    previous = NULL;
    current = *srcRoot;
    while (current != NULL)
    {
        if (current->number == filter)
        {
            NodePtr newNode = (NodePtr)calloc(sizeof(Node), 1);
            newNode->number = element;
            newNode->next = current->next;
            current->next = newNode;
            if (previous != NULL)
            {
                previous->next = current;
            }
        }
        previous = current;
        current = current->next;
    }
    if (previous == NULL)
    {
        printf("No elements with %d value in list\n", filter);
    }
}