//FormAI DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>

int celsius_to_fahrenheit(int celsius) {
  return (celsius * 9/5) + 32;
}

int fahrenheit_to_celsius(int fahrenheit) {
  return (fahrenheit - 32) * 5/9;
}

int main() {
  int choice, temp;

  printf("Welcome to the temperature converter!\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%d", &temp);
      printf("%d degrees Celsius is %d degrees Fahrenheit.\n", temp, celsius_to_fahrenheit(temp));
      break;
    case 2:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%d", &temp);
      printf("%d degrees Fahrenheit is %d degrees Celsius.\n", temp, fahrenheit_to_celsius(temp));
      break;
    default:
      printf("Invalid choice. Please try again.\n");
      break;
  }

  return 0;
}