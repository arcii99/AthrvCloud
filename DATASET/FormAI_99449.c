//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>

int main() {
  float value;
  int option;

  printf("Welcome to the innovative unit converter!\n");
  printf("Please enter a value to convert: ");
  scanf("%f", &value);

  printf("Choose the option that you want to convert to:\n");
  printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Kilometers to Miles\n4. Miles to Kilometers\n");
  scanf("%d", &option);

  switch(option) {
    case 1:
      printf("%.2f Celsius is %.2f Fahrenheit.\n", value, (value * 1.8) + 32);
      break;
    case 2:
      printf("%.2f Fahrenheit is %.2f Celsius.\n", value, (value - 32) / 1.8);
      break;
    case 3:
      printf("%.2f Kilometers is %.2f Miles.\n", value, value / 1.609);
      break;
    case 4:
      printf("%.2f Miles is %.2f Kilometers.\n", value, value * 1.609);
      break;
    default:
      printf("Invalid option selected. Please try again.\n");
      break;
  }

  return 0;
}