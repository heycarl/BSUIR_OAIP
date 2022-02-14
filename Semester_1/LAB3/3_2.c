// В одномерном массиве, состоящем из n вещественных элементов, вычислить:
//  - максимальный по модулю элемент массива;
//  - сумму элементов массива, расположенных между первым и вторым положительными 
//  элементами.

#include <stdio.h>
#include <math.h>

int n;

int main() {
   printf("LAB 3.2 task2 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter array size: \n");
   scanf("%d", &n);
   double A[n];
   double max = 0;

   for (int i = 0; i < n; i++)
   {
       scanf("%lf", &A[i]);
       if (fabs(A[i]) > max) {
           max = fabs(A[i]);
       }
   }

   double sum;
   int flag = 0;
   for (int i = 0; i < n; i++)
   {    
       if (flag == 1 && A[i] > 0) {
           break;
       }
       if (flag == 1 && A[i] < 0) {
           sum += A[i];
           continue;
       }
       if (flag == 0 && A[i] > 0) {
           flag = 1;
           continue;
       }
   }
   printf("MAX: %.2lf\n", max);
   printf("SUM: %.2lf\n", sum);
   return 0;
}