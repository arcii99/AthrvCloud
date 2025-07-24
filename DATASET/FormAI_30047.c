//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>

int main() {
  int number = 42; // We'll start with a "magic number"

  printf("Welcome to the curious game of number guessing!\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

  while (1) { // Infinite loop until the user guesses the number
    int guess; // Variable to store the user's guess
    printf("Enter your guess: ");

    if (scanf("%d", &guess) == 1) { // Make sure the user enters a valid number
      if (guess < 1 || guess > 100) { // Make sure the number is within the range
        printf("That's not a number between 1 and 100. Try again!\n");
        continue; // Start again from the while loop
      }

      if (guess < number) {
        printf("Too low! Guess higher.\n");
      } else if (guess > number) {
        printf("Too high! Guess lower.\n");
      } else {
        printf("Congratulations! You guessed the number.\n"); // Exit the loop
        break;
      }
    } else { // If the user enters an invalid number
      printf("That's not a valid number. Try again!\n");
      fflush(stdin); // Clear the input buffer
    }
  }

  return 0; // End the program
}