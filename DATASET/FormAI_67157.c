//FormAI DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  // Get temperature in Celsius
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert temperature to Fahrenheit
  fahrenheit = (celsius * 1.8) + 32;

  // Output result
  printf("%0.2f degree Celsius is equal to %0.2f degree Fahrenheit.\n", celsius, fahrenheit);

  return 0;
}