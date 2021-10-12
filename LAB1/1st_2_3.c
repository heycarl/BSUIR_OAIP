// Составить программу, которая бы по введенному времени
// года выдавала бы название месяцев, относящихся к нему. 

#include <stdio.h>
#include <string.h>


char time[20];

int main() {
   printf("LAB 1.2 task3 by Efimchik Alexandr from GROUP 150702 \n");

   printf("Enter time: ");
   scanf("%s", time);

   if (strcmp(time, "winter") == 0) {
      printf("December, January, February\n");
      return 0;
   } else if (strcmp(time, "summer") == 0) {
      printf("June, July, August\n");
      return 0;
   } else if (strcmp(time, "spring") == 0) {
      printf("March, April, May\n");
      return 0;
   } else if (strcmp(time, "autumn") == 0) {
      printf("September, October, November\n");
      return 0;
   }

   
   
   return 0;
}