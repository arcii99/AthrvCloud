//FormAI DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>

int main() {
  printf("Guess the number between 1 and 100\n\n");

  srand(time(NULL)); //seed the random number generator
  int randomNumber = rand() % 100 + 1; //generate a random number between 1 and 100

  int userGuess = 0;
  int numGuesses = 0;

  do {
    printf("Enter your guess: ");
    scanf("%d", &userGuess); //record the user's guess
    numGuesses++; //increment the count of guesses

    if(userGuess > randomNumber) { //if the user's guess is too high
      printf("Too high! Try again\n");
    }
    else if(userGuess < randomNumber) { //if the user's guess is too low
      printf("Too low! Try again\n");
    }
    else { //if the user's guess is correct
      printf("Congratulations! You guessed the number in %d guesses\n", numGuesses);
    }

  } while(userGuess != randomNumber);

  return 0;
}