#include "stdio.h"
#include "stdlib.h"
#include "time.h"

typedef struct Item
{
    int value;
    struct Item *next;
    struct Item *previous;
} ITEM;

void pushElement(ITEM **Head, int val);
ITEM *createItem(int val);
ITEM *findMiddleItem(ITEM *ListRoot, ITEM *ListEnd);
ITEM *findMiddleItemSF(ITEM *ListRoot, ITEM *ListEnd);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    ITEM *root = NULL;

    for (int i = 0; i < 100; i++)
    {
        pushElement(&root, rand() % 100);
    }

    for (int i = 0; i < 50; i++)
    {
        printf("%d--> ", root->value);
        root = root->next;
    }
    printf("\n");
    for (int i = 0; i < 51; i++)
    {
        printf("%d--> ", root->value);
        root = root->next;
    }

    // printf("2nd element value: %d\n", (root+sizeof(ITEM)*2)->value);
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
        else
        {
            Item->next = (*Head);
            Item->previous = (*Head);
            (*Head)->next = Item;
            (*Head)->previous = Item;
            *Head = Item;
        }
        return;
    }
    // More than 1 item (need to be sorted)

    ITEM *VirtualHead = *Head;
    ITEM *VirtualEnd = (*Head)->previous;
    ITEM *MiddleElement = findMiddleItemSF(VirtualHead, VirtualEnd);

    if ((*Head)->value > val)
    {
        Item->next = *Head;
        Item->previous = (*Head)->previous;
        (*Head)->next->previous = Item;
        (*Head)->previous->next = Item;
        *Head = Item;
        return;
    }
    else if ((*Head)->previous->value < val)
    {
        Item->next = *Head;
        Item->previous = (*Head)->previous;
        (*Head)->previous->next = Item;
        (*Head)->previous = Item;
        return;
    }
    else
    {
        do
        {
            if (MiddleElement->value <= val && MiddleElement->next->value >= val)
            { // Insert after middle element
                Item->next = MiddleElement->next;
                Item->previous = MiddleElement;
                MiddleElement->next = Item;
                return;
            }

            if (MiddleElement->value > val)
                VirtualEnd = MiddleElement;
            else
                VirtualHead = MiddleElement;

            MiddleElement = findMiddleItemSF(VirtualHead, VirtualEnd);
        } while (1);
    }
}

ITEM *findMiddleItem(ITEM *ListRoot, ITEM *ListEnd)
{
    ITEM *L_Ptr = ListRoot;
    ITEM *R_Ptr = ListEnd;

    while (L_Ptr == R_Ptr && L_Ptr->next != R_Ptr)
    {
        L_Ptr = L_Ptr->next;
        R_Ptr = R_Ptr->previous;
    }
    return L_Ptr;
}

ITEM *findMiddleItemSF(ITEM *ListRoot, ITEM *ListEnd)
{
    ITEM *Slow_Navigator = ListRoot;
    ITEM *FastNavigator = ListRoot;

    while (FastNavigator != ListEnd)
    {
        // fast is moved one step ahead
        FastNavigator = FastNavigator->next;
        // if fast is not the last element
        if (FastNavigator != ListEnd)
        {
            // slow pointer is moved one step ahead
            Slow_Navigator = Slow_Navigator->next;
            // fast pointer is moved second step ahead
            FastNavigator = FastNavigator->next;
        }
    }

    return Slow_Navigator;
}

ITEM *createItem(int val)
{
    ITEM *Item = (ITEM *)malloc(sizeof(ITEM));
    Item->value = val;
    return Item;
}