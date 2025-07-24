//FormAI DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>

// These are preprocessor directives which are like #include headers
// This will ensure that the functions from these libraries are available
#include <time.h>
#include <stdlib.h>

int main() {
  printf("Guess the number between 1 and 100\n");

  // Randomize the seed for the random number generator
  srand(time(NULL));

  // Get a random number between 1 and 100
  int number = rand() % 100 + 1;
  int guess;
  int num_guesses = 0;

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess < number) {
      printf("Too low, try again.\n");
    } else if (guess > number) {
      printf("Too high, try again.\n");
    }

    num_guesses++;
  } while (guess != number);

  printf("Congratulations, you guessed the number in %d guesses!\n", num_guesses);

  return 0;
}