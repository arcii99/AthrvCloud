//FormAI DATASET v1.0 Category: Poker Game ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

// Define struct for a card
struct Card {
  const char *rank;
  const char *suit;
};

// Declare variables
char *ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six",
                 "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
struct Card deck[NUM_CARDS];
bool used[NUM_CARDS] = {false};
int player_score = 0;
int computer_score = 0;

// Declare functions
void initialize_deck();
void shuffle_deck();
int get_card_value(struct Card card);
void deal_player_card();
void deal_computer_card();
void display_player_hand();
void display_computer_hand();
void display_player_score();
void display_computer_score();
void display_game_result();
bool check_game_over();

int main() {
  srand(time(NULL));
  initialize_deck();
  shuffle_deck();

  while (!check_game_over()) {
    deal_player_card();
    deal_computer_card();
    display_player_hand();
    display_computer_hand();
    display_player_score();
  }
  display_game_result();
  return 0;
}

void initialize_deck() {
  for (int i = 0; i < NUM_RANKS; i++) {
    for (int j = 0; j < NUM_SUITS; j++) {
      deck[i*NUM_SUITS+j].rank = ranks[i];
      deck[i*NUM_SUITS+j].suit = suits[j];
    }
  }
}

void shuffle_deck() {
  for (int i = 0; i < NUM_CARDS; i++) {
    int swap_index = rand() % NUM_CARDS;
    struct Card temp = deck[i];
    deck[i] = deck[swap_index];
    deck[swap_index] = temp;
  }
}

int get_card_value(struct Card card) {
  if (card.rank == "Ace") {
    return 11;
  } else if (card.rank == "King" || card.rank == "Queen" || card.rank == "Jack") {
    return 10;
  } else {
    return atoi(card.rank);
  }
}

void deal_player_card() {
  for (int i = 0; i < NUM_CARDS; i++) {
    if (!used[i]) {
      player_score += get_card_value(deck[i]);
      used[i] = true;
      break;
    }
  }
}

void deal_computer_card() {
  for (int i = 0; i < NUM_CARDS; i++) {
    if (!used[i]) {
      computer_score += get_card_value(deck[i]);
      used[i] = true;
      break;
    }
  }
}

void display_player_hand() {
  printf("Your hand: ");
  for (int i = 0; i < NUM_CARDS; i++) {
    if (used[i]) {
      printf("[%s of %s] ", deck[i].rank, deck[i].suit);
    }
  }
  printf("\n");
}

void display_computer_hand() {
  printf("Computer's hand: ");
  for (int i = 0; i < NUM_CARDS; i++) {
    if (used[i]) {
      printf("[%s of %s] ", deck[i].rank, deck[i].suit);
    } else {
      printf("[Hidden card]");
    }
  }
  printf("\n");
}

void display_player_score() {
  printf("Your score: %d\n", player_score);
}

void display_computer_score() {
  printf("Computer's score: %d\n", computer_score);
}

void display_game_result() {
  printf("Final score:\n");
  printf("Your score: %d\n", player_score);
  printf("Computer's score: %d\n", computer_score);
  if (player_score > 21) {
    printf("You lose!\n");
  } else if (computer_score > 21) {
    printf("You win!\n");
  } else if (player_score > computer_score) {
    printf("You win!\n");
  } else if (player_score < computer_score) {
    printf("You lose!\n");
  } else {
    printf("It's a tie!\n");
  }
}

bool check_game_over() {
  if (player_score >= 21 || computer_score >= 21) {
    return true;
  } else {
    return false;
  }
}