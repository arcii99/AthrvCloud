//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int choice;

  printf("1. Convert Celsius to Fahrenheit\n");
  printf("2. Convert Fahrenheit to Celsius\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  if(choice == 1) {
    printf("Enter Celsius temperature: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2fC is equal to %.2fF\n", celsius, fahrenheit);
  } else if(choice == 2) {
    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2fF is equal to %.2fC\n", fahrenheit, celsius);
  } else {
    printf("Invalid choice!\n");
  }

  return 0;
}