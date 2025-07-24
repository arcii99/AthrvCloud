//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); //seed random number generator

  printf("Welcome to the C Table Game!\n");
  printf("Here are the rules:\n");
  printf("1. You have to guess a number between 1 and 100.\n");
  printf("2. You will be given 7 chances to guess the number.\n");
  printf("3. If you guess the number correctly, you win!\n");
  printf("4. If you don't guess the number correctly within 7 chances, you lose.\n");

  int randomNumber = (rand() % 100) + 1; //generate random number between 1 and 100
  int userGuess;
  int numGuesses = 0;
  int maxGuesses = 7;

  while (numGuesses < maxGuesses) {
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &userGuess);
    numGuesses++;

    if (userGuess < 1 || userGuess > 100) {
      printf("Invalid guess! Please guess a number between 1 and 100.\n");
      numGuesses--; //don't count invalid guesses towards total guesses
    }
    else if (userGuess == randomNumber) {
      printf("Congratulations, you win!\n");
      printf("You guessed the number in %d guesses.\n", numGuesses);
      return 0;
    }
    else if (userGuess < randomNumber) {
      printf("Your guess is too low.\n");
    }
    else {
      printf("Your guess is too high.\n");
    }

    printf("You have %d guesses left.\n", maxGuesses - numGuesses);
  }

  printf("Sorry, you lose!\n");
  printf("The number was %d.\n", randomNumber);
  return 0;
}