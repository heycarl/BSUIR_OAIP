#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

void addTreeElement(struct Node **TreeRoot, int value)
{
    if (!(*TreeRoot))
    {
        struct Node *NewNode = calloc(1, sizeof(struct Node));
        NewNode->value = value;
        NewNode->Left = NULL;
        NewNode->Right = NULL;
        *TreeRoot = NewNode;
        return;
    }
    if (value > (*TreeRoot)->value)
    {
        addTreeElement(&((*TreeRoot)->Right), value);
    }
    else
    {
        addTreeElement(&((*TreeRoot)->Left), value);
    }
}

void deleteTreeElement(struct Node *TreeRoot)
{
    if (TreeRoot->Right != NULL)
    {
        deleteTreeElement(TreeRoot->Right);
    }
    if (TreeRoot->Left != NULL)
    {
        deleteTreeElement(TreeRoot->Left);
    }
    free(TreeRoot);
}

void printTree(struct Node *treePtr, int spaces)
{
    int loop; // loop counter

    // while not the end of tree
    while (treePtr != NULL)
    {

        // recursive call with right subtree
        printTree(treePtr->Right, spaces + 4);

        // loop and output spaces
        for (loop = 1; loop <= spaces; loop++)
        {
            printf(" ");
        } // end for
        printf("%d\n", treePtr->value);

        // set pointer to left subtree and make recursive call
        printTree(treePtr->Left, spaces + 4);
        treePtr = NULL;
    } // end while
} 