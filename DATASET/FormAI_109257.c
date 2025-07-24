//FormAI DATASET v1.0 Category: Poker Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum rank_suit {
  ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
} rank_t;

typedef enum card_suit {
  HEARTS, DIAMONDS, CLUBS, SPADES
} suit_t;

const char* RANK_NAMES[] = {"", "Ace", "Two", "Three", "Four", "Five", "Six",
                            "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char* SUIT_NAMES[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

typedef struct card {
  rank_t rank;
  suit_t suit;
} card_t;

card_t deck[DECK_SIZE];
card_t hand[HAND_SIZE];

void shuffle_deck() {
  int i, j;
  card_t temp;
  srand(time(NULL));
  for (i = 0; i < DECK_SIZE; i++) {
    j = rand() % DECK_SIZE;
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void print_card(card_t* card) {
  printf("%s of %s\n", RANK_NAMES[card->rank], SUIT_NAMES[card->suit]);
}

void create_deck() {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 1; j <= 13; j++) {
      deck[i*13+j-1].rank = j;
      deck[i*13+j-1].suit = i;
    }
  }
}

void deal_hand() {
  int i;
  for (i = 0; i < HAND_SIZE; i++) {
    hand[i] = deck[i];
  }
}

void print_hand() {
  int i;
  for (i = 0; i < HAND_SIZE; i++) {
    printf("%d. ", i+1);
    print_card(&hand[i]);
  }
}

int main() {
  int i;
  create_deck();
  shuffle_deck();
  printf("Welcome to the Poker Game\n");
  printf("Your hand is:\n");
  deal_hand();
  print_hand();
  return 0;
}