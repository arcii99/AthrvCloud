//FormAI DATASET v1.0 Category: Poker Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {HEARTS, DIAMONDS, CLUBS, SPADES} Suit;
typedef struct {
    Suit suit;
    int value;
} Card;

typedef struct {
    Card hand[HAND_SIZE];
    int score;
} Player;

Card deck[DECK_SIZE];
Player player, dealer;

void initializeDeck() {
  int index = 0;
  for (Suit s = HEARTS; s <= SPADES; s++) {
    for (int val = 2; val <= 14; val++) {
      deck[index].suit = s;
      deck[index].value = val;
      index++;
    }
  }
}

void shuffleDeck() {
  srand(time(NULL));
  for (int i = 0; i < DECK_SIZE; i++) {
    int j = rand() % DECK_SIZE;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void dealCards() {
  for (int i = 0; i < HAND_SIZE; i++) {
    player.hand[i] = deck[i];
    dealer.hand[i] = deck[i + HAND_SIZE];
  }
}

void printCard(Card c) {
  switch (c.value) {
    case 11: printf("J"); break;
    case 12: printf("Q"); break;
    case 13: printf("K"); break;
    case 14: printf("A"); break;
    default: printf("%d", c.value); break;
  }
  switch (c.suit) {
    case HEARTS: printf("\u2665"); break;
    case DIAMONDS: printf("\u2666"); break;
    case CLUBS: printf("\u2663"); break;
    case SPADES: printf("\u2660"); break;
  }
}

void printPlayerHand(Player p) {
  for (int i = 0; i < HAND_SIZE; i++) {
    printCard(p.hand[i]);
    printf(" ");
  }
}

void calculateScore(Player *p) {
  int score = 0;
  int aceCount = 0;
  for (int i = 0; i < HAND_SIZE; i++) {
    if (p->hand[i].value >= 10 && p->hand[i].value <= 13) {
      score += 10;
    } else if (p->hand[i].value == 14) {
      score += 11;
      aceCount++;
    } else {
      score += p->hand[i].value;
    }
  }
  while (score > 21 && aceCount > 0) {
    score -= 10;
    aceCount--;
  }
  p->score = score;
}

int main() {
  initializeDeck();
  shuffleDeck();
  dealCards();
  
  // Player's turn
  printf("Your hand: ");
  printPlayerHand(player);
  calculateScore(&player);
  printf("\nYour score: %d\n", player.score);
  char input[10];
  while (strcmp(input, "stand") != 0 && player.score <= 21) {
    printf("Do you want to hit or stand? ");
    fgets(input, sizeof(input), stdin);
    if (strcmp(input, "hit\n") == 0) {
      player.hand[HAND_SIZE] = deck[HAND_SIZE * 2];
      printf("Your hand: ");
      printPlayerHand(player);
      calculateScore(&player);
      printf("\nYour score: %d\n", player.score);
    }
  }
  
  // Dealer's turn
  printf("Dealer's hand: ");
  printPlayerHand(dealer);
  calculateScore(&dealer);
  printf("\nDealer's score: %d\n", dealer.score);
  while (dealer.score < 17) {
    dealer.hand[HAND_SIZE] = deck[HAND_SIZE * 3];
    printf("Dealer hits. Dealer's hand: ");
    printPlayerHand(dealer);
    calculateScore(&dealer);
    printf("\nDealer's score: %d\n", dealer.score);
  }
  
  // Determine winner
  if (player.score > 21 || (dealer.score <= 21 && dealer.score > player.score)) {
    printf("Dealer wins!\n");
  } else if (dealer.score > 21 || player.score > dealer.score) {
    printf("You win!\n");
  } else {
    printf("Tie game.\n");
  }

  return 0;
}