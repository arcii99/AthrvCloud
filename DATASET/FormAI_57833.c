//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num_players, i, num_guesses;

   printf("Welcome to the Guessing Game! How many players are there?\n");
   scanf("%d", &num_players);

   /* Error handling for invalid number of players */
   if (num_players < 1) {
      printf("Sorry, there must be at least 1 player. Please try again.\n");
      exit(1);
   }

   int* guesses[num_players];

   for (i = 0; i < num_players; i++) {
      printf("Player %d: How many guesses would you like to make?\n", i+1);
      scanf("%d", &num_guesses);

      /* Error handling for invalid number of guesses */
      if (num_guesses < 1) {
         printf("Sorry, you must make at least 1 guess. Please try again.\n");
         exit(1);
      }

      guesses[i] = malloc(sizeof(int) * num_guesses);

      printf("Player %d: Please enter your %d guesses, separated by spaces.\n", i+1, num_guesses);
      int j;
      for (j = 0; j < num_guesses; j++) {
         scanf("%d", &guesses[i][j]);

         /* Error handling for invalid guess */
         if (guesses[i][j] < 1 || guesses[i][j] > 100) {
            printf("Sorry, your guess must be between 1 and 100. Please try again.\n");
            exit(1);
         }
      }
   }

   /* Game logic goes here */

   return 0;
}