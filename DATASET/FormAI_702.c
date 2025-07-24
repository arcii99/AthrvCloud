//FormAI DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main() {
  float celsius;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  if (celsius < -273.15) {
    printf("Temperature cannot be less than absolute zero (-273.15°C)\n");
    return 0;
  }

  float fahrenheit = celsiusToFahrenheit(celsius);
  printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);

  float kelvin = celsiusToKelvin(celsius);
  printf("%.2f°C = %.2f K\n", celsius, kelvin);

  return 0;
}

float celsiusToFahrenheit(float celsius) {
  return (celsius * 9/5) + 32;
}

float celsiusToKelvin(float celsius) {
  return celsius + 273.15;
}