//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

int main() {
  float fahrenheit, celsius;
  int choice;

  printf("Temperature Converter\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("Enter your choice (1/2): ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter Temperature in Celsius: ");
      scanf("%f", &celsius);
      fahrenheit = (celsius * 9/5) + 32;
      printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
      break;

    case 2:
      printf("Enter Temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      celsius = (fahrenheit - 32) * 5/9;
      printf("%.2f Fahrenheit = %.2f Celsius", fahrenheit, celsius);
      break;

    default:
      printf("Invalid Choice! Please Enter 1 or 2.");
  }

  return 0;
}