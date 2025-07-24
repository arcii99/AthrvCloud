//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Taking the current time as seed for random number generator
  int num_guesses = 0; // Initializing the number of guesses to 0
  int number_to_guess = rand() % 100; // Generating a random number between 0 to 99
  int guess = -1; // Initializing the guess to be outside the range of the number to guess
  
  printf("Welcome to the Number Guessing Game!\n");
  printf("I am thinking of a number between 0 and 99. Can you guess it?\n");
  
  while (guess != number_to_guess) {
    printf("Guess: ");
    scanf("%d", &guess); // Getting the guess from user input
    num_guesses++; // Incrementing the number of guesses
    
    if (guess < number_to_guess) {
      printf("Too low! Try again.\n");
    } else if (guess > number_to_guess) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
    }
  }

  return 0;
}