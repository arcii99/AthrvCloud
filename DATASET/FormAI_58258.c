//FormAI DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>

int main() {
  float celsius, fahrenheit;
  int choice;

  printf("Temperature Converter Menu\n");
  printf("-------------------------\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");
  printf("Please choose an option (1 or 2): ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Enter temperature in Celsius: ");
      scanf("%f", &celsius);

      fahrenheit = celsius * (9.0 / 5.0) + 32.0;

      printf("%.1f°C = %.1f°F", celsius, fahrenheit);
      break;

    case 2:
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &fahrenheit);

      celsius = (fahrenheit - 32.0) * (5.0 / 9.0);

      printf("%.1f°F = %.1f°C", fahrenheit, celsius);
      break;

    default:
      printf("Invalid option chosen.");
      break;
  }
  
  return 0;
}