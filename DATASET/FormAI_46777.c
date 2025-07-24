//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int number, guess, attempts = 0;
   time_t t;
   srand((unsigned) time(&t));
   number = rand() % 100 + 1; //generates a random number between 1 and 100
   
   printf("Guess a number between 1 and 100:\n");
   
   do {
      scanf("%d", &guess);
      attempts++;
      if (guess > number) {
         printf("Too high! Guess again:\n");
      } else if (guess < number) {
         printf("Too low! Guess again:\n");
      }
   } while (guess != number);
   
   printf("Congratulations! You guessed the number in %d attempts.", attempts);
   
   return 0;
}