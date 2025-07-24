//FormAI DATASET v1.0 Category: Temperature Converter ; Style: minimalist
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int option;

  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius);

  printf("\nChoose an option:");
  printf("\n1. Convert to Fahrenheit");
  printf("\n2. Quit");
  printf("\nOption: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      fahrenheit = (celsius * 9/5) + 32;
      printf("%.2f C = %.2f F", celsius, fahrenheit);
      break;
    case 2:
      printf("Exiting the program...");
      break;
    default:
      printf("Invalid option!");
      break;
  }

  return 0;
}