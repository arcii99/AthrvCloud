//FormAI DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  float fahrenheit = (celsius * 9/5) + 32;
  return fahrenheit;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
  float kelvin = celsius + 273.15;
  return kelvin;
}

int main() {
  printf("Hi there! I am a Temperature Conversion program written in C.\n");
  printf("Enter a temperature in Celsius: ");

  float celsius;
  scanf("%f", &celsius);

  // Convert Celsius to Fahrenheit
  float fahrenheit = celsiusToFahrenheit(celsius);
  printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

  // Convert Celsius to Kelvin
  float kelvin = celsiusToKelvin(celsius);
  printf("%.2f degrees Celsius is equal to %.2f Kelvin.\n", celsius, kelvin);

  printf("Thank you for using me! I hope you found this program helpful.\n");
  return 0;
}