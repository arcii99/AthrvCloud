//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = (celsius * 1.8) + 32;

  printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
  return 0;
}

/*
Sample Output:

Enter temperature in Celsius: 25
25.00 Celsius = 77.00 Fahrenheit
*/