//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Ada Lovelace
/* 
 * User Input Sanitizer
 *  
 * This program takes a user input as an integer and sanitizes it to ensure
 * that the input falls within an acceptable range of values.
 *
 * By Ada Lovelace
 * 2021
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

  int userInput; // User input variable

  /* Greet the user and prompt for input */
  printf("Welcome to the User Input Sanitizer program.\n");
  printf("Please enter a number between 1 and 100: ");

  /* Get user input */
  scanf("%d", &userInput);

  /* Variables for range */
  int lowerLimit = 1;
  int upperLimit = 100;

  /* Check if input is within range */
  if (userInput >= lowerLimit && userInput <= upperLimit) {
    printf("Your input of %d is within the acceptable range.\n", userInput);
  } else {
    printf("Your input of %d is not within the acceptable range.\n", userInput);

    /* Sanitize input to be within range */
    if (userInput < lowerLimit) {
      userInput = lowerLimit;
      printf("Input has been sanitized to minimum value of %d.\n", lowerLimit);
    } else {
      userInput = upperLimit;
      printf("Input has been sanitized to maximum value of %d.\n", upperLimit);
    }
  }

  /* Output sanitized input */
  printf("Sanitized input: %d\n", userInput);

  return 0;
}