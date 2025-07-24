//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // initialize the random number generator
  srand(time(NULL));
  
  // generate a random number between 1 and 100
  int secretNumber = rand() % 100 + 1;
  
  // start the game
  printf("Welcome to the Guess the Number Game!\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n\n");
  
  // loop until the player guesses the correct number
  int guess;
  int numOfGuesses = 0;
  do {
    // prompt the player to enter a guess
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    // check if the guess is too high, too low, or correct
    if (guess < secretNumber) {
      printf("Too low! Try again.\n\n");
    } else if (guess > secretNumber) {
      printf("Too high! Try again.\n\n");
    } else {
      printf("Congratulations! You guessed the number in %d tries.\n", numOfGuesses);
    }
    
    // increment the number of guesses
    numOfGuesses++;
  } while (guess != secretNumber);
  
  return 0;
}