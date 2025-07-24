//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int randomNumber, guess, tryCount = 0;

   // Get current time as seed for random number generator
   srand(time(NULL));
   
   // Generate a random number between 1 and 100
   randomNumber = rand() % 100 + 1;
   
   printf("Let's play a guessing game! I'm thinking of a number between 1 and 100.\n");

   do
   {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      tryCount++;

      if (guess > randomNumber)
      {
         printf("Too high! Try again.\n");
      }
      else if (guess < randomNumber)
      {
         printf("Too low! Try again.\n");
      }
      else
      {
         printf("Congratulations! You guessed the number in %d tries.\n", tryCount);
      }
   } while (guess != randomNumber);

   return 0;
}