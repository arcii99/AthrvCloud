//FormAI DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>

int main() {
  float fahrenheit, celsius;
  int choice;

  printf("Temperature Converter\n");
  printf("---------------------\n");

  while (1) {
    printf("Select conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 9/5) + 32;
        printf("%.2f Celsius = %.2f Fahrenheit\n\n", celsius, fahrenheit);
        break;

      case 2:
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) * 5/9;
        printf("%.2f Fahrenheit = %.2f Celsius\n\n", fahrenheit, celsius);
        break;

      case 3:
        printf("Exiting program...\n");
        return 0;

      default:
        printf("Invalid choice. Please try again.\n\n");
        break;
    }
  }

  return 0;
}