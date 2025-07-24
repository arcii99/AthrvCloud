//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>

int main() {
  float temp_celsius;
  float temp_fahrenheit;

  printf("Welcome to the wacky temperature converter!\n");
  printf("Enter a temperature in Celsius and we'll convert it to Fahrenheit: ");
  
  // Get user input
  scanf("%f", &temp_celsius);

  // Do some calculations
  temp_fahrenheit = (temp_celsius * 9 / 5) + 32;

  // Display the result
  printf("\nCalculating...\n");
  printf("Beep boop beep...\n");
  printf("Your temperature in Fahrenheit is: %.2f\n", temp_fahrenheit);

  printf("\nBut wait, there's more!\n");
  printf("Did you know that you can also convert temperatures from Fahrenheit to Celsius?\n");
  printf("Just give me a temperature in Fahrenheit and we'll do the rest!\n");
  
  // Get user input again
  scanf("%f", &temp_fahrenheit);

  // Do more calculations
  temp_celsius = (temp_fahrenheit - 32) * 5 / 9;

  // Display the final result
  printf("\nCalculating again...\n");
  printf("Boop beep boop...\n");
  printf("Your temperature in Celsius is: %.2f\n", temp_celsius);

  printf("\nVoila! That's all, folks!\n");
  printf("Thank you for using our temperature converter. We hope you had a blast!\n");

  return 0;
}