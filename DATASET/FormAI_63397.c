//FormAI DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>

int main() {
  float input_number;
  int option;

  printf("Welcome to the Mind-Bending Unit Converter!\n");
  printf("---------------------------------------------\n\n");
  printf("Please select an option:\n");
  printf("1. Convert meters to miles\n");
  printf("2. Convert kilograms to grams\n");
  printf("3. Convert Fahrenheit to Celsius\n\n");
  printf("Option: ");
  scanf("%d", &option);

  switch(option) {
    case 1:
      printf("\nYou have selected meters to miles converter.\n");
      printf("Please enter the number of meters to convert: ");
      scanf("%f", &input_number);
      printf("%f meters is equivalent to %f miles!\n", input_number, input_number / 1609.344);
      break;

    case 2:
      printf("\nYou have selected kilograms to grams converter.\n");
      printf("Please enter the number of kilograms to convert: ");
      scanf("%f", &input_number);
      printf("%f kilograms is equivalent to %f grams!\n", input_number, input_number * 1000);
      break;

    case 3:
      printf("\nYou have selected Fahrenheit to Celsius converter.\n");
      printf("Please enter the temperature in degrees Fahrenheit to convert: ");
      scanf("%f", &input_number);
      printf("%f degrees Fahrenheit is equivalent to %f degrees Celsius!\n", input_number, (input_number - 32) * 5 / 9);
      break;

    default:
      printf("\nInvalid option selected. Please try again.\n");
  }

  return 0;
}