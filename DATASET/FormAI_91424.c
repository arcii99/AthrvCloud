//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include <stdio.h>

int kelvin_to_celsius(int kelvin) {
  return kelvin - 273;
}

int fahrenheit_to_celsius(int fahrenheit) {
  return (fahrenheit - 32) * 5 / 9;
}

int main() {
  int temperature, choice, celsius;
  printf("Please enter a temperature: ");
  scanf("%d", &temperature);

  printf("Choose a conversion:\n");
  printf("1. Kelvin to Celsius\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("Choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      celsius = kelvin_to_celsius(temperature);
      printf("%d K is %d C\n", temperature, celsius);
      break;
    case 2:
      celsius = fahrenheit_to_celsius(temperature);
      printf("%d F is %d C\n", temperature, celsius);
      break;
    default:
      printf("Invalid choice!\n");
  }

  return 0;
}