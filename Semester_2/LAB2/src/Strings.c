#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

char *inputString()
{
    char *current_word;
    current_word = calloc(1, sizeof(char));
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