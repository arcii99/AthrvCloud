//FormAI DATASET v1.0 Category: Poker Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_SIZE 5
#define CARD_TYPES 13
#define SUIT_TYPES 4

char *card_types[CARD_TYPES] = {"2", "3", "4", "5", "6", "7", "8", "9", "10",
                                "J", "Q", "K", "A"};
char *suit_types[SUIT_TYPES] = {"Hearts", "Diamonds", "Clubs", "Spades"};

char *get_card_name(int card_value) {
  int card_type = card_value % CARD_TYPES;
  int suit_type = card_value / CARD_TYPES;
  static char card_name[3];
  sprintf(card_name, "%s%c", card_types[card_type], suit_types[suit_type][0]);
  return card_name;
}

void shuffle_deck(int deck[]) {
  int i, j, temp;

  for (i = CARD_TYPES * SUIT_TYPES - 1; i > 0; i--) {
    j = rand() % (i + 1);
    temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void deal_hand(int deck[], int hand[]) {
  int i;

  for (i = 0; i < HAND_SIZE; i++) {
    hand[i] = deck[i];
  }
}

int get_card_value(int card_value) {
  int card_type = card_value % CARD_TYPES;
  int suit_type = card_value / CARD_TYPES;

  if (card_type >= 0 && card_type <= 8) {
    return card_type + 2;
  } else if (card_type >= 9 && card_type <= 11) {
    return 10;
  } else {  // Ace
    return 11;
  }
}

int evaluate_hand(int hand[]) {
  int i, sum = 0, num_aces = 0;

  for (i = 0; i < HAND_SIZE; i++) {
    sum += get_card_value(hand[i]);

    if (get_card_value(hand[i]) == 11) {
      num_aces++;
    }
  }

  while (sum > 21 && num_aces > 0) {
    sum -= 10;
    num_aces--;
  }

  return sum;
}

void print_hand(int hand[]) {
  int i;

  for (i = 0; i < HAND_SIZE; i++) {
    printf("%s ", get_card_name(hand[i]));
  }
}

int main() {
  int deck[CARD_TYPES * SUIT_TYPES];
  int hand[HAND_SIZE];
  int i;

  srand(time(NULL));

  for (i = 0; i < CARD_TYPES * SUIT_TYPES; i++) {
    deck[i] = i;
  }

  shuffle_deck(deck);
  deal_hand(deck, hand);

  printf("Your hand:\n");
  print_hand(hand);
  printf("\n");

  int hand_value = evaluate_hand(hand);
  printf("Hand value: %d\n", hand_value);

  return 0;
}