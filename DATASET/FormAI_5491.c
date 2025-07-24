//FormAI DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   printf("Welcome to the Poker Game!\n");

   // Initialize random seed
   srand(time(NULL));

   // Set up deck of cards
   const char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
   const char* suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
   int deck[52];
   for (int i = 0; i < 52; i++) {
      deck[i] = i;
   }

   // Shuffle deck
   for (int i = 51; i > 0; i--) {
      int j = rand() % (i + 1);
      int temp = deck[i];
      deck[i] = deck[j];
      deck[j] = temp;
   }

   // Deal cards
   int num_players = 5;
   int hand_size = 5;
   int hands[num_players][hand_size];
   for (int i = 0; i < hand_size; i++) {
      for (int j = 0; j < num_players; j++) {
         hands[j][i] = deck[i*num_players + j];
      }
   }

   // Display hands
   for (int i = 0; i < num_players; i++) {
      printf("Player %d's hand:\n", i+1);
      for (int j = 0; j < hand_size; j++) {
         int card = hands[i][j];
         const char* rank = ranks[card%13];
         const char* suit = suits[card/13];
         printf("%s of %s\n", rank, suit);
      }
      printf("\n");
   }

   // Determine winner
   int winner = 0;
   int max_score = 0;
   for (int i = 0; i < num_players; i++) {
      int score = 0;
      for (int j = 0; j < hand_size; j++) {
         int card = hands[i][j];
         score += (card % 13) + 1;
      }
      if (score > max_score) {
         max_score = score;
         winner = i;
      }
   }

   printf("Player %d wins with a score of %d!\n", winner+1, max_score);

   return 0;
}