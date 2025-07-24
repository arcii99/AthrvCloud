//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10
#define RANGE 100

int main() {
  int numberToGuess, guess, numGuesses = 0;
  srand(time(0));
  numberToGuess = rand() % RANGE + 1;

  printf("Welcome to the Guessing Game!\nI'm thinking of a number between 1 and %d.\n", RANGE);
  printf("You have %d guesses. Good luck!\n", MAX_GUESSES);

  while (numGuesses < MAX_GUESSES) {
    printf("Guess #%d: ", numGuesses + 1);
    scanf("%d", &guess);
    if (guess < 1 || guess > RANGE) {
      printf("Your guess must be between 1 and %d. Try again.\n", RANGE);
      continue;
    }

    numGuesses++;
    if (guess == numberToGuess) {
      printf("Congratulations! You guessed the number in %d tries!\n", numGuesses);
      return 0;
    } else if (guess < numberToGuess) {
      printf("Too low. ");
    } else {
      printf("Too high. ");
    }

    if (numGuesses == MAX_GUESSES) {
      printf("Sorry, you didn't guess the number. It was %d.\n", numberToGuess);
    } else {
      printf("You have %d guesses left.\n", MAX_GUESSES - numGuesses);
    }
  }

  return 0;
}