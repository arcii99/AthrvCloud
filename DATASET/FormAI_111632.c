//FormAI DATASET v1.0 Category: Temperature Converter ; Style: imaginative
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  char choice;

  printf("Welcome to the Temperature Converter!\n\n");

  while (1) {
    printf("Press 'C' to convert from Fahrenheit to Celsius.\n");
    printf("Press 'F' to convert from Celsius to Fahrenheit.\n");
    printf("Press 'Q' to quit.\n");

    printf("What's your choice? ");
    scanf(" %c", &choice);

    if (choice == 'C' || choice == 'c') {  // Fahrenheit to Celsius
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);

      celsius = (fahrenheit - 32) * 5 / 9;
      printf("%.2fF = %.2fC\n\n", fahrenheit, celsius);
    } else if (choice == 'F' || choice == 'f') {  // Celsius to Fahrenheit
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);

      fahrenheit = (celsius * 9 / 5) + 32;
      printf("%.2fC = %.2fF\n\n", celsius, fahrenheit);
    } else if (choice == 'Q' || choice == 'q') {  // Quit
      printf("Goodbye!\n");
      break;
    } else {  // Invalid choice
      printf("Invalid choice, try again.\n\n");
    }
  }

  return 0;
}