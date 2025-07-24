//FormAI DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int secret_num, guess, num_attempts = 0;
  srand(time(NULL));
  secret_num = rand() % 100 + 1;

  printf("*** Welcome to the Guessing Game! ***\n");
  printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    num_attempts++;

    if (guess < secret_num) {
      printf("Too low! Try again.\n");
    } else if (guess > secret_num) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed it in %d attempts.\n", num_attempts);
    }
  } while (guess != secret_num);

  return 0;
}