//FormAI DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  // Take input in Celsius
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert Celsius to Fahrenheit
  fahrenheit = (celsius * 9/5) + 32;

  // Display the temperature in Fahrenheit
  printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);

  return 0;
}