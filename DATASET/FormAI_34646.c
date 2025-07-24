//FormAI DATASET v1.0 Category: Temperature Converter ; Style: romantic
#include <stdio.h>

int main() {
  float temp_celsius, temp_fahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &temp_celsius);

  temp_fahrenheit = (temp_celsius * 9 / 5) + 32;

  printf("%.2f Celsius is equal to %.2f Fahrenheit.", temp_celsius, temp_fahrenheit);

  return 0;
}