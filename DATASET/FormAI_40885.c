//FormAI DATASET v1.0 Category: Temperature Converter ; Style: artistic
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  printf("Enter temperature in Celsius: ");
  scanf("%f", &celsius);

  fahrenheit = (celsius * 9 / 5) + 32;

  printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);

  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);

  celsius = (fahrenheit - 32) * 5 / 9;

  printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", fahrenheit, celsius);

  return 0;
}

/*
  This is a simple C Temperature Converter program that allows the user to input a temperature in Celsius or Fahrenheit and convert it to the other unit of measurement.

  We first prompt the user to enter a temperature in Celsius, then use a mathematical formula to convert it to Fahrenheit. We then display the result to the user.

  Next, we prompt the user to enter a temperature in Fahrenheit, then use another formula to convert it to Celsius. We then display the result to the user.

  The use of printf and scanf allows us to interact with the user and receive input from them.

  This program is both functional and easy to understand. It could be expanded upon to include additional features, such as converting between Kelvin and Celsius or Fahrenheit and Kelvin.

  Overall, this C Temperature Converter program is a useful tool for anyone needing to quickly convert temperatures between units of measurement.
*/