//FormAI DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int number, guess, attempts = 0;
  srand(time(0)); // generates the random seed based on time
  number = rand() % 100 + 1; // generates a random number from 1 to 100

  printf("\nWelcome to the Guessing Game!\n");
  printf("Guess the number between 1 to 100\n");

  do
  {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    attempts++;

    if (guess > number)
    {
      printf("Your guess is too high.\n");
    }
    else if (guess < number)
    {
      printf("Your guess is too low.\n");
    }
    else
    {
      printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
    }
  } while (guess != number);

  return 0;
}