// Заполнить массив с клавиатуры. Удалить все элементы, которые меньше предыдущего.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("LAB 6.1 by Efimchik Alexandr from GROUP 150702 \n");

    printf("Enter array sizes: ");
    int n = 0;
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
    }
    int *A[5];
    A[0] = ptr + 0;
    A[1] = ptr + 1;
    A[2] = ptr + 2;
    A[3] = ptr + 3;
    A[4] = ptr + 4;
    if (!ptr)
        return 0;
    for (int i = 0; i < n; i++)
    {
        int a = *(ptr + i);
        int b = *(ptr + i + 1);
        if (a < b)
        {
            printf("%d is smaller than %d \n", i, i+1);
            for (int j = i; j < n-1; j++)
            {
                *(ptr + j) = *(ptr + j + 1);
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
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    return 0;
}