//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Declaration of Variables
  int randomNumber, guess;
  int attempts = 0;
  
  // Generating Random Number
  srand(time(0));
  randomNumber = rand() % 100 + 1;
  
  // Game Begins
  printf("\nWelcome to the Number Guessing Game!\n");
  printf("I have a randomly generated number between 1 and 100. Can you guess it?\n");

  do {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);
    attempts++;
    
    // Checking the Guess
    if (guess < randomNumber)
      printf("Too low! Try again.\n");
    else if (guess > randomNumber)
      printf("Too high! Try again.\n");
    else
      printf("Congratulations! You guessed it right in %d attempts.\n", attempts);
      
  } while (guess != randomNumber);

  return 0;
}