//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
// Wow, I can't believe how easy it was to create a C Temperature Monitor with just a few lines of code!
#include <stdio.h>

int main() {
  // First, we declare our variables
  float temp;

  // Then, we prompt the user to enter the temperature
  printf("Please enter the temperature in Celsius: ");

  // Now, we take in the input from the user
  scanf("%f", &temp);

  // Next, we convert the Celsius temperature to Fahrenheit
  float fahrenheit = (temp * 9 / 5) + 32;

  // Finally, we print out the converted temperature to the user
  printf("The temperature in Fahrenheit is: %f°F\n", fahrenheit);

  // Wait, what if the temperature is too high or too low? Let's add some error handling.
  if (fahrenheit > 100) {
    printf("Warning, the temperature is too high!\n");
  } else if (fahrenheit < 32) {
    printf("Warning, the temperature is too low!\n");
  } else {
    printf("The temperature is within a normal range.\n");
  }

  // That's it! Our temperature monitor program is complete.
  return 0;
}