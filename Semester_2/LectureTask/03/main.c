#include <stdio.h>
#include <stdlib.h>
#include "List.h"

// Выполнить сортировку четных(по значению) элементов двусвязного списка. Программа должна запрашиваться количество узлов при создании и их значения.
// Производить обмен указателей, а не инф полей

// Список создается путем добавления элемента в начало списка. Функция вывода реализует отображение списка начиная с конечного элемента.

typedef struct Node
{
    int value;
    struct NODE* next;
    struct NODE* previous;
} NODE;

int main(int argc, char const *argv[])
{
    NODE *ListRoot = NULL;
    int nElements;
    printf("Enter nodes num: \n");
    scanf("%d", &nElements);
    if (nElements == 0)
    {
        return 0;
    }
    
    int el;
    for (int i = 0; i < nElements; i++)
    {
        scanf("%d", &el);
        appendElement(&ListRoot, el);
    }
    // printList(ListRoot);

    if (nElements == 1)
    {
        printList(ListRoot);
        return 0;
    }

    NODE* p1 = ListRoot;
    while (p1 != NULL)
    {
        if (p1->value % 2 != 0) {
            p1 = p1->next;
            continue;
        }
        NODE* p2 = p1->next;
        while (p2 != NULL)
        {
            if (p1->value < p2->value && p2->value % 2 == 0)
            {
                swapNodes(p1, p2);
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    printList(ListRoot);
     


    return 0;
}
