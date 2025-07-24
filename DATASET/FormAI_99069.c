//FormAI DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>

int main() {
  double celsius, fahrenheit, kelvin;
  int option;

  printf("Welcome to Temperature Converter\n");
  printf("1. Celsius to Fahrenheit and Kelvin\n");
  printf("2. Fahrenheit to Celsius and Kelvin\n");
  printf("3. Kelvin to Celsius and Fahrenheit\n");
  printf("Enter your option: ");
  scanf("%d", &option);

  switch (option) {
    case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%lf", &celsius);
      fahrenheit = (celsius * 9 / 5) + 32;
      kelvin = celsius + 273.15;
      printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, fahrenheit);
      printf("%.2lf Celsius = %.2lf Kelvin\n", celsius, kelvin);
      break;

    case 2:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%lf", &fahrenheit);
      celsius = (fahrenheit - 32) * 5 / 9;
      kelvin = (fahrenheit + 459.67) * 5 / 9;
      printf("%.2lf Fahrenheit = %.2lf Celsius\n", fahrenheit, celsius);
      printf("%.2lf Fahrenheit = %.2lf Kelvin\n", fahrenheit, kelvin);
      break;

    case 3:
      printf("Enter temperature in Kelvin: ");
      scanf("%lf", &kelvin);
      celsius = kelvin - 273.15;
      fahrenheit = (kelvin * 9 / 5) - 459.67;
      printf("%.2lf Kelvin = %.2lf Celsius\n", kelvin, celsius);
      printf("%.2lf Kelvin = %.2lf Fahrenheit\n", kelvin, fahrenheit);
      break;

    default:
      printf("Invalid option!\n");
      break;
  }

  return 0;
}