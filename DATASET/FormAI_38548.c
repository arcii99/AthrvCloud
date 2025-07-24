//FormAI DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>

int main() {
  double celsius, fahrenheit;

  printf("Enter a temperature in Celsius: ");
  scanf("%lf", &celsius);

  fahrenheit = (celsius * 9 / 5) + 32;

  printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", celsius, fahrenheit);

  return 0;
}