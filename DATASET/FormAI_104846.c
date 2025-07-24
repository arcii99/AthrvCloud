//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number_of_guesses = 1, number_to_be_guessed;
  srand(time(0));
  number_to_be_guessed = rand() % 100 + 1;

  printf("\nWelcome to the 'Guess the Number' game!");
  printf("\n\nRules: You have to guess a number between 1 and 100. You will also be told whether your guess is too high or too low.");
  printf("\n\nLet's begin!");

  do {
    printf("\n\nGuess the number (Attempt %d): ", number_of_guesses);
    scanf("%d", &guess);
    number_of_guesses++;

    if (guess > number_to_be_guessed) {
      printf("Too high! Try again.");
    } else if (guess < number_to_be_guessed) {
      printf("Too low! Try again.");
    } else {
      printf("\n\nCongratulations! You guessed the number in %d attempts.", number_of_guesses - 1);
    }
  } while (guess != number_to_be_guessed);

  return 0;
}