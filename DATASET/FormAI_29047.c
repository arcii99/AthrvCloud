//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int i, num, guess, tries = 0;
  srand(time(0)); //seed random number generator
  num = rand() % 100 + 1; // random number between 1 and 100
  printf("Welcome to the Guess the Number game!\n");
  printf("Guess a number between 1 and 100\n");
  do
  {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;
    // check if guess is higher or lower than the random number
    if (guess > num)
    {
      printf("Too high! Try again.\n");
    }
    else if (guess < num)
    {
      printf("Too low! Try again.\n");
    }
    else
    {
      printf("Congratulations! You guessed the number in %d tries.\n", tries);
    }
  } while (guess != num);
  return 0;
}