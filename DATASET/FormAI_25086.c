//FormAI DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include <stdio.h>

int main() {
  float temp_celsius, temp_fahrenheit;

  // Get temperature in Celsius from user
  printf("Enter temperature in Celsius: ");
  scanf("%f", &temp_celsius);

  // Convert Celsius to Fahrenheit: F = (9/5 * C) + 32
  temp_fahrenheit = (1.8 * temp_celsius) + 32;

  // Print result
  printf("%.2f Celsius = %.2f Fahrenheit", temp_celsius, temp_fahrenheit);

  return 0;
}