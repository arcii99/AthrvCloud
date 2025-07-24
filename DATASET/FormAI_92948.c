//FormAI DATASET v1.0 Category: Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random seed
  srand(time(NULL));

  // Declare variables
  int num_guesses = 0;
  int num_to_guess = rand() % 100; // Generate random number between 0 and 99
  int guess = -1; // Set initial guess to an invalid number

  // Display welcome message
  printf("Welcome to the Number Guessing Game!\n");
  printf("I am thinking of a number between 0 and 99.\n");

  // Loop until player correctly guesses the number
  while (guess != num_to_guess) {
    // Prompt player for guess
    printf("Guess a number: ");
    scanf("%d", &guess);

    // Increment number of guesses
    num_guesses++;

    // Check if guess is too high, too low, or correct
    if (guess < num_to_guess) {
      printf("Too low!\n");
    } else if (guess > num_to_guess) {
      printf("Too high!\n");
    } else {
      printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
    }
  }

  return 0;
}