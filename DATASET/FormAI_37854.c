//FormAI DATASET v1.0 Category: Poker Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *cards[] = {"Ace", "2", "3", "4", "5", "6",
                   "7", "8", "9", "10", "Jack", "Queen",
                   "King"}; // array of 13 cards
  char *suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"}; // array of 4 suits
  int deck[52]; // array of 52 cards
  int index = 0, choice = 0;

  srand(time(NULL)); // seed the random number generator

  // initialize the deck
  for (int i = 0; i < 52; i++){
    deck[i] = i;
  }

  // shuffle the deck
  for (int i = 0; i < 52; i++){
    int j = rand() % 52;
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }

  printf("\nWelcome to the hilarious game of C Poker!\n");

  do {
    printf("\nChoose a card from the deck:\n");
    for (int i = 0; i < 52; i++) {
      if (deck[i] != -1) {
        printf("%d. %s of %s\n", i+1, cards[deck[i]%13], suits[deck[i]/13]);
      }
    }
    scanf("%d", &choice);

    if (choice < 1 || choice > 52) {
      printf("Invalid choice. Try again.\n");
      continue;
    }

    if (deck[choice-1] == -1) {
      printf("You already chose that card. Try again.\n");
      continue;
    }

    printf("You chose the %s of %s\n", cards[deck[choice-1]%13], suits[deck[choice-1]/13]);
    deck[choice-1] = -1;

    index++;

  } while (index < 5);

  printf("\nCongratulations! You successfully played C Poker and won nothing!\n");

  return 0;
}