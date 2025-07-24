//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
   int n = 0;
   bool is_valid;
   srand(time(0));

   // Main Game Loop
   while (n <= 1000) {
      is_valid = false;

      // Check the input value
      while (!is_valid) { 
         printf("Guess the number (0 - 1000): ");
         scanf("%d", &n);

         if (n < 0 || n > 1000) {
            printf("Invalid input!\n");
         } else {
            is_valid = true;
         }
      }

      // Generate a random number
      int rand_num = rand() % 1000;

      // Calculate the difference between the input and the random number
      int difference = abs(n - rand_num);

      if (difference < 100) {
         printf("Scorching hot! You missed the mark by less than 100.\n");
      } else if (difference < 250) {
         printf("Hot! Your guess is within 250 of the target.\n");
      } else if (difference < 500) {
         printf("Warm. Your guess is within 500 of the target.\n");
      } else if (difference < 1000) {
         printf("Cold. Your guess is within 1000 of the target.\n");
      } else {
         printf("Frozen! Your guess is more than 1000 away from the target.\n");
      }
   }

   printf("Game Over!\n");

   return 0;
}