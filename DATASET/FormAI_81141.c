//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);
  fahrenheit = (celsius * 9 / 5) + 32;
  printf("%.1f Celsius = %.1f Fahrenheit", celsius, fahrenheit);
  return 0;
}