//FormAI DATASET v1.0 Category: Poker Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
  int value;
  char suit;
} Card;

void shuffle_deck(Card *deck) {
  for (int i = 0; i < DECK_SIZE; i++) {
    int j = rand() % DECK_SIZE;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void print_card(Card card) {
  char str_value[3];
  if (card.value == 1) {
    str_value[0] = 'A';
    str_value[1] = '\0';
  } else if (card.value <= 10) {
    sprintf(str_value, "%d", card.value);
  } else if (card.value == 11) {
    str_value[0] = 'J';
    str_value[1] = '\0';
  } else if (card.value == 12) {
    str_value[0] = 'Q';
    str_value[1] = '\0';
  } else if (card.value == 13) {
    str_value[0] = 'K';
    str_value[1] = '\0';
  }
  printf("%s%c ", str_value, card.suit);
}

void print_cards(Card *cards, int num_cards) {
  for (int i = 0; i < num_cards; i++) {
    print_card(cards[i]);
  }
}

int is_flush(Card *cards) {
  char suit = cards[0].suit;
  for (int i = 1; i < HAND_SIZE; i++) {
    if (cards[i].suit != suit) {
      return 0;
    }
  }
  return 1;
}

int is_straight(Card *cards) {
  for (int i = 0; i < HAND_SIZE - 1; i++) {
    if (cards[i].value != cards[i+1].value - 1) {
      return 0;
    }
  }
  return 1;
}

int is_straight_flush(Card *cards) {
  return is_flush(cards) && is_straight(cards);
}

int is_four_of_a_kind(Card *cards) {
  if (cards[0].value == cards[3].value || cards[1].value == cards[4].value) {
    return 1;
  }
  return 0;
}

int is_full_house(Card *cards) {
  if (cards[0].value == cards[1].value &&
      cards[2].value == cards[4].value) {
    return 1;
  }
  if (cards[0].value == cards[2].value &&
      cards[3].value == cards[4].value) {
    return 1;
  }
  return 0;
}

int is_three_of_a_kind(Card *cards) {
  if (cards[0].value == cards[2].value ||
      cards[1].value == cards[3].value ||
      cards[2].value == cards[4].value) {
    return 1;
  }
  return 0;
}

int is_two_pair(Card *cards) {
  if (cards[0].value == cards[1].value &&
      cards[2].value == cards[3].value) {
    return 1;
  }
  if (cards[0].value == cards[1].value &&
      cards[3].value == cards[4].value) {
    return 1;
  }
  if (cards[1].value == cards[2].value &&
      cards[3].value == cards[4].value) {
    return 1;
  }
  return 0;
}

int is_one_pair(Card *cards) {
  for (int i = 0; i < HAND_SIZE - 1; i++) {
    if (cards[i].value == cards[i+1].value) {
      return 1;
    }
  }
  return 0;
}

void draw_cards(Card *deck, Card *hand) {
  for (int i = 0; i < HAND_SIZE; i++) {
    hand[i] = deck[i];
  }
}

int main() {
  srand(time(NULL));
  Card deck[DECK_SIZE] = {
    {1, 'H'}, {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'},
    {1, 'D'}, {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'},
    {1, 'C'}, {2, 'C'}, {3, 'C'}, {4, 'C'}, {5, 'C'}, {6, 'C'}, {7, 'C'}, {8, 'C'}, {9, 'C'}, {10, 'C'}, {11, 'C'}, {12, 'C'}, {13, 'C'},
    {1, 'S'}, {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'}
  };
  Card hand[HAND_SIZE];
  shuffle_deck(deck);
  draw_cards(deck, hand);
  printf("Your hand: ");
  print_cards(hand, HAND_SIZE);
  printf("\n");
  if (is_straight_flush(hand)) {
    printf("You have a straight flush!\n");
  } else if (is_four_of_a_kind(hand)) {
    printf("You have four of a kind!\n");
  } else if (is_full_house(hand)) {
    printf("You have a full house!\n");
  } else if (is_flush(hand)) {
    printf("You have a flush!\n");
  } else if (is_straight(hand)) {
    printf("You have a straight!\n");
  } else if (is_three_of_a_kind(hand)) {
    printf("You have three of a kind!\n");
  } else if (is_two_pair(hand)) {
    printf("You have two pairs!\n");
  } else if (is_one_pair(hand)) {
    printf("You have one pair!\n");
  } else {
    printf("You have nothing.\n");
  }
  return 0;
}