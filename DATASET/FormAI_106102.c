//FormAI DATASET v1.0 Category: Random ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;

  // initialize random number generator
  srand(time(NULL));

  // generate random number between 1 and 100
  num = rand() % 100 + 1;

  printf("Guess a number between 1 and 100: ");

  // keep asking for guesses until the correct number is guessed
  do {
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Lower!\n");
    } else if (guess < num) {
      printf("Higher!\n");
    }
  } while (guess != num);

  printf("Congratulations! You guessed the number in %d tries!\n", tries);

  return 0;
}