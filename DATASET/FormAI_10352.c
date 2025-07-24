//FormAI DATASET v1.0 Category: Temperature Converter ; Style: light-weight
#include <stdio.h>

int main() {
   float temp, converted_temp;
   char choice;

   printf("Enter temperature in Celsius (C) or Fahrenheit (F): ");
   scanf("%c", &choice);

   if (choice == 'C' || choice == 'c') {
      printf("\nEnter temperature in Celsius: ");
      scanf("%f", &temp);

      converted_temp = (9 * temp) / 5 + 32;
      printf("\n%.2f C = %.2f F", temp, converted_temp);
   } 
   else if (choice == 'F' || choice == 'f') {
      printf("\nEnter temperature in Fahrenheit: ");
      scanf("%f", &temp);

      converted_temp = (temp - 32) * 5 / 9;
      printf("\n%.2f F = %.2f C", temp, converted_temp);
   } 
   else {
      printf("\nInvalid choice! Enter either C or F.");
   }

   return 0;
}