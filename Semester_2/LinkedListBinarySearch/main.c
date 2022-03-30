#include "stdio.h"
#include "stdlib.h"

typedef struct Item
{
    int value;
    struct Item *next;
    struct Item *previous;
} ITEM;

void pushElement(ITEM **Head, int val);
ITEM *createItem(int val);
ITEM *findMiddleItem(ITEM **ListRoot);

int main(int argc, char const *argv[])
{
    ITEM *root;
    pushElement(&root, 12);
    pushElement(&root, 14);
    pushElement(&root, 13);

    return 0;
}

void pushElement(ITEM **Head, int val)
{
    ITEM *Item = createItem(val);
    // No items
    if (*Head == NULL)
    {
        Item->next = Item;
        Item->previous = Item;
        *Head = Item;
        return;
    }
    // 1 Item
    if (*Head == (*Head)->previous && *Head == (*Head)->next)
    {
        if (val > (*Head)->value)
        {
            Item->previous = *Head;
            Item->next = *Head;
            (*Head)->next = Item;
            (*Head)->previous = Item;
            Item->value = val;
        }
        return;
    }
    // More than 1 item (need to be sorted)
    ITEM *MiddleItem = findMiddleItem(Head);
    if (MiddleItem->value > val) // left side from MiddleElement
    {
        MiddleItem->next = (*Head);
        (*Head)->previous = MiddleItem;
        /* code */
    }
    else // right side from MiddleElement
    {
        /* code */
    }
}

ITEM *findMiddleItem(ITEM **ListRoot)
{
    ITEM *L_Ptr = *ListRoot;
    ITEM *R_Ptr = (*ListRoot)->previous;

    while (L_Ptr != R_Ptr || L_Ptr->next != R_Ptr)
    {
        L_Ptr = L_Ptr->next;
        R_Ptr = R_Ptr->previous;
    }
    return L_Ptr;
}

ITEM *createItem(int val)
{
    ITEM *Item = (ITEM *)calloc(1, sizeof(ITEM));
    Item->value = val;
    return Item;
}
