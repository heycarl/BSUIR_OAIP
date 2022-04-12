#include <stdio.h>
#include "Struct.h"

void viewData(struct figure* f, int num)
{
    printf(" ==================================== \n");
    for (int i = 0; i < num; i++)
    {
        if (f[i].params.flag != 0)
        {
            printf("| Name: %6s | Color: %6s       |\n", f[i].Name, f[i].params.Color);
        } else {
            printf("| Name: %6s | Perimeter: %5.5f |\n", f[i].Name, f[i].params.Perimeter);
        }
    }
    printf(" ==================================== \n");
}