//FormAI DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>

int main() {
  float Celsius, Fahrenheit, Kelvin;

  printf("Enter a temperature in Celsius: ");
  scanf("%f", &Celsius);

  Fahrenheit = (Celsius * 9/5) + 32;
  Kelvin = Celsius + 273.15;

  printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit and %.2f Kelvin\n", Celsius, Fahrenheit, Kelvin);

  return 0;
}