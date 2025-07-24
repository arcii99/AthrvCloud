//FormAI DATASET v1.0 Category: Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  // Declare variables
  int secretNumber, guess, counter = 1;
  
  // Generate random number between 1-100
  srand(time(NULL));
  secretNumber = rand() % 100 + 1;
  
  // Start the game
  printf("Welcome to the Guessing Game!\n");
  printf("I am thinking of a number between 1 and 100.\n");
  printf("You have 5 guesses to find the secret number.\n\n");
  
  // Ask for user input and start the guessing loop
  while (counter <= 5) {
    printf("Guess #%d: ", counter);
    scanf("%d", &guess);
    
    // Compare user input with secret number
    if (guess == secretNumber) {
      printf("\nCongratulations, you guessed the secret number in %d tries!\n\n", counter);
      return 0;
    } else if (guess < secretNumber) {
      printf("Sorry, your guess is too low.\n");
    } else {
      printf("Sorry, your guess is too high.\n");
    }
    
    // Increase the guess counter
    counter++;
  }
  
  // Game over, reveal secret number
  printf("\nSorry, you didn't guess the secret number in 5 tries.\n");
  printf("The secret number was %d.\n\n", secretNumber);
  
  return 0;
}