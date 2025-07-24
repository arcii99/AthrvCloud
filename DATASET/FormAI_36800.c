//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include <stdio.h>

int main() {
  int option;
  double distance, temperature, celsius, kilometers, centimeters;

  printf("Welcome to the Grateful Unit Converter!\n");
  printf("Please choose an option:\n");
  printf("1. Miles to Kilometers\n");
  printf("2. Inches to Centimeters\n");
  printf("3. Fahrenheit to Celsius\n");
  printf("> ");
  scanf("%d", &option);

  switch (option) {
    case 1:
      printf("\nYou selected Miles to Kilometers.\n");
      printf("Enter a distance in miles: ");
      scanf("%lf", &distance);
      kilometers = distance * 1.60934;
      printf("%.2f miles is equal to %.2f kilometers.\n", distance, kilometers);
      break;

    case 2:
      printf("\nYou selected Inches to Centimeters.\n");
      printf("Enter a distance in inches: ");
      scanf("%lf", &distance);
      centimeters = distance * 2.54;
      printf("%.2f inches is equal to %.2f centimeters.\n", distance, centimeters);
      break;

    case 3:
      printf("\nYou selected Fahrenheit to Celsius.\n");
      printf("Enter a temperature in Fahrenheit: ");
      scanf("%lf", &temperature);
      celsius = (temperature - 32) * 5 / 9;
      printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temperature, celsius);
      break;

    default:
      printf("\nInvalid option selected.\n");
      break;
  }

  printf("\nThank you for using the Grateful Unit Converter!\n");

  return 0;
}