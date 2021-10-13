// Ввести массив вещественных чисел размером п, п вводиться с клавиатуры. 
// Найти его наибольший и наименьший элементы и поменять их местами. 
// Найти сумму и произведение всех элементов массива.

#include <stdio.h>
#include <math.h>

int p;
float SUM = 0;
float MULT = 1;
float max = 0;
int max_i, min_i;

int main() {
   printf("LAB 3.1 task2 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter array size: \n");
   scanf("%d", &p);
   double A[p];

   for (int i = 0; i < p; i++)
   {
       scanf("%lf", &A[i]);
       SUM += A[i];
       MULT *= A[i];
   }

   // find max
   for (int i = 0; i < p; i++)
   {
       if (A[i] > max) {
           max = A[i];
           max_i = i;
       }
   }
   float min = max;
   // find min
   for (int i = 0; i < p; i++)
   {
       if (A[i] < min) {
           min = A[i];
           min_i = i;
       }
   }

   A[max_i] = min;
   A[min_i] = max;
   
   printf("\nSUM: %.2lf\n", SUM);
   printf("Multiplied: %.2lf\n", MULT);

   printf("Max: %.2lf\n", max);
   printf("Min: %.2lf\n", min);

   printf("Max_i: %d\n", max_i);
   printf("Min_i: %d\n", min_i);

   for (int i = 0; i < p; i++)
   {
       printf("%.2lf ", A[i]);
   }
   return 0;
}