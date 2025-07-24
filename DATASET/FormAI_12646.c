//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

// function to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
     return (celsius * 1.8) + 32; // formula to convert
}

// function to convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
     return (fahrenheit - 32) / 1.8; // formula to convert
}

int main() {
     float temperature = 0;
     int choice = 0;
     
     printf("\nWelcome to the Temperature Converter!\n\n");
     printf("Please select an option:\n");
     printf("1. Convert Celsius to Fahrenheit\n");
     printf("2. Convert Fahrenheit to Celsius\n");

     // get user input
     scanf("%d", &choice);
     
     switch(choice) {
          case 1: // celsius to fahrenheit conversion
               printf("\nEnter temperature in degrees Celsius: ");
               scanf("%f", &temperature);

               printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit!", temperature, celsius_to_fahrenheit(temperature));
               break;

          case 2: // fahrenheit to celsius conversion
               printf("\nEnter temperature in degrees Fahrenheit: ");
               scanf("%f", &temperature);

               printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius!", temperature, fahrenheit_to_celsius(temperature));
               break;

          default: // invalid input
               printf("\nInvalid input! Please select either Option 1 or Option 2.");
     }
     
     printf("\nThank you for using the Temperature Converter. Have a nice day!\n\n");
     
     return 0;
}