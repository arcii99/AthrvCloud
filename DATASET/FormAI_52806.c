//FormAI DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
  float fahrenheit, celsius; // declare two float variables
  printf("Welcome to my temperature converter program!\n");
  printf("Enter the temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit); // get input from user
  // convert Fahrenheit to Celsius
  celsius = (fahrenheit - 32) * 5/9;
  printf("%.2fF is equal to %.2fC\n", fahrenheit, celsius);
  printf("Exciting right?! Now, let's convert Celsius to Fahrenheit!\n");
  printf("Enter the temperature in Celsius: ");
  scanf("%f", &celsius); // get input from user again
  // convert Celsius to Fahrenheit
  fahrenheit = (celsius * 9/5) + 32;
  printf("%.2fC is equal to %.2fF\n", celsius, fahrenheit);
  printf("Now you know how to convert temperatures like a pro! Keep exploring!\n");
  return 0;
}