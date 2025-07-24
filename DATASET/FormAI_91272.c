//FormAI DATASET v1.0 Category: Poker Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {
  char suit;
  int value;
};

void shuffle(struct card deck[], int n) {
  srand(time(NULL));
  int i, j;
  struct card temp;
  for (i = n - 1; i > 0; i--) {
    j = rand() % (i + 1);
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void deal(struct card deck[], int n, struct card *player1, struct card *player2) {
  int i;
  for (i = 0; i < n / 2; i++) {
    player1[i] = deck[i];
    player2[i] = deck[i + n / 2];
  }
}

int compare(struct card hand1[], struct card hand2[], int size) {
  // add your code to compare the two hands and determine the winner
}

int main() {
  struct card deck[52] = {
    {'H', 2}, {'H', 3}, {'H', 4}, /* ... and so on */ {'S', 'A'}
  };
  struct card player1[5], player2[5];
  shuffle(deck, 52);
  deal(deck, 52, player1, player2);
  printf("Player 1: \n");
  // add your code to print out each card in player1's hand
  printf("Player 2: \n");
  // add your code to print out each card in player2's hand
  int winner = compare(player1, player2, 5);
  if (winner == 1) {
    printf("Player 1 wins!\n");
  } else if (winner == 2) {
    printf("Player 2 wins!\n");
  } else {
    printf("It's a tie!\n");
  }
  return 0;
}