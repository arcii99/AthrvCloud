//FormAI DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float celsius_to_kelvin(float celsius);

int main() {
  float celsius, fahrenheit, kelvin;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = celsius_to_fahrenheit(celsius);
  kelvin = celsius_to_kelvin(celsius);

  printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
  printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);

  return 0;
}

float celsius_to_fahrenheit(float celsius) {
  return (celsius * 9.0 / 5.0) + 32.0;
}

float celsius_to_kelvin(float celsius) {
  return celsius + 273.15;
}