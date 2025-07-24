//FormAI DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Seed random number generator
  srand(time(NULL));

  // Generate a random number between 1 and 100
  int secret_number = rand() % 100 + 1;

  // Initialize user guess and number of guesses
  int guess;
  int num_guesses = 0;

  // Print instructions and prompt user for guess
  printf("Welcome to the guessing game!\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");
  printf("Enter your guess below:\n");
  scanf("%d", &guess);
  num_guesses++;

  // Loop until user guesses correctly
  while (guess != secret_number) {

    // If user's guess is too low, inform user and prompt for new guess
    if (guess < secret_number) {
      printf("Too low! Try again.\n");
      scanf("%d", &guess);
      num_guesses++;
    }

    // If user's guess is too high, inform user and prompt for new guess
    else {
      printf("Too high! Try again.\n");
      scanf("%d", &guess);
      num_guesses++;
    }
  }

  // If user guesses correctly, display congratulations message and number of guesses
  printf("Congratulations! You guessed the secret number in %d tries.\n", num_guesses);

  return 0;
}