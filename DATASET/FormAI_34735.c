//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20

void initialize_deck(int deck[]) {
  int i;
  for (i = 0; i < MAX_CARDS; i++) {
    deck[i] = i % 10 + 1;
  }
}

void shuffle_deck(int deck[]) {
  int i, j, temp;
  for (i = MAX_CARDS - 1; i > 0; i--) {
    j = rand() % (i + 1);
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void print_deck(int deck[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", deck[i]);
  }
  printf("\n");
}

void play_game(int deck[], int size) {
  int i, player1, player2, score1 = 0, score2 = 0;
  char input1[10], input2[10];
  for (i = 0; i < size; i += 2) {
    printf("Player 1: ");
    scanf("%s", input1);
    player1 = atoi(input1) - 1;
    while (player1 < i || player1 > i + 1) {
      printf("Invalid card selected, please choose again.\n");
      printf("Player 1: ");
      scanf("%s", input1);
      player1 = atoi(input1) - 1;
    }
    score1 += deck[player1];
    printf("Player 2: ");
    scanf("%s", input2);
    player2 = atoi(input2) - 1;
    while (player2 < i || player2 > i + 1) {
      printf("Invalid card selected, please choose again.\n");
      printf("Player 2: ");
      scanf("%s", input2);
      player2 = atoi(input2) - 1;
    }
    score2 += deck[player2];
    printf("\n");
    printf("Current score: Player 1 - %d | Player 2 - %d\n", score1, score2);
    printf("\n");
  }
  printf("-----------------------------\n");
  printf("Final score: Player 1 - %d | Player 2 - %d\n", score1, score2);
  if (score1 > score2) {
    printf("Player 1 wins!\n");
  } else if (score2 > score1) {
    printf("Player 2 wins!\n");
  } else {
    printf("It's a tie!\n");
  }
}

int main() {
  int deck[MAX_CARDS];
  srand(time(0));
  initialize_deck(deck);
  shuffle_deck(deck);
  print_deck(deck, MAX_CARDS);
  play_game(deck, MAX_CARDS);
  return 0;
}