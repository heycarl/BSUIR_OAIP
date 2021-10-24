// Дана целочисленная прямоугольная матрица.
// Определить количество столбцов, не содержащих ни одного нулевого элемента.

#include <stdio.h>

int main()
{
    printf("LAB 5.2 by Efimchik Alexandr from GROUP 150702 \n");

    // printf("Enter matrix size: ");
    // int m, n;
    // scanf("%d%d", &m, &n);
    // int A[m][n];
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         scanf("%d", &A[i][j]);
    //     }
    // }
    int m = 4;
    int n = 5;

    int A[5][5] = {{5, 12, 3, -2, 32}, {6, -23, 0, 22, 323}, {15, 16, -3, -2, 232}, {99, -99, 52, 76, 2}};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    int num = 0;
    for (int j = 0; j < n; j++)
    {
        int flag = 0;
        for (int i = 0; i < m; i++)
        {
            if (A[i][j] == 0)
            {
                flag = 1;
                break;
            }
        }
        (!flag) ? (num += 1) : (num = num);
    }
    printf("\n%d\n", num);
}