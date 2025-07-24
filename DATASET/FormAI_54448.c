//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Ken Thompson
#include <stdio.h>

int main() {
  float tempCelsius, tempFahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &tempCelsius);

  // Convert Celsius to Fahrenheit
  tempFahrenheit = (tempCelsius * 9/5) + 32;

  printf("%.2f Celsius is equal to %.2f Fahrenheit.", tempCelsius, tempFahrenheit);

  return 0;
}