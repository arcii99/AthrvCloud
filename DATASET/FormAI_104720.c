//FormAI DATASET v1.0 Category: Temperature Converter ; Style: curious
#include <stdio.h>

int main() {
  double fahr, celsius;
  int lower, upper, step;

  lower = 0;    // Lower limit of temperature table
  upper = 300;  // Upper limit of temperature table
  step = 20;    // Step size

  printf("Celsius\tFahrenheit\n");

  celsius = lower;
  while (celsius <= upper) {
    fahr = (celsius * 9.0 / 5.0) + 32.0;
    printf("%7.1f\t%10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}