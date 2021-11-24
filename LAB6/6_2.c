// Заполнить элементы двумерного массива вещественными числами.
// В каждом столбце после максимального элемента добавить 0

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("LAB 6.2 by Efimchik Alexandr from GROUP 150702 \n");

    printf("Enter array sizes: ");
    int n = 0; // rows
    int m = 0; // column
    scanf("%d %d", &n, &m);

    float **ptr = (float**)calloc((n + 1), sizeof(float*));
    for (int i = 0; i < n + 1; i++)
    {
        *(ptr + i) = (float*)calloc(m, sizeof(float));
        for (int j = 0; j < m; j++)
        {
            scanf("%f", &ptr[i][j]);
        }
    }

    if (!ptr)
        return 0;

    for (int i = 0; i < m; i++)
    {
        int max = 0;
        for (int j = 0; j < n; j++)
        {
            max = (ptr[j][i]) >= (ptr[max][i]) ? (j) : (max);
        }
        for (int j = n; j > max; j--)
        {
            ptr[j][i] = ptr[j - 1][i];
        }
        ptr[max + 1][i] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%.2lf ", ptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}