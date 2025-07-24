//FormAI DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print card suit and value
void printCard(int card) {
  int suit = card / 13;
  int value = card % 13;

  switch(suit) {
    case 0:
      printf("Hearts ");
      break;
    case 1:
      printf("Diamonds ");
      break;
    case 2:
      printf("Clubs ");
      break;
    case 3:
      printf("Spades ");
      break;
  }

  switch(value) {
    case 0:
      printf("Ace\n");
      break;
    case 10:
      printf("Jack\n");
      break;
    case 11:
      printf("Queen\n");
      break;
    case 12:
      printf("King\n");
      break;
    default:
      printf("%d\n", value + 1);
      break;
  }
}

int main() {
  srand(time(0)); // set seed for random number generator

  int deck[52]; // initialize deck array
  int i, j;

  // populate deck with values from 0 to 51
  for(i = 0; i < 52; i++) {
    deck[i] = i;
  }

  // shuffle deck
  for(i = 0; i < 52; i++) {
    int j = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  // deal cards
  int hand[5];
  for(i = 0; i < 5; i++) {
    hand[i] = deck[i];
    printf("Card %d: ", i + 1);
    printCard(hand[i]);
  }

  return 0;
}