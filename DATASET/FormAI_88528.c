//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // initialize random seed

  int secret_num = rand() % 100; // generate random number between 0 and 99

  int guess, num_guesses = 0; // initialize guess and number of guesses

  printf("Welcome to Guess the Number!\n\n");

  do {
    printf("Guess a number between 0 and 99: ");
    scanf("%d", &guess);
    num_guesses++; // increment number of guesses

    if (guess > secret_num) {
      printf("Too high!\n\n");
    } else if (guess < secret_num) {
      printf("Too low!\n\n");
    } else {
      printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);
    }
  } while (guess != secret_num);

  return 0;
}