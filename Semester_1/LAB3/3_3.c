// Проверить, имеется ли в одномерном числовом массиве A из n элементов, 
// хотя бы одна пара взаимно обратных чисел.

#include <stdio.h>
#include <math.h>

int n;

int main() {
   printf("LAB 3.3 task2 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter array size: \n");
   scanf("%d", &n);
   double A[n];
   double max = 0;

   for (int i = 0; i < n; i++)
   {
       scanf("%lf", &A[i]);
   }

   double sum;
   int flag = 0;
   for (int i = 0; i < n; i++)
   {    
        for (int j = 0; j < n; j++)
        {    
            if (A[i] == -1 * A[j]) {
                printf("This nums are %.2lf and %.2lf\n", A[i], A[j]);
                return 0;
            }
        }
   }
   printf("No nums for this condition\n");
   return 0;
}