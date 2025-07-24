//FormAI DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main() {
  float celsius, fahrenheit;

  printf("Welcome to the Paranoid Temperature Converter!\n");
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  // Check if temperature is below absolute zero
  if (celsius < -273.15) {
    printf("Warning: Temperature is below absolute zero! The universe might collapse!\n");
    printf("Please enter a valid temperature above -273.15 Celsius.\n");
    return 0;
  }

  fahrenheit = (celsius * (9.0 / 5.0)) + 32.0;

  // Check if temperature is above boiling point of water
  if (fahrenheit > 212.0) {
    printf("Warning: Temperature is above the boiling point of water!\n");
    printf("Please be careful with your temperature measurements.\n");
  }

  printf("%0.2f Celsius is equivalent to %0.2f Fahrenheit.\n", celsius, fahrenheit);
  return 0;
}