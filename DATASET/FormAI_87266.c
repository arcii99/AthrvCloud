//FormAI DATASET v1.0 Category: Temperature Converter ; Style: creative
#include <stdio.h>

int main() {
  float temperature_celsius;
  float temperature_fahrenheit;

  printf("Welcome to the temperature converter!\n");

  // Get temperature in Celsius from user
  printf("Enter temperature in Celsius: ");
  scanf("%f", &temperature_celsius);

  // Convert Celsius to Fahrenheit
  temperature_fahrenheit = ((temperature_celsius * 9) / 5) + 32;

  // Print the converted temperature in Fahrenheit
  printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", temperature_celsius, temperature_fahrenheit);

  return 0;
}