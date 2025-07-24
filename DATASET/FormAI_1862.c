//FormAI DATASET v1.0 Category: Educational ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int secretNum = 7;
  int guess;
  int guessCount = 0;
  int guessLimit = 3;
  int outOfGuesses = 0;
  
  printf("Welcome to the Guessing Game!\n");
  printf("You have three chances to guess the secret number between 1-10.\n");
  
  while(guess != secretNum && outOfGuesses == 0)
  {
     if(guessCount < guessLimit)
     {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        guessCount++;
     }
     else
     {
        outOfGuesses = 1;
     }
  }
  
  if(outOfGuesses == 1)
  {
     printf("\nOut of guesses. You Lose!\n");
  }
  else
  {
     printf("\nCongratulations! You guessed the secret number.\n");
  }
  
  return 0;
}