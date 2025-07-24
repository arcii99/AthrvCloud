//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int guess, number, attempts = 1;

   srand(time(0)); // seeding random number generator

   number = rand() % 100; // generating random number

   printf("Guess the number between 0 and 100\n");

   // Loop until user guesses the number
   do
   {
      printf("Enter your guess: ");
      scanf("%d", &guess);

      if (guess < number)
      {
         printf("Too low! Try again.\n");
         attempts++;
      }
      else if (guess > number)
      {
         printf("Too high! Try again.\n");
         attempts++;
      }
      else
      {
         printf("Congratulations! You guessed the number in %d attempts.", attempts);
      }
   } while (guess != number);

   return 0;
}