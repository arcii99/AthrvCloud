//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
  char choice;
  float temp, result;

  printf("Welcome to the temperature converter app!\n");

  do {
    printf("\nChoose conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    scanf(" %c", &choice);

    switch (choice) {
      case '1':
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);

        result = (temp * 9/5) + 32;

        printf("%.2fC = %.2fF\n", temp, result);

        break;

      case '2':
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &temp);

        result = (temp - 32) * 5/9;

        printf("%.2fF = %.2fC\n", temp, result);

        break;

      case '3':
        printf("\nExiting...\n");
        exit(0);

      default:
        printf("\nInvalid choice, please try again.\n");
    }
  } while (1);

  return 0;
}