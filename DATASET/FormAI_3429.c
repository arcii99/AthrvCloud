//FormAI DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>

float convert_to_celsius(float fahrenheit); // Function to convert fahrenheit to celsius
float convert_to_fahrenheit(float celsius); // Function to convert celsius to fahrenheit

int main() {
   int choice;
   float temperature, converted_temperature;
   
   printf("Welcome to the temperature conversion program!\n");
   printf("Please select an option:\n");
   printf("1. Convert from Fahrenheit to Celsius\n");
   printf("2. Convert from Celsius to Fahrenheit\n");
   scanf("%d", &choice);
   
   switch (choice) {
      case 1:
         printf("Enter temperature in Fahrenheit:\n");
         scanf("%f", &temperature);
         converted_temperature = convert_to_celsius(temperature);
         printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, converted_temperature);
         break;
      case 2:
         printf("Enter temperature in Celsius:\n");
         scanf("%f", &temperature);
         converted_temperature = convert_to_fahrenheit(temperature);
         printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperature, converted_temperature);
         break;
      default:
         printf("Invalid choice. Please select either 1 or 2.\n");
   }
   
   return 0;
}

float convert_to_celsius(float fahrenheit) {
   float celsius;
   celsius = (fahrenheit - 32) * (5.0/9.0);
   return celsius;
}

float convert_to_fahrenheit(float celsius) {
   float fahrenheit;
   fahrenheit = (celsius * (9.0/5.0)) + 32;
   return fahrenheit;
}