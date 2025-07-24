//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int choice;
  
  printf("Welcome to the Happy Temperature Converter!\n\n");

  do {
    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nYou chose Celsius to Fahrenheit.\n");
        printf("Enter temperature in Celsius: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9 / 5) + 32;
        printf("The temperature in Fahrenheit is %.2f\n\n", fahrenheit);
        break;
      
      case 2:
        printf("\nYou chose Fahrenheit to Celsius.\n");
        printf("Enter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5 / 9;
        printf("The temperature in Celsius is %.2f\n\n", celsius);
        break;

      case 3:
        printf("\nThank you for using the Happy Temperature Converter! Goodbye!\n");
        break;
      
      default:
        printf("\nInvalid choice. Please enter a number between 1 and 3.\n\n");
        break;
    }
  } while(choice != 3);

  return 0;
}