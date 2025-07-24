//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
   return (celsius * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
   return (fahrenheit - 32) * 5/9;
}

// function to convert kilometers to miles
float kilometersToMiles(float kilometers) {
   return kilometers / 1.609;
}

// function to convert miles to kilometers
float milesToKilometers(float miles) {
   return miles * 1.609;
}

int main() {
   int choice;
   float value, result;

   printf("Select an option to convert:\n");
   printf("1. Celsius to Fahrenheit\n");
   printf("2. Fahrenheit to Celsius\n");
   printf("3. Kilometers to Miles\n");
   printf("4. Miles to Kilometers\n");
   scanf("%d", &choice);

   switch(choice) {
      case 1: // Celsius to Fahrenheit
         printf("Enter temperature in Celsius: ");
         scanf("%f", &value);
         result = celsiusToFahrenheit(value);
         printf("%.2f Celsius is equal to %.2f Fahrenheit", value, result);
         break;
      case 2: // Fahrenheit to Celsius
         printf("Enter temperature in Fahrenheit: ");
         scanf("%f", &value);
         result = fahrenheitToCelsius(value);
         printf("%.2f Fahrenheit is equal to %.2f Celsius", value, result);
         break;
      case 3: // Kilometers to Miles
         printf("Enter distance in kilometers: ");
         scanf("%f", &value);
         result = kilometersToMiles(value);
         printf("%.2f kilometers is equal to %.2f miles", value, result);
         break;
      case 4: // Miles to Kilometers
         printf("Enter distance in miles: ");
         scanf("%f", &value);
         result = milesToKilometers(value);
         printf("%.2f miles is equal to %.2f kilometers", value, result);
         break;
      default:
          printf("Invalid choice");
   }

   return 0;
}