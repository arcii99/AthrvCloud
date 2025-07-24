//FormAI DATASET v1.0 Category: Temperature Converter ; Style: random
#include <stdio.h>
//a Celsius to Fahrenheit temperature converter!

int main() {
  float celsius, fahrenheit; //declaring variables

  printf("Welcome to the Celsius to Fahrenheit Converter! \n\n");

  printf("Enter a temperature in Celsius: "); //requesting the temperature in Celsius
  scanf("%f", &celsius); //receiving the input

  fahrenheit = (celsius * 1.8) + 32; //formula

  printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit. \n", celsius, fahrenheit); //print the converted temperature

  printf("\nThank you for using the Celsius to Fahrenheit Converter! \n");

  return 0; //end the program
}