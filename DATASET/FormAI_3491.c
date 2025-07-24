//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

int main() {
  float temperature, celsius, fahrenheit;

  printf("-----------------------------\n");
  printf("|  Temperature Converter   |\n");
  printf("-----------------------------\n\n");

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Conversion formula
  fahrenheit = (celsius * 9/5) + 32;
  printf("%.2f Celsius is equal to %.2f Fahrenheit.\n\n", celsius, fahrenheit);

  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);

  // Conversion formula
  celsius = (fahrenheit - 32) * 5/9;
  printf("%.2f Fahrenheit is equal to %.2f Celsius.\n\n", fahrenheit, celsius);

  printf("Thanks for using our Temperature Converter.\n");

  return 0;
}