//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;     /* lower limit of temperature table */
  upper = 300;   /* upper limit */
  step = 20;     /* step size */

  printf("Surprise, surprise! Welcome to the temperature converter!\n");
  printf("This program converts Fahrenheit to Celsius.\n");
  
  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}