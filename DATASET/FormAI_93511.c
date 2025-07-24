//FormAI DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int randomNumber, guess, numAttempts;
  
  // Generate a random number between 1-100
  srand(time(NULL)); // Seed the random number generator
  randomNumber = rand() % 100 + 1;
  
  printf("Welcome to the Guessing Game!\n\n");
  
  // Prompt the user to guess the number
  printf("Guess a number between 1 and 100:\n");
  
  // Keep prompting the user to guess until they get it right or use up all their attempts
  numAttempts = 0;
  do {
    scanf("%d", &guess);
    numAttempts++;
    
    if (guess == randomNumber) {
      printf("Congratulations! You guessed the number in %d attempts.\n", numAttempts);
    } else if (guess > randomNumber) {
      printf("Too high! Guess again:\n");
    } else {
      printf("Too low! Guess again:\n");
    }
  } while (guess != randomNumber && numAttempts < 10);
  
  // Tell the user if they ran out of attempts without guessing the number
  if (numAttempts == 10) {
    printf("\nSorry, you used up all 10 attempts. The number was %d.\n", randomNumber);
  }
  
  return 0;
}