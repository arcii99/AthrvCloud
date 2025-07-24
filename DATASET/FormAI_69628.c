//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int choice;
  
  printf("Welcome to the Temperature Converter!\n\n");
  printf("What would you like to convert?\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("Enter your choice (1 or 2): ");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 1.8) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.", celsius, fahrenheit);
  } 
  else if (choice == 2) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) / 1.8;
    printf("%.2f Fahrenheit is equal to %.2f Celsius.", fahrenheit, celsius);
  } 
  else {
    printf("Invalid choice.");
  }

  return 0;
}