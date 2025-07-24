//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include <stdio.h>

int main() {
  float celsius, kelvin, fahrenheit;
  int choice;

  printf("Welcome to the Surrealist Temperature Converter!\n");
  printf("Please select your starting temperature scale:\n");
  printf("1. Celsius\n2. Kelvin\n3. Fahrenheit\n");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &celsius);
      kelvin = celsius + 273.15;
      fahrenheit = (celsius * 9 / 5) + 32;
      printf("\nYour surreal temperature is...\n");
      printf("%.2f Kelvin\n%.2f Fahrenheit\n", kelvin, fahrenheit);
      break;
    case 2:
      printf("Enter temperature in Kelvin: ");
      scanf("%f", &kelvin);
      celsius = kelvin - 273.15;
      fahrenheit = ((kelvin - 273.15) * 9 / 5) + 32;
      printf("\nYour surreal temperature is...\n");
      printf("%.2f Celsius\n%.2f Fahrenheit\n", celsius, fahrenheit);
      break;
    case 3:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      celsius = (fahrenheit - 32) * 5 / 9;
      kelvin = ((fahrenheit - 32) * 5 / 9) + 273.15;
      printf("\nYour surreal temperature is...\n");
      printf("%.2f Celsius\n%.2f Kelvin\n", celsius, kelvin);
      break;
    default:
      printf("Invalid Choice. Please Try Again.\n");
  }

  return 0;
}