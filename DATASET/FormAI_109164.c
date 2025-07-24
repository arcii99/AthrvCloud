//FormAI DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome message
  printf("Welcome to the Table Game! Let's get started!\n");

  // Set up and shuffle deck of cards
  int deck[52];
  int i;
  for (i=0; i<52; i++) {
    deck[i] = i+1;
  }
  srand(time(NULL));
  for (i=0; i<52; i++) {
    int j = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  // Deal cards to players
  int player1_total = 0;
  int player1_cards[10];
  int player1_num_cards = 0;
  int player2_total = 0;
  int player2_cards[10];
  int player2_num_cards = 0;
  for (i=0; i<4; i++) {
    if (i%2 == 0) {
      player1_total += deck[i]/4 + 1;
      player1_cards[player1_num_cards] = deck[i];
      player1_num_cards++;
    } else {
      player2_total += deck[i]/4 + 1;
      player2_cards[player2_num_cards] = deck[i];
      player2_num_cards++;
    }
  }

  // Display initial hands
  printf("Player 1's hand: ");
  for (i=0; i<player1_num_cards; i++) {
    printf("%d ", player1_cards[i]);
  }
  printf("\nPlayer 2's hand: ");
  for (i=0; i<player2_num_cards; i++) {
    printf("%d ", player2_cards[i]);
  }
  printf("\n");

  // Player 1's turn
  char response[10];
  while (player1_total <= 21) {
    printf("Player 1, would you like to hit or stay? ");
    scanf("%s", response);
    if (strcmp(response, "hit") == 0) {
      player1_cards[player1_num_cards] = deck[i];
      player1_num_cards++;
      player1_total += deck[i]/4 + 1;
      printf("Player 1's hand: ");
      for (i=0; i<player1_num_cards; i++) {
        printf("%d ", player1_cards[i]);
      }
      printf("\n");
    } else {
      break;
    }
  }

  // Player 2's turn
  while (player2_total <= 21) {
    printf("Player 2, would you like to hit or stay? ");
    scanf("%s", response);
    if (strcmp(response, "hit") == 0) {
      player2_cards[player2_num_cards] = deck[i];
      player2_num_cards++;
      player2_total += deck[i]/4 + 1;
      printf("Player 2's hand: ");
      for (i=0; i<player2_num_cards; i++) {
        printf("%d ", player2_cards[i]);
      }
      printf("\n");
    } else {
      break;
    }
  }

  // Determine winner
  if (player1_total > 21 && player2_total > 21) {
    printf("Both players bust! It's a tie!\n");
  } else if (player1_total > 21) {
    printf("Player 1 busts! Player 2 wins!\n");
  } else if (player2_total > 21) {
    printf("Player 2 busts! Player 1 wins!\n");
  } else if (player1_total > player2_total) {
    printf("Player 1 wins!\n");
  } else if (player2_total > player1_total) {
    printf("Player 2 wins!\n");
  } else {
    printf("It's a tie!\n");
  }

  // End of game message
  printf("Thanks for playing the Table Game! Come back soon!\n");

  return 0;
}