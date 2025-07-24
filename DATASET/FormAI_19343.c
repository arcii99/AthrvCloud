//FormAI DATASET v1.0 Category: Unit converter ; Style: artistic
#include <stdio.h>

int main() {
  int choice;
  float input_value, output_value;

  printf("Welcome to the artistic C unit converter:\n");
  printf("Enter the option to convert:\n 1. Fahrenheit to Celsius\n 2. Feet to Meters\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter the temperature in Fahrenheit:\n");
      scanf("%f", &input_value);
      output_value = (input_value - 32) * 5/9;
      printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", input_value, output_value);
      break;
    case 2:
      printf("Enter the length in feet:\n");
      scanf("%f", &input_value);
      output_value = input_value / 3.281;
      printf("%.2f feet is equal to %.2f meters.\n", input_value, output_value);
      break;
    default:
      printf("Invalid choice\n");
  }

  printf("Thank you for using the artistic C unit converter!\n");

  return 0;
}