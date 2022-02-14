// Билет с шестизначным номером является “счастливым”, если сумма трех первых 
// цифр равна сумме трех его последних цифр. Составьте алгоритм для определения
// по номеру билета “счастливый” он или нет.

#include <stdio.h>
#include <math.h>

int num;
int units [6];

int main() {
   printf("LAB 1.1 task2 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter ticket number: \n");
   scanf("%d", &num);
   units[0] = num / 100000;
   units[1] = num % 100000 / 10000;
   units[2] = num % 10000 / 1000;
   units[3] = num % 1000 / 100;
   units[4] = num % 100 / 10; 
   units[5] = num % 10;

   if ((units[0] + units[1] + units[2]) == (units[3] + units[4] + units[5]))
   {
      printf("Lucky you are!\n");
   } else {
      printf("Looser :)\n");
   }
   return 0;
}