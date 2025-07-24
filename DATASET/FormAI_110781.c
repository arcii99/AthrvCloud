//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int num, guess, tries = 0;
  srand(time(0));  // Initialization, should only be called once.

  num = rand() % 100 + 1;  // Generate random number between 1 and 100

  printf("\nGuess My Number Game\n");

  do {
    printf("Enter a guess between 1 and 100 : ");
    scanf("%d", &guess);
    tries++;

    if (guess > num) {
      printf("Too high!\n\n");
    } else if (guess < num) {
      printf("Too low!\n\n");
    } else {
      printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
    }

  } while (guess != num);

  return 0;
}