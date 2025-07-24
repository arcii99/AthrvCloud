//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Our main method where all the magic happens
int main() {
  // Prompt the user to enter a temperature in Celsius
  printf("Hey there! I heard you need help converting Celsius to Fahrenheit. What's the temperature in Celsius?\n");

  // Declare a variable to store user input
  double celsiusTemp;

  // Read the user input from the console
  scanf("%lf", &celsiusTemp);

  // Do some math to convert the Celsius temperature to Fahrenheit
  double fahrenheitTemp = (celsiusTemp * 9 / 5) + 32;

  // Print out the results of the conversion
  printf("Ah, I see. %lf degrees Celsius converts to %lf degrees Fahrenheit. Isn't math fun?\n", celsiusTemp, fahrenheitTemp);

  // Return our success code
  return 0;
}