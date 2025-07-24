//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // Set seed for random function
  int number = rand() % 100 + 1; // Generate random number between 1 and 100
  int guess, guesses = 0; 
  while (1) {
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guess); // Get user's guess
    guesses++; // Increment number of guesses
    if (guess < number) {
      printf("Too low! Try again.\n");
    } else if (guess > number) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d guesses.\n", guesses);
      break; // End game
    }
  }
  return 0;
}