//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, tries = 0;
  srand(time(0));
  num = rand() % 100 + 1;
  printf("\nWelcome to the Guessing Game! I have selected a secret number between 1 and 100, and you have to guess it.\n");
  printf("You have 10 chances to guess the secret number.\n");

  do {
    printf("\nGuess a number: ");
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Too high! Try again.\n\n");
    } else if (guess < num) {
      printf("Too low! Try again.\n\n");
    } else {
      printf("\nCongratulations! You guessed the secret number %d in %d tries.\n", num, tries);
      break;
    }

  } while (tries < 10);

  if (tries == 10) {
    printf("\nSorry, you have used all your chances. The secret number was %d.\n", num);
  }

  return 0;
}