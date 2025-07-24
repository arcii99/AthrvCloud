//FormAI DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL)); // Seed the RNG
  int guess, number;
  int max_guesses = 5;
  int guesses_left = max_guesses;

  printf("Guess the number between 1 and 100.\n");

  number = rand() % 100 + 1; // Generate random number between 1 and 100

  while (guesses_left > 0) {
    printf("\nYou have %d guess(es) left.\n", guesses_left);
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess == number) {
      printf("\nCongratulations, you found the number %d with %d guess(es) left!\n", number, guesses_left - 1);
      return 0;
    } else if (guess < number) {
      printf("Too low!\n");
    } else {
      printf("Too high!\n");
    }

    guesses_left--;
  }

  printf("\nSorry, you ran out of guesses. The number was %d.\n", number);
  return 0;
}