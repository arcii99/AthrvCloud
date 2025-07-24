//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9/5) + 32;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5/9;
}

// function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
  return celsius + 273.15;
}

// function to convert Kelvin to Celsius
float kelvinToCelsius(float kelvin) {
  return kelvin - 273.15;
}

// function to convert Fahrenheit to Kelvin
float fahrenheitToKelvin(float fahrenheit) {
  return (fahrenheit + 459.67) * 5/9;
}

// function to convert Kelvin to Fahrenheit
float kelvinToFahrenheit(float kelvin) {
  return kelvin * 9/5 - 459.67;
}

int main() {
  int choice;
  float temperature;

  printf("Please select an option:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("3. Celsius to Kelvin\n");
  printf("4. Kelvin to Celsius\n");
  printf("5. Fahrenheit to Kelvin\n");
  printf("6. Kelvin to Fahrenheit\n");
  scanf("%d", &choice);

  printf("Enter a temperature value: ");
  scanf("%f", &temperature);

  switch(choice) {
    case 1: printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;
    case 2: printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;
    case 3: printf("%.2f Celsius = %.2f Kelvin\n", temperature, celsiusToKelvin(temperature));
            break;
    case 4: printf("%.2f Kelvin = %.2f Celsius\n", temperature, kelvinToCelsius(temperature));
            break;
    case 5: printf("%.2f Fahrenheit = %.2f Kelvin\n", temperature, fahrenheitToKelvin(temperature));
            break;
    case 6: printf("%.2f Kelvin = %.2f Fahrenheit\n", temperature, kelvinToFahrenheit(temperature));
            break;
    default: printf("Invalid choice");
  }

  return 0;
}