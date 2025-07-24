//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  float celsius;
  int choice;

  printf("Welcome to the Temperature Converter! Please select an option:\n");
  printf("1. Convert Celsius to Fahrenheit.\n");
  printf("2. Convert Fahrenheit to Celsius.\n");
  scanf("%d", &choice);

  if(choice == 1) { // Celsius to Fahrenheit
    printf("\nOh boy, you're going to need some heat! Please input the temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 1.8) + 32;
    printf("\n%.2f degrees Celsius is %.2f degrees Fahrenheit. Enjoy the heat!\n", celsius, fahrenheit);
  } else if(choice == 2) { // Fahrenheit to Celsius
    printf("\nOh no, too much heat! Please input the temperature in Fahrenheit: ");
    scanf("%f", &celsius);
    float fahrenheit = (celsius - 32) * 0.5556; // I'm not good with math, but thankfully the internet is!
    printf("\n%.2f degrees Fahrenheit is %.2f degrees Celsius. Cool off!\n", celsius, fahrenheit);
  } else {
    printf("\nThat's not a valid option! Go cool down and try again.\n");
    exit(0); // I'm sorry, I can't let you do that, Dave.
  }

  return 0;
}