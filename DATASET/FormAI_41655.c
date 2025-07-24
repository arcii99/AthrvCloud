//FormAI DATASET v1.0 Category: Funny ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator

  printf("Welcome to the exciting guessing game!\n\n");
  printf("I'm thinking of a number between 1 and 100!\n\n");

  int secret = rand() % 100 + 1; // Generate random number between 1 and 100

  int guess; // Variable to store user's guess
  int num_attempts = 0; // Counter for number of attempts

  do {
    printf("Enter your guess (between 1 and 100): ");
    scanf("%d", &guess);
    num_attempts++;

    if (guess < secret) {
      printf("Too low! Guess higher.\n");
    } else if (guess > secret) {
      printf("Too high! Guess lower.\n");
    } else {
      printf("You guessed it! The secret number was %d.\n", secret);
      printf("It only took you %d attempts!\n", num_attempts);
    }

  } while (guess != secret);

  printf("\nThanks for playing! Come back soon!\n");
  return 0;
}