// Проверить, есть ли в матрице хотя бы одна строка, содержащая положительный элемент, и найти ее номер. 
// Знаки элементов предыдущей строки изменить на противоположные.


#include <stdio.h>

int main()
{
    printf("LAB 5.3 by Efimchik Alexandr from GROUP 150702 \n");

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

    int A[4][5] = {{-5, -12, -3, -2, -32}, {6, -23, 0, 22, 323}, {15, 16, -3, -2, 232}, {99, -99, 52, 76, 2}};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    int num = -1;
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] > 0)
            {
                flag = 1;
                num = i;
                break;
            }
        }
        if (flag) break;
    }
    printf("\n%d row consists above zero value\n\n", num);
    if (num == 0)
    {
        printf("First row consists above zero vanlue, passing ...\n");
        return 0;
    } else {
        for (int j = 0; j < n; j++)
        {
            int temp = A[num-1][j];
            A[num-1][j] = temp * -1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (i == num-1) ? (printf("\033[0;34m%d\033[0m ", A[i][j])) : (printf("%d ", A[i][j]));
        }
        printf("\n");
    }
}