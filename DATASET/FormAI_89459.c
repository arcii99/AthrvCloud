//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>

// function prototypes
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);
void displayTemperature(float celsius, float fahrenheit, float kelvin);

int main() {
  float celsius, fahrenheit, kelvin;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // convert celsius to fahrenheit and kelvin using functions
  fahrenheit = celsiusToFahrenheit(celsius);
  kelvin = celsiusToKelvin(celsius);

  // display the temperatures
  displayTemperature(celsius, fahrenheit, kelvin);

  return 0;
}

// function to convert celsius to fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9/5 + 32);
}

// function to convert celsius to kelvin
float celsiusToKelvin(float celsius) {
  return (celsius + 273.15);
}

// function to display all temperatures
void displayTemperature(float celsius, float fahrenheit, float kelvin) {
  printf("\n%.2f degrees Celsius = %.2f degrees Fahrenheit\n", celsius, fahrenheit);
  printf("%.2f degrees Celsius = %.2f Kelvin\n", celsius, kelvin);
}