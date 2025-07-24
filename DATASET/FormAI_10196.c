//FormAI DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>

int main() {

   float celsius, fahrenheit;

   printf("---------------------\n");
   printf("Temperature Converter\n");
   printf("---------------------\n\n");

   printf("Enter temperature in Celsius: ");
   scanf("%f", &celsius);

   // Convert Celsius to Fahrenheit
   fahrenheit = (celsius * 1.8) + 32;

   printf("\n%f degrees Celsius is equal to %f degrees Fahrenheit\n\n", celsius, fahrenheit);

   printf("Thanks for using our program. Have a great day!\n");

   return 0;
}