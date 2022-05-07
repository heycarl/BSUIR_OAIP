struct Node
{
    int value;
    struct Node *Left;
    struct Node *Right;
};

void addTreeElement(struct Node **TreeRoot, int value);
void deleteTreeElement(struct Node *TreeRoot);
void printTree( struct Node* treePtr, int spaces );