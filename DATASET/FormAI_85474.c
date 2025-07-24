//FormAI DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include<stdio.h>

int main() {
   int option;
   float temperature;

   printf("1. Convert Celsius to Fahrenheit\n");
   printf("2. Convert Fahrenheit to Celsius\n");
   printf("Which conversion do you want to do? Enter option number: ");
   scanf("%d", &option);

   if(option == 1) {
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      float fahrenheit = (temperature * (9.0 / 5.0)) + 32;
      printf("%0.2f Celsius is equal to %.2f Fahrenheit\n", temperature, fahrenheit);
   } else if(option == 2) {
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      float celsius = (temperature - 32) * (5.0 / 9.0);
      printf("%0.2f Fahrenheit is equal to %.2f Celsius\n", temperature, celsius);
   } else {
      printf("Invalid option number\n");
   }

   return 0;
}