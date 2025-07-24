//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

int main() {
   float celsius, fahrenheit;
   int choice;

   printf("Choose an option:\n");
   printf("1. Convert Celsius to Fahrenheit\n");
   printf("2. Convert Fahrenheit to Celsius\n");
   scanf("%d", &choice);

   switch (choice) {
      case 1:
         printf("Enter temperature in Celsius: ");
         scanf("%f", &celsius);
         fahrenheit = (celsius * 9 / 5) + 32;
         printf("%0.2f Celsius = %0.2f Fahrenheit\n", celsius, fahrenheit);
         break;

      case 2:
         printf("Enter temperature in Fahrenheit: ");
         scanf("%f", &fahrenheit);
         celsius = (fahrenheit - 32) * 5 / 9;
         printf("%0.2f Fahrenheit = %0.2f Celsius\n", fahrenheit, celsius);
         break;

      default:
         printf("Invalid option!");
   }

   return 0;
}