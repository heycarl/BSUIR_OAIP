// Из двух упорядоченных одномерных массивов (длины K и N) сформируйте одномерный массив размером K+N,
// упорядоченный так же, как исходные массивы.

#include <stdio.h>
#include <math.h>

int k, n = 0;

int main() {
    printf("LAB 4.2 by Efimchik Alexandr from GROUP 150702 \n");

    printf("Enter array sizes: ");
    scanf("%d%d", &k, &n);
    int A[k];
    int B[n];
    int len = k+n;
    int C[k+n];

    for (int i = 0; i < k; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (int i = 0; i < k; i++) {
        C[i] = A[i];
    }
    for (int i = k; i < len; i++) {
        C[i] = B[i-k];
    }

    for (int i = 0; i < len; i++) {
        printf("%d\n", C[i]);
    }

    return 0;
}