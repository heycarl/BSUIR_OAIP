// Население города ежегодно увеличивается на 1/n наличного состава жителей,
// где n-натуральное число. Через сколько лет население города  утроится.

#include <stdio.h>
#include <math.h>

double n,source;
int i = 0;


int main() {
   printf("LAB 2.2 task2 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter default people: \n");
   scanf("%lf", &n);
   source = 3 * n;
   while (source >= n)
   {
       n += 1 / n;
       i++;
   }
   
   printf("%d years\n", i);
   return 0;
}