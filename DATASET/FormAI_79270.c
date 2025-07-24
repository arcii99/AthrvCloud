//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int randomNumber, guess, attempts = 0;
  srand(time(NULL)); // The srand() function sets the starting point for generating random numbers.

  randomNumber = rand() % 101; // Generate a random number between 0 and 100.

  printf("I have chosen a number between 0 and 100. Try to guess it!\n");

  do {
    printf("Guess #%d: ", attempts + 1);
    scanf("%d", &guess); // Get the user's guess.

    attempts++; // Increase the number of attempts.

    if (guess == randomNumber) {
      printf("Congratulations, you win! You guessed the number in %d attempts.\n", attempts);
    } else {
      if (guess < randomNumber) {
        printf("Too low, try again.\n");
      } else {
        printf("Too high, try again.\n");
      }
    }
  } while (guess != randomNumber);

  return 0;
}