//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));
   int num = rand() % 100;
   printf("Welcome to the surreal guessing game!\n");
   printf("The random number is: %d\n", num);
   printf("Try to guess the number...\n");

   int guess = 0;
   int count = 0;
   while (guess != num) {
      printf("Enter your guess: ");
      scanf("%d", &guess);
      if (guess < 0 || guess > 100) {
         printf("Invalid guess. Try again.\n");
         continue;
      }
      count++;
      if (guess == num) {
         printf("\n\nYou have won the game!\n");
         printf("It only took you %d tries!\n", count);
         printf("Congratulations! You can now exit your mind.\n");
      }
      else {
         printf("Sorry, that is not the number.\n");
         if (count == 3) {
            printf("\n\nYou have failed the game!\n");
            printf("You have 2 more tries to escape the labyrinth of the unconscious.\n");
         }
         else if (count == 5) {
            printf("\n\nYou have failed the game!\n");
            printf("You have 1 more try to return to the waking world.\n");
         }
         else if (count == 7) {
            printf("\n\nYou have failed the game!\n");
            printf("You are now trapped in the dream world forever.\n");
            printf("But don't worry, it's a fun place to be!\n");
            printf("Until next time!\n");
            break;
         }
      }
   }

   return 0;
}