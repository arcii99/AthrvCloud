//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main() {
  float cel, fahr;
  int choice;

  printf("Welcome to Temperature Converter!\n\n");

  printf("Please choose an option:\n");
  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("\nEnter temperature in Celsius: ");
      scanf("%f", &cel);
      fahr = (cel * 1.8) + 32;
      printf("Temperature in Fahrenheit: %.2f°F", fahr);
      break;

    case 2:
      printf("\nEnter temperature in Fahrenheit: ");
      scanf("%f", &fahr);
      cel = (fahr - 32) / 1.8;
      printf("Temperature in Celsius: %.2f°C", cel);
      break;

    default:
      printf("\nInvalid choice! Please try again.");
  }

  return 0;
}