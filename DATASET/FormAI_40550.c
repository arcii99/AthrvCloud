//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>

int main() {
  printf("Welcome to the Temperature Converter!\n\n");

  // Input temperature in Celsius
  float celsius;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert Celsius to Fahrenheit and display the result
  float fahrenheit = (celsius * 9 / 5) + 32;
  printf("Temperature in Fahrenheit: %0.2f°F\n", fahrenheit);

  // Convert Celsius to Kelvin and display the result
  float kelvin = celsius + 273.15;
  printf("Temperature in Kelvin: %0.2fK\n", kelvin);

  // Bonus feature: convert Celsius to Rankine
  float rankine = (celsius + 273.15) * 9 / 5;
  printf("Temperature in Rankine: %0.2f°R\n\n", rankine);

  // Input temperature in Fahrenheit
  float fahrenheit2;
  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit2);

  // Convert Fahrenheit to Celsius and display the result
  float celsius2 = (fahrenheit2 - 32) * 5 / 9;
  printf("Temperature in Celsius: %0.2f°C\n", celsius2);

  // Convert Fahrenheit to Kelvin and display the result
  float kelvin2 = (fahrenheit2 + 459.67) * 5 / 9;
  printf("Temperature in Kelvin: %0.2fK\n", kelvin2);

  // Bonus feature: convert Fahrenheit to Rankine
  float rankine2 = fahrenheit2 + 459.67;
  printf("Temperature in Rankine: %0.2f°R\n\n", rankine2);

  return 0;
}