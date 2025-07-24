//FormAI DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>

int main() {
   float celsius, fahrenheit;
   int choice;

   printf("Please choose an option:\n");
   printf("1. Celsius to Fahrenheit conversion\n");
   printf("2. Fahrenheit to Celsius conversion\n");
   scanf("%d", &choice);

   // Celsius to Fahrenheit conversion
   if (choice == 1) {
      printf("Enter temperature in Celsius: ");
      scanf("%f", &celsius);

      fahrenheit = (celsius * 9 / 5) + 32;

      printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", celsius, fahrenheit);
   }

   // Fahrenheit to Celsius conversion
   if (choice == 2) {
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);

      celsius = (fahrenheit - 32) * 5 / 9;

      printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", fahrenheit, celsius);
   }

   return 0;
}