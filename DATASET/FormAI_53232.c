//FormAI DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int guess, number, tries = 0;
   srand(time(0));
   number = rand() % 100 + 1; // Generates a random number between 1 and 100

   printf("\n\nWelcome to the Guessing Game!\n");
   printf("You must try to guess a random number between 1 and 100.\n");
   
   // While loop that keeps running until the player guesses the number
   while (guess != number) 
   {
      printf("\nEnter your guess: ");
      scanf("%d", &guess);
      tries++;

      if (guess > number)
      {
         printf("Too high! Try again.\n");
      }
      else if (guess < number)
      {
         printf("Too low! Try again.\n");
      }
      else
      {
         printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
      }
   }

   return 0;
}