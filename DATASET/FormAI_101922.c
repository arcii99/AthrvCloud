//FormAI DATASET v1.0 Category: Unit converter ; Style: decentralized
#include <stdio.h>

float cel_to_fahr(float cel) {
  float fahr = 9.0/5.0 * cel + 32.0;
  return fahr;
}

float fahr_to_cel(float fahr) {
  float cel = 5.0/9.0 * (fahr - 32.0);
  return cel;
}

int main() {
  float temp;
  char choice;

  printf("Welcome to the Decentralized Unit Converter\n");

  while (1) {
    printf("\nPlease choose an option:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Exit\n");
    scanf(" %c", &choice);

    if (choice == '1') {
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &temp);
      printf("%.2f°C = %.2f°F\n", temp, cel_to_fahr(temp));
    }
    else if (choice == '2') {
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &temp);
      printf("%.2f°F = %.2f°C\n", temp, fahr_to_cel(temp));
    }
    else if (choice == '3') {
      printf("Goodbye!\n");
      break;
    }
    else {
      printf("Invalid option, please try again.\n");
    }
  }

  return 0;
}