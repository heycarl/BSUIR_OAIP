// Copyright (c) Alexandr Efimchik 2022 13/03/2022
// Group 150702

// Организовать три очереди с одинаковым количеством элементов, 
// содержащие соответствено имена, отчества и фамилии людей. 
// Составьте очередь из элементов, содержащих наиболее полную информацию о людях, 
// воспользовавшись уже созданными очередями и запросив какую-то дополнительную информацию. 
// Решение в программе оформляйте через подпрограммы.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    char *value;
    struct Node *next;
} Node;

typedef Node *NodePtr;

char *inputString();

void pushElement(NodePtr *srcRoot, char *element);
char *popElement(NodePtr *srcRoot);
void printList(NodePtr current);

int main()
{
    printf("LAB 6.1 by Efimchik Alexandr from GROUP 150702 \n");

    NodePtr fName_root = NULL;
    NodePtr lName_root = NULL;
    NodePtr mName_root = NULL;

    int person_num;
    printf("Enter person num: ");
    scanf("%d", &person_num);

    for (int i = 0; i < person_num; i++)
    {
        printf("Enter %d first name: ", i);
        pushElement(&fName_root, inputString());
        printf("Enter %d last name: ", i);
        pushElement(&lName_root, inputString());
        printf("Enter %d middle name: ", i);
        pushElement(&mName_root, inputString());
    }

    NodePtr DoB_root = NULL;
    NodePtr final_root = NULL;
    for (int i = 0; i < person_num; i++)
    {
        char *first_name = popElement(&fName_root);
        char *last_name = popElement(&lName_root);
        char *middle_name = popElement(&mName_root);
        printf("Enter date of birth for %s %s: ", first_name, last_name);
        char *dOb = inputString();

        size_t final_len = strlen(first_name) + strlen(last_name) + strlen(middle_name) + strlen(dOb) + 3;
        char *person = (char*)calloc(sizeof(char) * final_len, 1);
        strcat(person, first_name);
        strcat(person, " ");
        strcat(person, last_name);
        strcat(person, " ");
        strcat(person, middle_name);
        strcat(person, " ");
        strcat(person, dOb);
        pushElement(&final_root, person);    
    }

    printList(final_root);

    return 0;
}

void pushElement(NodePtr *srcRoot, char *element)
{
    NodePtr newElement = (NodePtr)calloc(sizeof(Node), 1);
    newElement->value = element;
    newElement->next = NULL;
    NodePtr *temp = srcRoot;
    if ((*srcRoot) == NULL) {
        *srcRoot = newElement;
        return;
    }
    while ((*temp)->next != NULL)
    {
        temp = &(*temp)->next;
    }
    (*temp)->next = newElement;
    
}

char *popElement(NodePtr *srcRoot)
{   
    char *value;
    if ((*srcRoot)->next == NULL) {
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
        printf("%s -> ", current->value);
        current = current->next;
    }
    printf("\nlist end\n");
}

char *inputString()
{
    char *current_word;
    current_word = calloc(sizeof(char), 1);
    int word_size = 0;
    char current_char = 0;
    current_char = getc(stdin);
    if (current_char != '\n') {
        current_word = realloc(current_word, sizeof(char) * (word_size + 1));
        current_word[word_size] = current_char;
        word_size++;
    }
    while (1)
    {
        current_char = getc(stdin);
        if (current_char == '\n')
        {
            break;
        }
        current_word = realloc(current_word, sizeof(char) * (word_size + 1));
        current_word[word_size] = current_char;
        word_size++;
    };
    current_word = realloc(current_word, sizeof(char) * (word_size + 1));
    current_word[word_size] = '\0';

    return current_word;
}