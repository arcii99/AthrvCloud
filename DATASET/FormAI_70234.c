//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>

int main() {
  // Declare variables
  float celsius, fahrenheit, kelvin;

  // Get user input
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert to Fahrenheit
  fahrenheit = (celsius * 1.8) + 32;

  // Convert to Kelvin
  kelvin = celsius + 273.15;

  // Output results
  printf("\nTemperature in Fahrenheit: %.2f", fahrenheit);
  printf("\nTemperature in Kelvin: %.2f", kelvin);

  return 0;
}