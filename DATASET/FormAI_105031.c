//FormAI DATASET v1.0 Category: Temperature Converter ; Style: genious
#include <stdio.h>

int main() {
  float celsius = 0, fahrenheit = 0;

  printf("Welcome to the Celsius to Fahrenheit Converter\n\n");

  // Ask user for input
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  // Calculate the temperature in Fahrenheit
  fahrenheit = (celsius * 9 / 5) + 32;

  // Check if the temperature is freezing or boiling
  if (fahrenheit <= 32) {
    printf("\nThe temperature is freezing!\n");
  } else if (fahrenheit >= 212) {
    printf("\nThe temperature is boiling!\n");
  }

  // Display the temperature in Fahrenheit
  printf("\n%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);

  return 0;
}