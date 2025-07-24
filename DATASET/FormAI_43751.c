//FormAI DATASET v1.0 Category: Poker Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

typedef struct {
   int value;
   char name[3];
   char suit[9];
} Card;

void print_card(Card card) {
   printf("%s of %s\n", card.name, card.suit);
}

void print_hand(Card hand[], int size) {
   for (int i = 0; i < size; i++) {
      print_card(hand[i]);
   }
}

int main() {
   srand(time(NULL)); // seed the random number generator
   Card deck[NUM_CARDS];
   Card player_hand[2];
   Card computer_hand[2];
   int used[NUM_CARDS] = {0}; // keep track of used cards
   int count = 0; // count of used cards
   int choice;
   int player = 0; // 0 for player, 1 for computer
   int player_score = 0;
   int computer_score = 0;

   // initialize the deck
   for (int i = 0; i < NUM_SUITS; i++) {
      for (int j = 0; j < NUM_RANKS; j++) {
         deck[i*NUM_RANKS+j].value = j+1;
         sprintf(deck[i*NUM_RANKS+j].name, "%d", j+1);
         switch (i) {
            case 0:
               sprintf(deck[i*NUM_RANKS+j].suit, "Clubs");
               break;
            case 1:
               sprintf(deck[i*NUM_RANKS+j].suit, "Diamonds");
               break;
            case 2:
               sprintf(deck[i*NUM_RANKS+j].suit, "Hearts");
               break;
            case 3:
               sprintf(deck[i*NUM_RANKS+j].suit, "Spades");
               break;
         }
      }
   }

   // shuffle the deck
   while (count < NUM_CARDS) {
      int card = rand() % NUM_CARDS;
      if (!used[card]) {
         used[card] = 1;
         count++;
      }
   }
   count = 0;

   // deal cards
   player_hand[0] = deck[count++];
   computer_hand[0] = deck[count++];
   player_hand[1] = deck[count++];
   computer_hand[1] = deck[count++];

   // show cards
   printf("Your hand:\n");
   print_hand(player_hand, 2);
   printf("\nComputer's hand:\n");
   print_card(computer_hand[0]);
   printf("<hidden card>\n");

   // player's turn
   printf("\nWhat is your move?\n");
   printf("1. Hit\n");
   printf("2. Stand\n");
   scanf("%d", &choice);
   while (choice != 2) {
      if (choice == 1) {
         player_hand[2] = deck[count++];
         printf("You drew:\n");
         print_card(player_hand[2]);
         printf("Your hand is now:\n");
         print_hand(player_hand, 3);
      } else {
         printf("Invalid choice.\n");
      }
      printf("\nWhat is your move?\n");
      printf("1. Hit\n");
      printf("2. Stand\n");
      scanf("%d", &choice);
   }

   // computer's turn
   printf("\nComputer's turn:\n");
   while (computer_score < 17) {
      computer_hand[2] = deck[count++];
      printf("Computer drew:\n");
      print_card(computer_hand[2]);
      computer_score += computer_hand[2].value;
      printf("Computer's score is now %d.\n", computer_score);
   }

   // determine winner
   player_score = player_hand[0].value + player_hand[1].value;
   if (player_score <= 21 && player_score > computer_score || computer_score > 21) {
      printf("\nYou win!\n");
   } else {
      printf("\nComputer wins!\n");
   }

   return 0;
}