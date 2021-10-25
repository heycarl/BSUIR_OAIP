// Дана целочисленная прямоугольная матрица.
// Определить количество столбцов, не содержащих ни одного нулевого элемента.

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