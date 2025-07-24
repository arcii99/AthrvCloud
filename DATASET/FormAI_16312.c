//FormAI DATASET v1.0 Category: Temperature Converter ; Style: careful
#include <stdio.h>

int main() {
   float celsius, fahrenheit;
   int choice;
   
   printf("\nTemperature Converter\n\n");
   printf("1. Convert from Celsius to Fahrenheit\n");
   printf("2. Convert from Fahrenheit to Celsius\n");
   printf("Enter your choice (1 or 2): ");
   scanf("%d", &choice);
   
   switch (choice) {
      case 1:
         printf("\nEnter temperature in Celsius: ");
         scanf("%f", &celsius);
         fahrenheit = (celsius * 9/5) + 32;
         printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
         break;
         
      case 2:
         printf("\nEnter temperature in Fahrenheit: ");
         scanf("%f", &fahrenheit);
         celsius = (fahrenheit - 32) * 5/9;
         printf("%.2f Fahrenheit = %.2f Celsius\n", fahrenheit, celsius);
         break;
         
      default:
         printf("\nInvalid Choice!\n");
         break;
   }
   
   return 0;
}