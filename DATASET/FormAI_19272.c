//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

int main() {
  float f, c;
  int choice;

  printf("Temperature Converter\n");
  printf("1. Fahrenheit to Celsius\n");
  printf("2. Celsius to Fahrenheit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &f);
    c = (f - 32) * 5/9;
    printf("%.2f°F = %.2f°C", f, c);
  }
  else if (choice == 2) {
    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);
    f = (c * 9/5) + 32;
    printf("%.2f°C = %.2f°F", c, f);
  }
  else {
    printf("Invalid choice. Please try again.");
  }

  return 0;
}