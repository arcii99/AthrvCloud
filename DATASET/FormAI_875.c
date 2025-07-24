//FormAI DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>

float convertCtoF(float tempC) { // convert Celsius to Fahrenheit
  float tempF = (tempC * 1.8) + 32;
  return tempF;
}

float convertFtoC(float tempF) { // convert Fahrenheit to Celsius
  float tempC = (tempF - 32) / 1.8;
  return tempC;
}

int main() {
  float temp, result;
  char choice;

  printf("Welcome to the paranoid temperature converter!\n");
  printf("Are you sure you want to convert a temperature? (y/n)\n");
  scanf("%c", &choice);

  if (choice == 'y') {
    printf("Please enter a temperature: ");
    scanf("%f", &temp);

    printf("Are you sure it's in Celsius? (y/n)\n");
    scanf("%c", &choice); // consume the enter key

    scanf("%c", &choice);
    if (choice == 'y') {
      result = convertCtoF(temp);
      printf("%.2f C = %.2f F\n", temp, result);
    } else {
      printf("Then it must be in Fahrenheit.\n");
      result = convertFtoC(temp);
      printf("%.2f F = %.2f C\n", temp, result);
    }
  } else {
    printf("Okay, better safe than sorry!");
  }

  return 0;
}