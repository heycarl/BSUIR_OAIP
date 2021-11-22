// Заполнить массив с клавиатуры. Удалить все элементы, которые меньше предыдущего.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("LAB 6.1 by Efimchik Alexandr from GROUP 150702 \n");

    printf("Enter array sizes: ");
    int n = 0;
    scanf("%d", &n);

    int *ptr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    if (!ptr)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] < ptr[i+1])
        {
            printf("%d is smaller than %d \n", i, i+1);
            for (int j = i; j < n-1; j++)
            {
                ptr[j] = ptr[j+1];
            }
            n--;
            if (realloc(ptr, n * sizeof(int)))
            {
                printf("Freed!\n");
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    return 0;
}