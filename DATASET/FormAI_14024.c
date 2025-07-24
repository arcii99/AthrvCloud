//FormAI DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
  float fahrenheit = (celsius * 9/5) + 32;
  return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
  float celsius = (fahrenheit - 32) * 5/9;
  return celsius;
}

int main() {
  int choice;
  float temperature;
  
  printf("Welcome to the Cyberpunk Unit Converter\n");
  printf("------------------------\n");
  printf("Please choose an option:\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("------------------------\n");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      printf("%.2f Celsius is equal to %.2f Fahrenheit", temperature, celsiusToFahrenheit(temperature));
      break;
      
    case 2:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      printf("%.2f Fahrenheit is equal to %.2f Celsius", temperature, fahrenheitToCelsius(temperature));
      break;
      
    default:
      printf("Invalid option selected");
  }
  
  return 0;
}