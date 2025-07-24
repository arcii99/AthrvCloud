//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void shuffle(int [], int);

int main() {
  // Declaration of variables
  const int deckSize = 52;
  int deck[deckSize];
  char *suits[] = {"hearts", "diamonds", "spades", "clubs"};
  char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
  int numOfPlayers, numOfCards = 5;
  int hand[numOfCards];
  char name[20];
  int i, j, k;

  // Seed random generator
  srand(time(NULL));

  // Create and shuffle the deck of cards
  for (i = 0; i < deckSize; i++) {
    deck[i] = i;
  }
  shuffle(deck, deckSize);

  // Get number of players
  printf("Enter number of players: ");
  scanf("%d", &numOfPlayers);
  printf("\n");

  // Deal cards to all players
  for (i = 0; i < numOfPlayers; i++) {
    printf("Enter player %d's name: ", i+1);
    scanf("%s", name);
    printf("\n%s's hand: ", name);
    for (j = 0; j < numOfCards; j++) {
      hand[j] = deck[j+(numOfCards*i)];
      printf("%s of %s, ", ranks[hand[j]%13], suits[hand[j]/13]);
    }
    printf("\n\n");
  }

  return 0;
}

// Function to shuffle the deck of cards
void shuffle(int deck[], int deckSize) {
  int temp, randomIndex;
  for (int i = 0; i < deckSize; i++) {
    randomIndex = rand()%deckSize;
    temp = deck[i];
    deck[i] = deck[randomIndex];
    deck[randomIndex] = temp;
  }
}