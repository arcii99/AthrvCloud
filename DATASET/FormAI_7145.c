//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

/* Convert Celsius to Fahrenheit */
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}

/* Convert Celsius to Kelvin */
float celsiusToKelvin(float celsius) {
  return celsius + 273.15;
}

int main() {
  float celsius, fahrenheit, kelvin;

  printf("Enter a temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = celsiusToFahrenheit(celsius);
  kelvin = celsiusToKelvin(celsius);

  printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
  printf("%.2f Celsius is %.2f Kelvin\n", celsius, kelvin);
 
  return 0;
}