//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int num, guess, tries = 0;

   // Generate a random number
   srand(time(0)); 
   num = rand() % 100 + 1;
   
   printf("\nWelcome to 'Guess the Number' game!\n");
   printf("I am thinking of a number between 1 and 100.\n");
   
   // Keep asking the user to guess until they get it right
   do
   {
      printf("\nEnter your guess: ");
      scanf("%d", &guess);
      tries++;

      if (guess > num)
         printf("Sorry, that's too high. Try again.");
      else if (guess < num)
         printf("Sorry, that's too low. Try again.");
      else
         printf("\nCongratulations! You got it in %d tries!\n", tries);

   } while (guess != num);
   
   printf("\nThank you for playing!\n");
   
   return 0;
}