//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Initialize RNG seed with current time.

  // Greet user.
  printf("Welcome to Guess the Number Game!\n");
  printf("Can you guess the number I'm thinking of?\n");

  int number = rand() % 100; // Generate random number between 0 and 99.
  int guess;
  int tries = 0;

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;

    if (guess > number) {
      printf("Too high! Try again.\n");
    } else if (guess < number) {
      printf("Too low! Try again.\n");
    }
  } while (guess != number);

  printf("Congratulations! You guessed the number in %d tries.\n", tries);

  return 0;
}