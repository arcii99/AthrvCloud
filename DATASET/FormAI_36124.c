//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>

// Welcome to the Temperature Converter!
// This program will convert Celsius to Fahrenheit and vice versa using the exciting formulae!
// Are you ready to get started? 

int main() {
  float celsius, fahrenheit;
  int option;

  printf("Enter 1 to convert Celsius to Fahrenheit\nEnter 2 to convert Fahrenheit to Celsius\n");
  scanf("%d", &option);

  if (option == 1) {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.1f Celsius is equal to %.1f Fahrenheit. Woooohoooo!!!\n", celsius, fahrenheit);

  } else if (option == 2) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.1f Fahrenheit is equal to %.1f Celsius. Yayyyyy!!!\n", fahrenheit, celsius);

  } else {
    printf("Invalid option. Please try again.");    
  }

  return 0;
}

// Congratulations! You've successfully converted temperatures using our exciting formulae! 
// Stay tuned for more fun programming adventures!