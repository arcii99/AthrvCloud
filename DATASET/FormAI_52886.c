//FormAI DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  // Generating a random number
  srand(time(NULL));
  int target = rand() % 100 + 1;

  printf("Guess a number between 1 and 100:\n");

  int guess;
  scanf("%d", &guess);

  int attempts = 1;

  while (guess != target) {
    if (guess < target) {
      printf("Too low, guess again:\n");
    } else {
      printf("Too high, guess again:\n");
    }
    scanf("%d", &guess);
    attempts++;
  }

  printf("Congratulations, you guessed the number in %d attempts!", attempts);

  return 0;
}