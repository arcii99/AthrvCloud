//FormAI DATASET v1.0 Category: Random ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num, guess, attempts = 0;
   srand(time(0));
   num = rand() % 100 + 1;

   printf("*** Welcome to the Random Number Game! ***\n\n");
   printf("I am thinking of a number between 1 and 100.\n");
   printf("Can you guess what it is?\n");

   do {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      attempts++;

      if (guess > num) {
         printf("Lower!\n");
      } else if (guess < num) {
         printf("Higher!\n");
      } else {
         printf("\nCongratulations! You guessed it in %d attempts!\n", attempts);
      }
   } while (guess != num);

   printf("\nThank you for playing!\n\n");
   return 0;
}