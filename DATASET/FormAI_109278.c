//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Sherlock Holmes
/*
  "The Case of the Mysterious Temperature Converter"
  In this program, Sherlock Holmes is asked to investigate a temperature converter that has been causing chaos throughout London. Clients are finding that the converter gives unreliable results, causing a great deal of trouble. While examining the code, Sherlock discovers that the converter is not calculating the temperature correctly. It is his task to solve the case and put an end to the confusion once and for all.
*/

#include <stdio.h>

double convertToFahrenheit(double celsius) {
  double fahrenheit = (celsius * 9 / 5) + 32; 
  return fahrenheit;
}

double convertToCelsius(double fahrenheit) {
  double celsius = (fahrenheit - 32) * 5 / 9;
  return celsius;
}

int main() {
  // Let's ask the user for the temperature they want to convert
  double temperature;
  printf("What is the temperature you would like to convert? ");
  scanf("%lf", &temperature);

  // Let's ask the user for the type of unit they want to convert
  char unit;
  printf("Is the temperature in Celsius or Fahrenheit? (Enter C or F): ");
  scanf(" %c", &unit);

  // We'll use a switch statement to determine which conversion function to call
  double convertedTemp;
  switch(unit) {
    case 'C':
    case 'c':
      convertedTemp = convertToFahrenheit(temperature);
      printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temperature, convertedTemp);
      break;
    case 'F':
    case 'f':
      convertedTemp = convertToCelsius(temperature);
      printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temperature, convertedTemp);
      break;
    default:
      printf("Invalid input. Please enter C or F.\n");
      break;
  }

  // Let's return 0, since our program has been executed successfully.
  return 0;
}