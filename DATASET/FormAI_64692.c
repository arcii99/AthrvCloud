//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>

// function prototypes
float fahrenheitToCelsius(float);
float celsiusToFahrenheit(float);

int main() {
  float temperature;
  int choice;
  printf("Welcome to the Unit Converter!\n");
  printf("Which conversion would you like to perform?\n");
  printf("1. Fahrenheit to Celsius\n2. Celsius to Fahrenheit\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);
  switch(choice) {
    case 1:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      printf("%.2f Fahrenheit = %.2f Celsius", temperature, fahrenheitToCelsius(temperature));
      break;
    case 2:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      printf("%.2f Celsius = %.2f Fahrenheit", temperature, celsiusToFahrenheit(temperature));
      break;
    default:
      printf("Invalid choice! Please choose either 1 or 2.");
  }
  return 0;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  return (celsius * 9 / 5) + 32;
}