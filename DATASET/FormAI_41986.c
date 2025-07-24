//FormAI DATASET v1.0 Category: Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator with current time
  
  int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
  int guess = 0; // Initialize user's guess as 0
  int numGuesses = 0; // Initialize number of guesses as 0
  
  printf("Guess a number between 1 and 100!\n");
  
  // Main while loop to receive guesses and check them against the secret number
  while (guess != secretNumber) {
    scanf("%d", &guess); // Receive user input for guess
    numGuesses++; // Increment number of guesses
    
    if (guess < secretNumber) { // Check if guess is too low
      printf("Too low! Guess again:\n");
    } else if (guess > secretNumber) { // Check if guess is too high
      printf("Too high! Guess again:\n");
    } else { // If guess is correct
      printf("Congratulations! You guessed the secret number in %d guess(es)!\n", numGuesses);
    }
  }
  
  return 0; // End program
}