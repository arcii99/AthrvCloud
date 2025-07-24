//FormAI DATASET v1.0 Category: Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, number, count = 0;
  srand(time(NULL));
  number = rand() % 100 + 1;

  printf("Guess a number between 1 and 100\n");

  while (guess != number) {
    count++;
    printf("Enter your guess: ");
    scanf("%d", &guess);

    if (guess > number) {
      printf("Too high\n");
    }
    else if (guess < number) {
      printf("Too low\n");
    }
    else {
      printf("Congratulations! You guessed it in %d tries\n", count);
    }
  }

  return 0;
}