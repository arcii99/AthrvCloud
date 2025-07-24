//FormAI DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>

int main() {

  char choice;
  float temp; // input temperature
  float result; // converted temperature

  printf("Welcome to the Temperature Converter Program!\n");
  printf("Please select the conversion type: [C]elsius to Fahrenheit or [F]ahrenheit to Celsius (C/F): ");
  scanf("%c", &choice);

  if (choice == 'C' || choice == 'c') {

    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &temp);

    result = (temp * 9 / 5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", temp, result);

  } else if (choice == 'F' || choice == 'f') {

    printf("Please enter the temperature in Fahrenheit: ");
    scanf("%f", &temp);

    result = (temp - 32) * 5 / 9;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", temp, result);

  } else {
    printf("Invalid choice.");
  }

  return 0;
}