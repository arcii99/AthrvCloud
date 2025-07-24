//FormAI DATASET v1.0 Category: Educational ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int guess, attempts=0;
  srand(time(NULL)); // initialize the random number generator
  int secret_num = rand() % 100 + 1; // generate a random number between 1 and 100

  printf("Welcome to the Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    attempts++;

    if (guess > secret_num) {
      printf("Too high! Try again.\n");
    } else if (guess < secret_num) {
      printf("Too low! Try again.\n");
    }

  } while (guess != secret_num);

  printf("\nCongratulations!! You guessed the secret number in %d attempts!\n", attempts);

  return 0;
}