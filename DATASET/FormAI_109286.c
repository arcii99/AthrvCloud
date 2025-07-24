//FormAI DATASET v1.0 Category: Poker Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

struct card {
   char* name;
   int value;
};

typedef struct card Card;

void shuffle(Card* deck);
void printDeck(Card* deck);
void dealCards(Card* deck, int num_players);
int scoreHand(Card hand[]);

int main() {
   // initialize deck
   Card deck[DECK_SIZE] = { 
      {"Ace of Hearts", 11}, {"2 of Hearts", 2}, {"3 of Hearts", 3},
      {"4 of Hearts", 4}, {"5 of Hearts", 5}, {"6 of Hearts", 6},
      {"7 of Hearts", 7}, {"8 of Hearts", 8}, {"9 of Hearts", 9},
      {"10 of Hearts", 10}, {"Jack of Hearts", 10}, {"Queen of Hearts", 10},
      {"King of Hearts", 10}, {"Ace of Spades", 11}, {"2 of Spades", 2},
      {"3 of Spades", 3}, {"4 of Spades", 4}, {"5 of Spades", 5},
      {"6 of Spades", 6}, {"7 of Spades", 7}, {"8 of Spades", 8},
      {"9 of Spades", 9}, {"10 of Spades", 10}, {"Jack of Spades", 10},
      {"Queen of Spades", 10}, {"King of Spades", 10}, {"Ace of Clubs", 11},
      {"2 of Clubs", 2}, {"3 of Clubs", 3}, {"4 of Clubs", 4},
      {"5 of Clubs", 5}, {"6 of Clubs", 6}, {"7 of Clubs", 7},
      {"8 of Clubs", 8}, {"9 of Clubs", 9}, {"10 of Clubs", 10},
      {"Jack of Clubs", 10}, {"Queen of Clubs", 10}, {"King of Clubs", 10},
      {"Ace of Diamonds", 11}, {"2 of Diamonds", 2}, {"3 of Diamonds", 3},
      {"4 of Diamonds", 4}, {"5 of Diamonds", 5}, {"6 of Diamonds", 6},
      {"7 of Diamonds", 7}, {"8 of Diamonds", 8}, {"9 of Diamonds", 9},
      {"10 of Diamonds", 10}, {"Jack of Diamonds", 10},
      {"Queen of Diamonds", 10}, {"King of Diamonds", 10}
   };
   
   // seed random number generator for shuffling
   srand(time(NULL));
   
   // shuffle deck
   shuffle(deck);
   
   // deal cards to players
   int num_players = 2;
   dealCards(deck, num_players);
   
   return 0;
}

// shuffles the deck of cards
void shuffle(Card* deck) {
   int i, j;
   Card temp;
   for (i = DECK_SIZE - 1; i > 0; i--) {
      j = rand() % (i + 1);
      temp = deck[j];
      deck[j] = deck[i];
      deck[i] = temp;
   }
}

// prints out the cards in the deck
void printDeck(Card* deck) {
   int i;
   for (i = 0; i < DECK_SIZE; i++) {
      printf("%s\n", deck[i].name);
   }
}

// deals cards to players and determines the winner
void dealCards(Card* deck, int num_players) {
   int i, j;
   Card hands[num_players][2];
   // deal cards to each player
   for (i = 0; i < num_players; i++) {
      for (j = 0; j < 2; j++) {
         hands[i][j] = deck[i * 2 + j];
      }
   }
   // print out each player's hand
   for (i = 0; i < num_players; i++) {
      printf("Player %d's hand:\n", i + 1);
      printf("%s\n", hands[i][0].name);
      printf("%s\n", hands[i][1].name);
      printf("Total score: %d\n", scoreHand(hands[i]));
   }
}

// calculates the score of a hand of cards
int scoreHand(Card hand[]) {
   int i, score = 0;
   for (i = 0; i < 2; i++) {
      score += hand[i].value;
   }
   return score;
}