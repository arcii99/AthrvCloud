//FormAI DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;     /* lower limit of temperature scale */
  upper = 300;   /* upper limit */
  step = 20;     /* step size */

  printf("Celsius to Fahrenheit Converter\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius * 9.0 / 5.0) + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  printf("\nFahrenheit to Celsius Converter\n");

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}