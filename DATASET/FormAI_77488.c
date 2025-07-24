//FormAI DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>

int main() {
   float celsius, fahrenheit;

   printf("Please enter the temperature in Celsius: ");
   scanf("%f", &celsius);

   // convert celsius to fahrenheit
   fahrenheit = (celsius * 1.8) + 32;

   printf("\n%0.2f degrees Celsius is equal to %0.2f degrees Fahrenheit.\n", celsius, fahrenheit);

   return 0;
}