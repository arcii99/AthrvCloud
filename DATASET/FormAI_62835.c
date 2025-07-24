//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, guess, num_guesses = 0;
  srand(time(NULL)); // initialize random number generator
  num = rand() % 100 + 1; // generate random number between 1 and 100
  printf("I'm thinking of a number between 1 and 100. Guess what it is!\n");
  
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    num_guesses++;

    if (guess > num) {
      printf("Lower!\n");
    } else if (guess < num) {
      printf("Higher!\n");
    }

  } while (guess != num);

  printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses);

  return 0;
}