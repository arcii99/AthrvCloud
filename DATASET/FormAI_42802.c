//FormAI DATASET v1.0 Category: Table Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
  printf("Welcome to the C Table Game!\n");
  
  // Initialize random seed
  srand(time(NULL));
  
  // Generate random number between 1 and 100
  int secret_number = rand() % 100 + 1;
  
  // Initialize player guess and number of tries
  int guess;
  int tries = 0;
  
  // Loop while player hasn't guessed the secret number
  while (guess != secret_number) {
    
    // Prompt player for guess
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guess);
    
    // Increment number of tries
    tries++;
    
    // Check if guess is too high or too low
    if (guess > secret_number) {
      printf("Too high! Try again.\n");
    } else if (guess < secret_number) {
      printf("Too low! Try again.\n");
    } else {
      printf("Congratulations! You guessed the secret number in %d tries.\n", tries);
    }
    
  }
  
  return 0;
}