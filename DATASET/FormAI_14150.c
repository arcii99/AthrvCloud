//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  // Getting input from user
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert to Fahrenheit
  fahrenheit = (celsius * 9 / 5) + 32;

  // Print results
  printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

  return 0;
}