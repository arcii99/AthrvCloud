//FormAI DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, num, count = 0;
  srand(time(0)); // seed for random number generator
  num = rand() % 100 + 1; // generating a random number between 1 to 100
  printf("Welcome to the Number Guessing Game! \n");
  printf("Guess a number between 1 to 100: ");
  do {
    scanf("%d", &guess);
    count++; //counting the number of guesses
    if (guess > num)
      printf("Too high! Guess again: ");
    else if (guess < num)
      printf("Too low! Guess again: ");
    else
      printf("Congratulations! You have guessed the right number in %d attempts. \n", count);
  } while (guess != num);
  return 0;
}