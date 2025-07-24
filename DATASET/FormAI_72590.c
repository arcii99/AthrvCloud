//FormAI DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include <stdio.h>

int main() {
  float fahrenheit, celsius, kelvin;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert Celsius to Fahrenheit
  fahrenheit = (celsius * 1.8) + 32;
  
  // Convert Celsius to Kelvin
  kelvin = celsius + 273.15;

  printf("\n%.2f degree Celsius is equal to:\n", celsius);
  printf("%.2f degree Fahrenheit\n", fahrenheit);
  printf("%.2f Kelvin\n", kelvin);

  return 0;
}