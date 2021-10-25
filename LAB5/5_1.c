// Дана матрица вещественных чисел N х М. Количество строк N и столбцов М задается пользователем. 
// Найти максимальный и минимальный элемент в каждой строке и поменять их местами. 
// Найти сумму элементов на главной диагонали.

#include <stdio.h>

int main()
{
    printf("LAB 5.2 by Efimchik Alexandr from GROUP 150702 \n");

    printf("Enter matrix size: ");
    int m, n;
    scanf("%d%d", &m, &n);
    int A[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    // int m = 5;
    // int n = 5;

    // int A[5][5] = {{5, 12, 3, -2, 32}, {6, -23, 0, 22, 323}, {15, 16, -3, -2, 232}, {99, -99, 52, 76, 2}, {0, 1, 3, -2, -667}};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < m; i++)
    {
        int max_i = 0;
        int min_i = 0;
        for (int j = 0; j < m; j++)
        {
            ((A[i][j] > A[i][max_i]) ? (max_i = j) : (max_i = max_i));
            ((A[i][j] < A[i][min_i]) ? (min_i = j) : (min_i = min_i));
        }
        int t;
        t = A[i][max_i];
        A[i][max_i] = A[i][min_i];
        A[i][min_i] = t;
        for (int j = 0; j < n; j++)
        {
            if (j == max_i)
                printf("\033[1;34m%d \033[0m", A[i][j]);
            else if (j == min_i)
                printf("\033[1;31m%d \033[0m", A[i][j]);
            else
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (i == j) ? (printf("\033[0;33m%d\033[0m ", A[i][j])) && (sum += A[i][j]) : (printf("%d ", A[i][j]));
        }
        printf("\n");
    }
    printf("\033[0;33m%d\033[0m\n", sum);
}