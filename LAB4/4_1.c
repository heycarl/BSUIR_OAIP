// Отсортировать массив в порядке убывания методом вставок
// Выполнить сортировку четных элементов методом пузырька.
// Выполнить сортировку отрицательных элементов методом вставок.
// Выполнить сортировку положительных элементов методом выбора.
// Выполнить сортировку нечетных элементов методом Шелла.

#include <stdio.h>
#include <math.h>

int n = 0;

int swap(int a, int b, int c[])
{
    int temp = c[a];
    c[a] = c[b];
    c[b] = temp;
    return 0;
}

int main()
{
    printf("LAB 4.1 by Efimchik Alexandr from GROUP 150702 \n");

    printf("Enter array sizes: ");
    scanf("%d", &n);
    int A[n];

    for (int i = 0; i < n; i++) 
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // [1 task][done] Отсортировать массив в порядке убывания методом вставок
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && A[j - 1] < A[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
        {
            swap(j - 1, j, A); // меняем местами элементы j и j-1
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // [2 task][done] Выполнить сортировку четных элементов методом пузырька.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (A[j] > A[j + 1] && i % 2 == 0)
            {
                swap(j, j + 1, A);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // [3 task][done] Выполнить сортировку отрицательных элементов методом вставок.
    for (int i = 1; i < n; i++)
    {
        if (A[i] < 0)
        {
            for (int j = i; j > 0 && A[j - 1] > A[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
            {
                swap(j - 1, j, A); // меняем местами элементы j и j-1
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // [4 task][done] Выполнить сортировку положительных элементов методом выбора.
    int min_index;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            min_index = i;
            for (int j = i; j < n; j++)
            {
                if (A[j] < A[min_index])
                {
                    min_index = j;
                }
            }
            swap(min_index, i, A);
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // [5 task][done] Выполнить сортировку нечетных элементов методом Шелла.
    for (int hap = n / 2; hap > 0; hap--)
    {
        for (int i = 0; i < n - hap; i++)
        {
            if (i % 2 != 0)
            {
                // for (int k = 0; k < n; k++)
                // {
                //     if (k == i || k == i + hap)
                //     {
                //         if (A[i] > A[i + hap]) printf("\033[1;33m%d\033[0m ", A[k]);
                //         else printf("\033[1;31m%d\033[0m ", A[k]);
                //     }
                //     else
                //     {
                //         printf("%d ", A[k]);
                //     }
                // }
                // printf("\n");
                if (A[i] > A[i + hap])
                {
                    swap(i, i + hap, A);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}