//FormAI DATASET v1.0 Category: Educational ; Style: active
#include <stdio.h>

int main() {
  // Welcome message
  printf("Welcome to the Guessing Game!\n");
  
  // Generate a random number between 1 and 100
  int secret_number = rand() % 100 + 1;
  printf("I've chosen a number between 1 and 100. Can you guess what it is?\n");
  
  // Loop until the user correctly guesses the number
  int guess;
  int num_guesses = 0;
  while (1) {
    // Get the user's guess
    printf("Enter your guess: ");
    scanf("%d", &guess);
    num_guesses++;
    
    // Check if the guess is correct
    if (guess == secret_number) {
      printf("Congratulations! You guessed the number in %d guesses!\n", num_guesses);
      break;
    }
    
    // Provide a hint if the guess is too high or too low
    if (guess > secret_number) {
      printf("Too high. Try again.\n");
    } else {
      printf("Too low. Try again.\n");
    }
  }
  
  return 0;
}