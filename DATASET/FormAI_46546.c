//FormAI DATASET v1.0 Category: Poker Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void shuffleDeck(int deck[]);
int dealCard(int deck[], int *remainingCards);
int calculateHandValue(int hand[], int numCards);

int main () {

   // Initialize the deck of cards
   int deck[52] = {1,2,3,4,5,6,7,8,9,10,10,10,10,
                   1,2,3,4,5,6,7,8,9,10,10,10,10,
                   1,2,3,4,5,6,7,8,9,10,10,10,10,
                   1,2,3,4,5,6,7,8,9,10,10,10,10};

   // Shuffle the deck
   shuffleDeck(deck);

   // Initialize player and dealer hands
   int playerHand[10] = {0};
   int dealerHand[10] = {0};

   // Deal first two cards to player and dealer
   int remainingCards = 52;
   playerHand[0] = dealCard(deck, &remainingCards);
   dealerHand[0] = dealCard(deck, &remainingCards);
   playerHand[1] = dealCard(deck, &remainingCards);
   dealerHand[1] = dealCard(deck, &remainingCards);

   // Display the player's first two cards
   printf("Your hand: %d %d\n", playerHand[0], playerHand[1]);

   // Allow the player to hit or stand
   char hitOrStand;
   do {
      printf("Hit or stand? (h/s): ");
      fflush(stdin);
      scanf("%c", &hitOrStand);

      if (hitOrStand == 'h') {
         playerHand[calculateHandValue(playerHand, 10)] = dealCard(deck, &remainingCards);
         printf("Your hand: ");

         // Display all of the player's cards
         for (int i = 0; i < 10; i++) {
            if (playerHand[i] != 0) printf("%d ", playerHand[i]);
         }
         printf("\n");
      }
   } while (hitOrStand == 'h');

   // Dealer's turn
   int dealerTotal = calculateHandValue(dealerHand, 10);
   while (dealerTotal < 17) {
      dealerHand[dealerTotal] = dealCard(deck, &remainingCards);
      dealerTotal = calculateHandValue(dealerHand, 10);
   }

   // Display the dealer's cards
   printf("Dealer's hand: ");
   for (int i = 0; i < 10; i++) {
      if (dealerHand[i] != 0) printf("%d ", dealerHand[i]);
   }
   printf("\n");

   // Determine the winner
   int playerTotal = calculateHandValue(playerHand, 10);
   if (playerTotal > 21) {
      printf("Bust! You lose.\n");
   }
   else if (dealerTotal > 21) {
      printf("Dealer busts! You win.\n");
   }
   else if (dealerTotal >= playerTotal) {
      printf("Dealer wins.\n");
   }
   else {
      printf("You win.\n");
   }

   return 0;
}

// Function to shuffle the deck of cards
void shuffleDeck(int deck[]) {
   srand(time(NULL));
   for (int i = 0; i < 52; i++) {
      int j = rand() % 52;
      int temp = deck[i];
      deck[i] = deck[j];
      deck[j] = temp;
   }
}

// Function to deal a card from the deck
int dealCard(int deck[], int *remainingCards) {
   int index = 52 - *remainingCards;
   (*remainingCards)--;
   return deck[index];
}

// Function to calculate the hand value
int calculateHandValue(int hand[], int numCards) {
   int total = 0;
   int numAces = 0;
   for (int i = 0; i < numCards; i++) {
      total += hand[i];
      if (hand[i] == 1) {
         numAces++;
      }
   }
   while (numAces > 0 && total < 12) {
      total += 10;
      numAces--;
   }
   return total;
}