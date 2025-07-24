//FormAI DATASET v1.0 Category: Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); // Seed the random number generator with current time

  printf("Welcome to the Number Guessing Game!\n");

  int secret_num = rand() % 100 + 1; // Generate random number between 1 and 100
  int guess, num_guesses = 0;

  do
  {
    printf("Guess a number between 1 and 100: ");
    scanf("%d", &guess);

    if (guess > secret_num)
    {
      printf("Too high!\n");
    }
    else if (guess < secret_num)
    {
      printf("Too low!\n");
    }

    num_guesses++;
  } while (guess != secret_num);

  printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);

  return 0;
}