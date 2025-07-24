//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cyberpunk
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

int main() {
  int choice;
  float temperature;

  printf("Welcome to the Cyberpunk Temperature Converter\n");
  printf("Please select an option to begin:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &temperature);
      printf("%.2fC is equivalent to %.2fF\n", temperature, celsiusToFahrenheit(temperature));
      break;
    case 2:
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      printf("%.2fF is equivalent to %.2fC\n", temperature, fahrenheitToCelsius(temperature));
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

  return 0;
}