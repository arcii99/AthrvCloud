//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

int main() {
  float celsius, fahrenheit;

  printf("Hello there! Welcome to my temperature converter!\n");
  printf("Please enter a temperature in Celsius: ");
  scanf("%f", &celsius);

  // Convert Celsius to Fahrenheit
  fahrenheit = (celsius * 1.8) + 32;
  
  // Output result in a happy message
  printf("\n\n******* CONVERSION COMPLETE! *******\n");
  printf("Your temperature in Fahrenheit is: %.2f\n", fahrenheit);
  printf("Hooray! You've successfully converted Celsius to Fahrenheit!\n");
  printf("You're now a temperature conversion pro! Keep up the good work! :)\n");

  return 0;
}