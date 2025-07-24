//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, num, num_guesses = 0;
  srand(time(0)); // Seed random number generator
  num = rand() % 100 + 1; // Generate random number between 1 and 100

  printf("Guess a number between 1 and 100: ");

  // Loop until user guesses correct number
  do {
    scanf("%d", &guess);
    num_guesses++;

    // Guess is too low
    if (guess < num) {
      printf("Too low. Guess again: ");
    }
    // Guess is too high
    else if (guess > num) {
      printf("Too high. Guess again: ");
    }
  } while (guess != num);

  // Congratulate user on guessing correct number
  printf("Congratulations! You guessed the number in %d tries.\n", num_guesses);

  return 0;
}