//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Claude Shannon
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
  printf("Welcome to the temperature converter!\n\n");

  float temperatureInCelsius;
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &temperatureInCelsius);

  float temperatureInFahrenheit = celsiusToFahrenheit(temperatureInCelsius);
  printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temperatureInCelsius, temperatureInFahrenheit);

  float temperatureInKelvin = celsiusToKelvin(temperatureInCelsius);
  printf("%.2f degrees Celsius is equal to %.2f Kelvins.\n", temperatureInCelsius, temperatureInKelvin);

  printf("\nThank you for using the temperature converter!\n");

  return 0;
}