//FormAI DATASET v1.0 Category: Poker Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

int main()
{
   int deck[NUM_CARDS];
   int suit, rank, card, hand, sum;
   int player_hand[HAND_SIZE];
   char *suit_name[] = {"hearts", "diamonds", "clubs", "spades"};
   char *rank_name[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

   srand(time(NULL)); // Initialize random number generator

   // Initialize deck array with cards
   for (card = 0; card < NUM_CARDS; card++)
      deck[card] = card;

   // Shuffle the deck
   for (card = 0; card < NUM_CARDS; card++) {
      int random_card = rand() % NUM_CARDS;
      int temp = deck[card];
      deck[card] = deck[random_card];
      deck[random_card] = temp;
   }

   // Deal the cards to the player
   for (hand = 0; hand < HAND_SIZE; hand++)
      player_hand[hand] = deck[hand];

   // Display the player's hand
   printf("Your hand:\n");
   for (hand = 0; hand < HAND_SIZE; hand++) {
      suit = player_hand[hand] / NUM_RANKS;
      rank = player_hand[hand] % NUM_RANKS;
      printf("  %s of %s\n", rank_name[rank], suit_name[suit]);
   }

   // Calculate the sum of the ranks in the player's hand
   sum = 0;
   for (hand = 0; hand < HAND_SIZE; hand++) {
      rank = player_hand[hand] % NUM_RANKS;
      if (rank >= 0 && rank <= 8) {
         sum += (rank + 1);
      } else { // Face cards
         sum += 10;
      }
   }

   // Determine the value of the player's hand
   printf("Your hand value is: ");
   if (sum < 21) {
      printf("%d\n", sum);
   } else if (sum == 21) {
      printf("Blackjack!\n");
   } else {
      printf("Busted!\n");
   }

   return 0;
}