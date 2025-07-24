//FormAI DATASET v1.0 Category: Temperature Converter ; Style: energetic
// Welcome to the C Temperature Converter program!
// This program converts a given temperature in Celsius to Fahrenheit and Kelvin
// Let's get started!

#include <stdio.h>

int main() {
  float celsius, fahrenheit, kelvin;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Formula for converting Celsius to Fahrenheit
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  // Formula for converting Celsius to Kelvin
  kelvin = celsius + 273.15;

  // Displaying the converted temperatures
  printf("\n%.2f\u00B0C is equal to:\n%.2f\u00B0F\n%.2fK", celsius, fahrenheit, kelvin);

  // Energize the program with a message to encourage users to run it again
  printf("\n\nThat was fun! Let's try another temperature! Hit that Run button again! :)");
  return 0;
}