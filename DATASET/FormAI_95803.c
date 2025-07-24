//FormAI DATASET v1.0 Category: Random ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int random_num, guess, tries = 0, max_tries = 10;
  srand(time(0)); // seedrng the random number generator

  random_num = rand() % 100 + 1; // generate the random number between 1 and 100
  printf("Welcome to the Guessing Game! I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

  do {
    printf("Enter your guess (attempt %d of %d): ", tries+1, max_tries);
    scanf("%d", &guess);

    if (guess < random_num)
      printf("Too low! Guess higher.\n");
    else if (guess > random_num)
      printf("Too high! Guess lower.\n");
    else {
      printf("Congratulations! You guessed the right number in %d attempt(s)!\n", tries+1);
      break;
    }

    tries++;
  } while (tries < max_tries);

  if (tries == max_tries)
    printf("Sorry, you didn't guess the number in %d attempts. The number was %d.\n", max_tries, random_num);

  return 0;
}