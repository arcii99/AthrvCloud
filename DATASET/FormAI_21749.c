//FormAI DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_PLAYERS 2
#define MAX_HAND_SIZE 5

enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct card {
  enum suit s;
  enum rank r;
};

typedef struct card Card;

void shuffle(Card *deck);
void print_card(Card c);
void print_hand(Card *hand, int num_cards);
int rank_compare(const void *a, const void *b);

int main(void) {
  Card deck[NUM_CARDS];
  Card player_hands[NUM_PLAYERS][MAX_HAND_SIZE];
  int i, j;

  srand((unsigned) time(NULL));

  // initialize deck of cards
  for (i = 0; i < NUM_SUITS; i++) {
    for (j = 0; j < NUM_RANKS; j++) {
      deck[(NUM_RANKS * i) + j].s = i;
      deck[(NUM_RANKS * i) + j].r = j;
    }
  }

  // shuffle deck
  shuffle(deck);

  // deal hands to players
  for (i = 0; i < NUM_PLAYERS; i++) {
    for (j = 0; j < MAX_HAND_SIZE; j++) {
      player_hands[i][j] = deck[(i * MAX_HAND_SIZE) + j];
    }

    qsort(player_hands[i], MAX_HAND_SIZE, sizeof(Card), rank_compare);

    printf("Player %d's hand: ", i + 1);
    print_hand(player_hands[i], MAX_HAND_SIZE);
    printf("\n");
  }

  return 0;
}

// Fisher-Yates shuffle algorithm
void shuffle(Card *deck) {
  int i, j;
  Card temp;

  for (i = NUM_CARDS - 1; i > 0; i--) {
    j = rand() % (i + 1);

    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void print_card(Card c) {
  switch (c.r) {
    case TWO: printf("2"); break;
    case THREE: printf("3"); break;
    case FOUR: printf("4"); break;
    case FIVE: printf("5"); break;
    case SIX: printf("6"); break;
    case SEVEN: printf("7"); break;
    case EIGHT: printf("8"); break;
    case NINE: printf("9"); break;
    case TEN: printf("10"); break;
    case JACK: printf("J"); break;
    case QUEEN: printf("Q"); break;
    case KING: printf("K"); break;
    case ACE: printf("A"); break;
  }

  switch (c.s) {
    case CLUBS: printf("C"); break;
    case DIAMONDS: printf("D"); break;
    case HEARTS: printf("H"); break;
    case SPADES: printf("S"); break;
  }
}

void print_hand(Card *hand, int num_cards) {
  int i;

  for (i = 0; i < num_cards; i++) {
    print_card(hand[i]);
    printf(" ");
  }
}

int rank_compare(const void *a, const void *b) {
  Card *card_a = (Card *) a;
  Card *card_b = (Card *) b;

  return card_a->r - card_b->r;
}