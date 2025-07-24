//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

/* This program converts Celsius to Fahrenheit using user input */

int main(void) {
  float celsius, fahrenheit;

  // Ask user for input
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  /* Conversion formula: F = (C x 9/5 ) + 32 */
  fahrenheit = (celsius * 9/5) + 32;

  // Output conversion result
  printf("%.1f degrees Celsius is equal to %.1f degrees Fahrenheit.\n", celsius, fahrenheit);

  return 0;
}