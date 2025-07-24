//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
  double fahrenheit = (celsius * 9 / 5) + 32;
  return fahrenheit;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
  double kelvin = celsius + 273.15;
  return kelvin;
}

int main()
{
  double temperatureInCelsius;
  printf("Enter temperature in Celsius: ");
  scanf("%lf", &temperatureInCelsius);

  double temperatureInFahrenheit = celsiusToFahrenheit(temperatureInCelsius);
  double temperatureInKelvin = celsiusToKelvin(temperatureInCelsius);

  printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit and %.2lf Kelvin.\n", temperatureInCelsius,
         temperatureInFahrenheit, temperatureInKelvin);

  return 0;
}