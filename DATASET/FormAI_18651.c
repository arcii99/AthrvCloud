//FormAI DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  float fahrenheit = (celsius * 9 / 5) + 32;
  return fahrenheit;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
  float kelvin = celsius + 273.15;
  return kelvin;
}

int main() {
  float celsius;
  
  // Take input from user
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);
  
  // Call the conversion functions and print the results
  printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
  printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, celsiusToKelvin(celsius));
  
  return 0;
}