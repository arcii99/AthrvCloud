//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>

int main()
{
   float celsius, fahrenheit;

   printf("Enter temperature in Celsius: ");
   scanf("%f", &celsius);

   // Convert Celsius to Fahrenheit
   fahrenheit = (celsius * 9/5) + 32;

   printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);

   return 0;
}