//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, numguesses = 0;
  
  // Generate a random number between 1 and 100
  srand(time(0));
  number = rand() % 100 + 1;
  
  printf("Welcome to the Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
  
  // Loop until user guesses correctly
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    // Check if guess is too high or too low
    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    }
    
    // Increment number of guesses
    numguesses++;
  } while (guess != number);
  
  // Congratulate user and print number of guesses
  printf("Congratulations! You guessed the number in %d guesses.\n", numguesses);
  
  return 0;
}