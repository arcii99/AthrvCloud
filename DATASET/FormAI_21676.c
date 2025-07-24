//FormAI DATASET v1.0 Category: Game ; Style: optimized
#include <stdio.h>

int main() {
  int num, guess, attempts = 0;
  srand(time(0)); // Seed random number generator
  num = rand() % 100 + 1; // Generate random number between 1 and 100
  printf("Guess the number between 1 and 100\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess < num) {
      printf("Too low\n");
    } else if (guess > num) {
      printf("Too high\n");
    }

    attempts++;
  } while (guess != num);

  printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

  return 0;
}