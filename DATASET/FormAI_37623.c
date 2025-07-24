//FormAI DATASET v1.0 Category: Game ; Style: realistic
#include <stdio.h>

int main() {
  int number, guess, attempts = 0;
  srand(time(NULL)); // Seed the random number generator

  // Generate a random number between 1 and 100
  number = rand() % 100 + 1;

  printf("Welcome to the Number Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100, can you guess it?\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    attempts++;

    if (guess > number) {
      printf("Too high! Guess again.\n");
    } else if (guess < number) {
      printf("Too low! Guess again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
    }
  } while (guess != number);

  return 0;
}