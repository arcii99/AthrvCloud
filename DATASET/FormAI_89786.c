//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  printf("Welcome to Celsius to Fahrenheit Temperature Converter\n");
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = (1.8*celsius) + 32;

  printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

  return 0;
}