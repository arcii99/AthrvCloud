//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Generate a random number
  srand(time(NULL));
  int secret_num = rand() % 100 + 1;

  printf("Guess a number between 1 and 100\n");

  int guess;
  int num_guesses = 0;

  // Loop until the user guesses the correct number
  while (1) {
    
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess < 1 || guess > 100) {
      printf("Invalid guess. Please enter a number between 1 and 100\n");
      continue;
    }
    
    num_guesses++;

    if (guess == secret_num) {
      printf("Congratulations! You guessed the secret number in %d guesses!\n", num_guesses);
      break;
    } else if (guess < secret_num) {
      printf("Too low! Guess again.\n");
    } else {
      printf("Too high! Guess again.\n");
    }

  }
  return 0;
}