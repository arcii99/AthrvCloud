//FormAI DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>

int main() {
   float temperature, celsius, fahrenheit;
   int option;

   printf("Enter 1 to convert Fahrenheit to Celsius\n");
   printf("Enter 2 to convert Celsius to Fahrenheit\n");
   printf("Your option: ");
   scanf("%d", &option);

   if (option == 1) {
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      celsius = (temperature - 32) * 5/9;
      printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", temperature, celsius);
   } else if (option == 2) {
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      fahrenheit = (temperature * 9/5) + 32;
      printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", temperature, fahrenheit);
   } else {
      printf("Invalid option!");
   }

   return 0;
}