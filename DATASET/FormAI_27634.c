//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // game setup
  srand(time(NULL));
  int secret_num = rand() % 100 + 1;
  int guess, num_guesses = 0;

  // game instructions
  printf("Welcome to the Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");
  printf("You have 10 tries to guess it.\n");

  // main game loop
  while (num_guesses < 10) {
    printf("\nGuess #%d: ", num_guesses + 1);
    scanf("%d", &guess);

    if (guess < 1 || guess > 100) {
      printf("Invalid guess. Please try again.\n");
      continue;
    }

    if (guess == secret_num) {
      printf("Congratulations! You guessed the secret number in %d tries.\n", num_guesses + 1);
      return 0;
    } else if (guess < secret_num) {
      printf("Too low! Guess again.\n");
    } else {
      printf("Too high! Guess again.\n");
    }

    num_guesses++;
  }

  printf("Sorry, you didn't guess the secret number in time.\n");
  printf("The secret number was: %d\n", secret_num);
  return 0;
}