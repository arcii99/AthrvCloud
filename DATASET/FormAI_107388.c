//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>

int main() {
  float temp_celsius = 0.0, temp_fahrenheit = 0.0;
  printf("Please enter the temperature in Celsius: ");
  scanf("%f", &temp_celsius);

  temp_fahrenheit = (temp_celsius * 1.8) + 32;

  printf("\nThe temperature in Fahrenheit is: %.2f F", temp_fahrenheit);

  return 0;
}