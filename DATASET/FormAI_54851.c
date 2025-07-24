//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number_of_guesses=1, number, max_range;
  time_t t;

  // Initializing random number generator
  srand((unsigned) time(&t));

  // Prompt user to enter max range for the random number
  printf("Enter max range for the random number: ");
  scanf("%d", &max_range);

  // Generate a random number
  number = rand() % max_range + 1;

  // Prompt user to make a guess
  printf("Guess a number between 1 and %d.\n", max_range);
  printf("Enter your guess: ");
  scanf("%d", &guess);

  // Loop until user guesses the number
  while (guess != number) {
    number_of_guesses++;
    
    if (guess > number) {
      printf("Too high. Try again.\n");
    } else {
      printf("Too low. Try again.\n");
    }

    printf("Enter your guess: ");
    scanf("%d", &guess);
  }

  // Print the number of guesses it took to guess the number
  printf("You guessed the number in %d guesses!\n", number_of_guesses);

  return 0;
}