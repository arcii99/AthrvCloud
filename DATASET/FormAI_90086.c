//FormAI DATASET v1.0 Category: Scientific ; Style: minimalist
#include <stdio.h>

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float f) {
  return (f - 32) * 5 / 9;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float c) {
  return (c * 9 / 5) + 32;
}

int main() {

  float fahrenheit, celsius;

  // Get Fahrenheit temperature from user
  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);

  // Convert Fahrenheit to Celsius
  celsius = fahrenheitToCelsius(fahrenheit);

  // Display Celsius temperature
  printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);

  // Get Celsius temperature from user
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert Celsius to Fahrenheit
  fahrenheit = celsiusToFahrenheit(celsius);

  // Display Fahrenheit temperature
  printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

  return 0;
}