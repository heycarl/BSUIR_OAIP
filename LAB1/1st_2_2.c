// Определить, какие из заданных трёх действительных чисел a, b и c являются целыми.

#include <stdio.h>
#include <math.h>

double a,b,c;

int main() {
   printf("LAB 1.2 task2 by Efimchik Alexandr from GROUP 150702 \n");

   scanf("%lf%lf%lf", &a, &b, &c);

   if ((int)a - a != 0) {
      printf("%.2lf is not full\n", a);
   }
   if ((int)b - b != 0) {
      printf("%.2lf is not full\n", b);
   }
   if ((int)c - c != 0) {
      printf("%.2lf is not full\n", c);
   }
   
   return 0;
}