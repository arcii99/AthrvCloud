//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

int main() {
  double value;
  char unit;

  printf("Enter a value to convert: ");
  scanf("%lf", &value);

  printf("Enter the unit of measurement (C, F, K): ");
  scanf(" %c", &unit);

  switch (unit) {
    case 'C':
      printf("%.2lf degrees Celsius is equivalent to %.2lf degrees Fahrenheit and %.2lf Kelvin.\n", value, (value * 9 / 5) + 32, value + 273.15);
      break;
    case 'F':
      printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius and %.2lf Kelvin.\n", value, (value - 32) * 5 / 9, (value + 459.67) * 5 / 9);
      break;
    case 'K':
      printf("%.2lf Kelvin is equivalent to %.2lf degrees Celsius and %.2lf degrees Fahrenheit.\n", value, value - 273.15, (value * 9 / 5) - 459.67);
      break;
    default:
      printf("Invalid unit of measurement.\n");
      break;
  }

  return 0;
}