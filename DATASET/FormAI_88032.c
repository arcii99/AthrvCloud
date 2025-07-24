//FormAI DATASET v1.0 Category: Temperature Converter ; Style: interoperable
#include <stdio.h>

float convertToFahrenheit(float celsius) {
   return (celsius * 1.8) + 32;
}

float convertToKelvin(float celsius) {
   return celsius + 273.15;
}

int main() {
   float celsius, fahrenheit, kelvin;
   int choice;

   printf("Enter temperature in Celsius: ");
   scanf("%f", &celsius);

   printf("Choose conversion:\n");
   printf("1. Celsius to Fahrenheit\n2. Celsius to Kelvin\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   switch(choice) {
      case 1:
         fahrenheit = convertToFahrenheit(celsius);
         printf("%.2f°C = %.2f°F", celsius, fahrenheit);
         break;
      case 2:
         kelvin = convertToKelvin(celsius);
         printf("%.2f°C = %.2f°K", celsius, kelvin);
         break;
      default:
         printf("Invalid choice");
   }
   return 0;
}