//FormAI DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int number, guess, nguesses = 1;
  srand(time(0));
  number = rand() % 100 + 1;
  // Generates random number between 1 and 100

  printf("\nWelcome to the Guessing Game!\n");
  printf("\nGuess the number between 1 and 100!\n");

  do
  {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);

    if (guess < number)
      printf("\nToo low, try again!\n");
    else if (guess > number)
      printf("\nToo high, try again!\n");
    else
    {
      printf("\nCongratulations! You have guessed the number in %d attempts.\n", nguesses);
      break;
    }
    nguesses++;

  } while (guess != number);

  return 0;
}