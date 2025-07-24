//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include<stdio.h>

//Function to convert temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float c) {
   float f = (c * 9 / 5) + 32;
   return f;
}

//Function to convert temperature from Fahrenheit to Celsius
float fahrenheitToCelsius(float f) {
   float c = (f - 32) * 5 / 9;
   return c;
}

int main() {
   float temp, result;
   char choice;

   printf("Enter temperature: ");
   scanf("%f", &temp);

   printf("Enter C for Celsius to Fahrenheit conversion or F for Fahrenheit to Celsius conversion: ");
   scanf(" %c", &choice);

   if (choice == 'C' || choice == 'c') {
      result = celsiusToFahrenheit(temp);
      printf("%.2f C = %.2f F", temp, result);
   } else if (choice == 'F' || choice == 'f') {
      result = fahrenheitToCelsius(temp);
      printf("%.2f F = %.2f C", temp, result);
   } else {
      printf("Invalid choice");
   }

   return 0;
}