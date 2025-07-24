//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: multiplayer
#include<stdio.h>

int main() {
   int players, rounds;
   printf("Enter the number of players: ");
   scanf("%d", &players);
   printf("Enter the number of rounds to simulate: ");
   scanf("%d", &rounds);

   int scores[players][rounds]; // 2D array to store scores of players per round.

   printf("Enter the initial scores of players:\n");
   for (int i = 0; i < players; i++) {
      for (int j = 0; j < rounds; j++) {
         scanf("%d", &scores[i][j]);
      }
   }

   printf("Simulation starting...\n");

   for (int j = 0; j < rounds; j++) {
      printf("Round %d\n", j+1);
      for (int i = 0; i < players; i++) {
         int score;
         printf("Player %d, enter your score for this round: ", i+1);
         scanf("%d", &score);
         scores[i][j] += score;
      }
   }

   printf("Simulation complete!\n");

   for (int i = 0; i < players; i++) {
      int total_score = 0;
      for (int j = 0; j < rounds; j++) {
         total_score += scores[i][j];
      }
      printf("Player %d total score: %d\n", i+1, total_score);
   }

   return 0;
}