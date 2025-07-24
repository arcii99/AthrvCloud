//FormAI DATASET v1.0 Category: Poker Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int HAND_SIZE = 5;
const int NUM_RANKS = 13;
const int NUM_SUITS = 4;

typedef enum suit {
  CLUBS,
  DIAMONDS,
  HEARTS,
  SPADES
} Suit;

typedef enum value {
  ACE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
} Value;

typedef struct card {
  Suit suit;
  Value value;
} Card;

void print_card(Card x) {
  switch (x.value) {
    case ACE:
      printf("A");
      break;
    case TWO:
      printf("2");
      break;
    case THREE:
      printf("3");
      break;
    case FOUR:
      printf("4");
      break;
    case FIVE:
      printf("5");
      break;
    case SIX:
      printf("6");
      break;
    case SEVEN:
      printf("7");
      break;
    case EIGHT:
      printf("8");
      break;
    case NINE:
      printf("9");
      break;
    case TEN:
      printf("10");
      break;
    case JACK:
      printf("J");
      break;
    case QUEEN:
      printf("Q");
      break;
    case KING:
      printf("K");
      break;
    default:
      printf("Invalid value.\n");
      exit(EXIT_FAILURE);
      break;
  }

  switch (x.suit) {
    case CLUBS:
      printf("C ");
      break;
    case DIAMONDS:
      printf("D ");
      break;
    case HEARTS:
      printf("H ");
      break;
    case SPADES:
      printf("S ");
      break;
    default:
      printf("Invalid suit.\n");
      exit(EXIT_FAILURE);
      break;
  }
}

void print_hand(Card hand[HAND_SIZE]) {
  for (int i = 0; i < HAND_SIZE; i++) {
    print_card(hand[i]);
    printf(" ");
  }
  printf("\n");
}

void shuffle_deck(Card deck[NUM_RANKS][NUM_SUITS]) {
  srand(time(NULL));
  for (int i = 0; i < NUM_RANKS; i++) {
    for (int j = 0; j < NUM_SUITS; j++) {
      int r = rand() % NUM_RANKS;
      int s = rand() % NUM_SUITS;
      Card temp = deck[i][j];
      deck[i][j] = deck[r][s];
      deck[r][s] = temp;
    }
  }
}

int main(int argc, char* argv[]) {
  Card deck[NUM_RANKS][NUM_SUITS];
  int num_players = 0;

  // Initialize deck
  for (int i = 0; i < NUM_RANKS; i++) {
    for (int j = 0; j < NUM_SUITS; j++) {
      deck[i][j].value = i;
      deck[i][j].suit = j;
    }
  }

  printf("Welcome to C Poker Game!\n");

  // Input number of players
  do {
    printf("Enter the number of players (2-10): ");
    fflush(stdout);
    scanf("%d", &num_players);
  } while (num_players < 2 || num_players > 10);

  printf("Dealing %d hands...\n", num_players);
  shuffle_deck(deck);

  // Deal hands
  for (int i = 0; i < num_players; i++) {
    Card hand[HAND_SIZE];
    for (int j = 0; j < HAND_SIZE; j++) {
      hand[j] = deck[NUM_RANKS - j - 1][i];
    }
    printf("Hand %d: ", i + 1);
    print_hand(hand);
  }

  return 0;
}