//FormAI DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>

int main() {
  int choice = 0;
  
  printf("Welcome to the Temperature Converter!\n");
  
  while (choice != 3) {
    printf("What would you like to do?\n");
    printf("1. Convert from Celsius to Fahrenheit\n");
    printf("2. Convert from Fahrenheit to Celsius\n");
    printf("3. Quit\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
      float celsius;
      printf("Enter the temperature in Celsius: ");
      scanf("%f", &celsius);
      float fahrenheit = (celsius * 1.8) + 32;
      printf("%.2f degrees Celsius equals %.2f degrees Fahrenheit\n", celsius, fahrenheit);
    }
    else if (choice == 2) {
      float fahrenheit;
      printf("Enter the temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);
      float celsius = (fahrenheit - 32) / 1.8;
      printf("%.2f degrees Fahrenheit equals %.2f degrees Celsius\n", fahrenheit, celsius);
    }
    else if (choice == 3) {
      printf("Goodbye!\n");
    }
    else {
      printf("Invalid choice. Please try again.\n");
    }
  }
  
  return 0;
}