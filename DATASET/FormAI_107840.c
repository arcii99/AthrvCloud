//FormAI DATASET v1.0 Category: Temperature Converter ; Style: unmistakable
#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
  float fahrenheit = (9.0/5.0) * celsius + 32.0;
  return fahrenheit;
}

float celsius_to_kelvin(float celsius) {
  float kelvin = celsius + 273.15;
  return kelvin;
}

int main() {
  float celsius;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  float fahrenheit = celsius_to_fahrenheit(celsius);
  float kelvin = celsius_to_kelvin(celsius);

  printf("%.2f C is equivalent to %.2f F\n", celsius, fahrenheit);
  printf("%.2f C is equivalent to %.2f K\n", celsius, kelvin);

  return 0;
}