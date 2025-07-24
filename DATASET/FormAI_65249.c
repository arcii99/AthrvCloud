//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

int main() {
  float celsius, fahrenheit, kelvin;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Conversion to Fahrenheit
  fahrenheit = (celsius * 9/5) + 32;
  printf("\nTemperature in Fahrenheit: %f", fahrenheit);

  // Conversion to Kelvin
  kelvin = celsius + 273.15;
  printf("\nTemperature in Kelvin: %f", kelvin);

  return 0;
}