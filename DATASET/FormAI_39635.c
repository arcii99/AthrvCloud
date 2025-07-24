//FormAI DATASET v1.0 Category: Poker Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

void shuffleDeck(int deck[], const int size);
void playPoker(int deck[], const int size, int players[]);

int main() {
  int deck[DECK_SIZE];
  int players[4] = {0, 0, 0, 0};

  srand(time(NULL)); // seed the random number generator

  // initialize the deck
  for (int i = 0; i < DECK_SIZE; i++) {
    deck[i] = i;
  }

  // shuffle the deck
  shuffleDeck(deck, DECK_SIZE);

  // play the game
  playPoker(deck, DECK_SIZE, players);

  return 0;
}

void shuffleDeck(int deck[], const int size) {
  for (int i = 0; i < size; i++) {
    // choose a random index within the deck
    int j = rand() % size;
    // swap the cards at index i and j
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void playPoker(int deck[], const int size, int players[]) {
  // deal the cards
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      players[j] += deck[i+j*5];
    }
  }

  // print each player's hand
  for (int i = 0; i < 4; i++) {
    printf("Player %d's hand:", i+1);
    for (int j = 0; j < 5; j++) {
      int card = (players[i] >> (j * 8)) & 0xff; // extract the card from the player's hand
      printf(" %d", card);
    }
    printf("\n");
  }
}