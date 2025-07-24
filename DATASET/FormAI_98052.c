//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>

int main() {
  printf("###################################################\n");
  printf("### Welcome to the Temperature Converter 2000! ###\n");
  printf("###################################################\n");

  float tempCelsius, tempFahrenheit;
  char choice;

  printf("Enter the temperature in Celsius: ");
  scanf("%f", &tempCelsius);

  printf("\nChoose what you want to convert it to:\n");
  printf("Fahrenheit (press F) or Kelvin (press K)? ");
  scanf(" %c", &choice);

  if (choice == 'F') {
    tempFahrenheit = (tempCelsius * 9/5) + 32;
    displayConversion(tempCelsius, tempFahrenheit, 'F');
  }
  else if (choice == 'K') {
    float tempKelvin = tempCelsius + 273.15;
    displayConversion(tempCelsius, tempKelvin, 'K');
  }
  else {
    displayError();
  }

  return 0;
}

void displayConversion(float tempCelsius, float convertedTemp, char choice) {
  printf("\n***************************************************\n");
  printf("*** Temperature Conversion from Celsius to %c ***\n", choice);
  printf("***************************************************\n\n");
  printf("%.1f°C is equivalent to %.1f%c\n", tempCelsius, convertedTemp, choice);
}

void displayError() {
  printf("\nERROR: Invalid conversion choice!\n");
}