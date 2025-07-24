//FormAI DATASET v1.0 Category: Random ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  // Declare variables
  int number, guess, tries = 0;

  // Seed the random number generator
  srand(time(0));

  // Generate a random number between 1 and 100
  number = rand() % 100 + 1;

  // Welcome the user to the game
  printf("Welcome to the Random Number Guessing Game!\n");
  printf("I'm thinking of a number between 1 and 100.\n");

  do
  {
    // Ask the user for their guess
    printf("Guess the number: ");
    scanf("%d", &guess);

    // Increment the number of tries
    tries++;

    if (guess < number)
    {
      printf("Too low! Try again.\n");
    }
    else if (guess > number)
    {
      printf("Too high! Try again.\n");
    }
    else
    {
      printf("Congratulations! You guessed the number in %d tries.\n", tries);
    }
  } while (guess != number);

  return 0;
}