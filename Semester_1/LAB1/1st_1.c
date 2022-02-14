// Ввести катеты прямоугольного треугольника. Найти его гипотенузу и площадь.
// Результат вывести с точностью до двух знаков после запятой.


#include <stdio.h>
#include <math.h>

float a,b,s,g;

int main() {
   printf("LAB 1.1 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter a and b sides: \n");
   scanf("%f%f", &a, &b);
   s = a * b;
   g = sqrt(pow(a, 2) + pow(b, 2));
   printf("Sum: %.2f\nHypotenuse %.2f\n", s, g);

   return 0;
}