//FormAI DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int r = rand() % 10;
  int num;

  printf("Welcome to the random number guessing game! Guess a number between 0-9: ");
  scanf("%d", &num);

  if (num == r) {
    printf("You guessed it! Congratulations!");
    return 0;
  } else if (num < 0 || num > 9) {
    printf("Oops! The number must be between 0-9!");
    exit(1);
  } else {
    printf("Sorry, that wasn't the number. Try again.");

    int tries = 1;
    while (1) {
      printf("\n\nGuess again: ");
      scanf("%d", &num);
      tries++;

      if (num == r) {
        printf("You guessed it! Congratulations!");
        return 0;
      } else if (tries == 3) {
        printf("Sorry, you have exceeded the maximum number of tries. The correct number was %d.", r);
        exit(1);
      } else if (num < 0 || num > 9) {
        printf("Oops! The number must be between 0-9!");
        exit(1);
      } else {
        printf("Wrong again! Try once more.");
      }
    }
  }

  return 0;
}