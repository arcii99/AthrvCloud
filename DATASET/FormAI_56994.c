//FormAI DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>

int main(void) {
  int choice;
  float temp, convertedTemp;

  printf("Welcome to the Future Temperature Converter!\n");
  printf("Please select the temperature scale to convert from:\n\n");
  printf("1) Celsius\n");
  printf("2) Fahrenheit\n");
  printf("3) Kelvin\n\n");

  scanf("%d", &choice);

  if (choice == 1) {
    printf("\nEnter temperature in Celsius: ");
    scanf("%f", &temp);

    // Convert Celsius to Fahrenheit
    convertedTemp = (temp * 9) / 5 + 32;

    printf("%.2fC is equal to %.2fF\n\n", temp, convertedTemp);

  } else if (choice == 2) {
    printf("\nEnter temperature in Fahrenheit: ");
    scanf("%f", &temp);

    // Convert Fahrenheit to Celsius
    convertedTemp = (temp - 32) * 5 / 9;

    printf("%.2fF is equal to %.2fC\n\n", temp, convertedTemp);

  } else if (choice == 3) {
    printf("\nEnter temperature in Kelvin: ");
    scanf("%f", &temp);

    // Convert Kelvin to Celsius
    convertedTemp = temp - 273.15;

    printf("%.2fK is equal to %.2fC\n\n", temp, convertedTemp);

  } else {
    printf("\nInvalid choice, please try again.\n\n");
  }

  return 0;
}