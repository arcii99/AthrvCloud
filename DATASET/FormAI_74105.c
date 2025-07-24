//FormAI DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int choice;

  printf("Welcome to a unique Temperature Converter Program! \n");
  printf("Are you trying to convert Celsius to Fahrenheit (Enter 1) or Fahrenheit to Celsius (Enter 2)?\n");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
  }
  else if (choice == 2) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
  }
  else {
    printf("Invalid choice. Please enter 1 or 2.");
  }

  return 0;
}