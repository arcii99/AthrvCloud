//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert to Fahrenheit
  fahrenheit = (celsius * 1.8) + 32;
  printf("%.2f\u00B0C is equal to %.2f\u00B0F\n", celsius, fahrenheit);

  // Convert back to Celsius
  celsius = (fahrenheit - 32) / 1.8;
  printf("%.2f\u00B0F is equal to %.2f\u00B0C\n", fahrenheit, celsius);

  return 0;
}