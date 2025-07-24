//FormAI DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Welcome message to the player
  printf("Welcome to the Mind-Bending game!\n");
  printf("In this game, you will be given a number between 1 to 100.\n");
  printf("Your task is to guess the number that the computer is thinking.\n");
  printf("You will have 10 attempts to guess the correct number.\n");

  // Initializing variables
  int numberToGuess, guess, numberOfGuesses = 0;
  srand(time(0));
  numberToGuess = rand() % 100 + 1;

  // Loop for taking input and giving output
  while(1) {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    numberOfGuesses++;

    if(guess == numberToGuess) {
      printf("Congratulations! You have guessed the correct number in %d attempts.\n", numberOfGuesses);
      break;
    }
    else if(guess < numberToGuess) {
      printf("The number is higher than your guess.\n");
    }
    else {
      printf("The number is lower than your guess.\n");
    }

    if(numberOfGuesses == 10) {
      printf("Sorry! You have used all your attempts.\n");
      printf("The correct number was %d.\n", numberToGuess);
      break;
    }
  }

  return 0;
}