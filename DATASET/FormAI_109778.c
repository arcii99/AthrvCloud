//FormAI DATASET v1.0 Category: Poker Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char suits[4][10] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  char ranks[13][10] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

  int deck[52];
  int i, j;
  srand(time(NULL));
  
  // Create the deck
  for(i=0; i<52; i++) {
    deck[i] = i;
  }

  // Shuffle the deck
  for(i=0; i<52; i++) {
    int j = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  // Print the shuffled deck
  printf("Shuffled Deck:\n\n");
  for(i=0; i<52; i++) {
    printf("%s of %s\n", ranks[deck[i] % 13], suits[deck[i] / 13]);
  }

  return 0;
}