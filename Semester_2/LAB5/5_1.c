// Copyright (c) Alexandr Efimchik 2022 13/03/2022
// Group 150702

// Создать текстовые файлы, содержащие один текстовую, а другой числовую информацию 
// (количество слов и чисел должно быть одинаковым). Используя стек, создать другой текстовый файл,
// в котором числа и слова чередовались, а порядок чисел и слов был бы сохранен. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int number;
    struct Node *next;
} Node;

typedef Node *NodePtr;

int validateFilename(char *name);
FILE *generateFile(char *mode, char *filename);

void printList(NodePtr);
void pushElement(NodePtr *current, int item);
int popElement(NodePtr *srcRoot);

int main()
{
    printf("LAB 5.1 by Efimchik Alexandr from GROUP 150702 \n");

    NodePtr root1 = NULL;
    NodePtr root2 = NULL;

    FILE *f1 = generateFile("w+", "f1");
    FILE *f2 = generateFile("w+", "f2");

    int items_num;
    printf("Enter item num: ");
    scanf("%d", &items_num);

    char b;
    int n;
    for (int i = 0; i < items_num; i++)
    {
        printf("\nEnter %d char and num: ");
        getchar();
        scanf("%c %d", &b, &n);
        fprintf(f1, "%c", b);        
        fprintf(f2, "%d ", n);
    }
    fseek(f1, SEEK_SET, 0);
    fseek(f2, SEEK_SET, 0);

    for (int i = 0; i < items_num; i++)
    {
        fscanf(f1, "%c", &b);
        pushElement(&root1, b);

        fscanf(f2, "%d", &n);
        pushElement(&root2, n);
    }

    FILE *out = generateFile("w+", "output");
    for (int i = 0; i < items_num; i++)
    {
        b = popElement(&root1);
        n = popElement(&root2);

        fprintf(out, "%c | %d\n", b, n);
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

FILE *generateFile(char *mode, char *filename)
{   
    if (!validateFilename(filename))
        return NULL;
    
    FILE *file;
    if ((file = fopen(filename, mode)) == NULL)
        printf("File could not be opened\n");
    fseek(file, 0, SEEK_SET);
    return file;
}

int validateFilename(char *name)
{
    if (strlen(name) > 20)
        return 0;
    return 1;
}
