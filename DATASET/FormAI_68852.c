//FormAI DATASET v1.0 Category: Poker Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define MAX_PLAYERS 10
#define NUM_CARDS_PER_HAND 5

typedef struct {
  int rank;
  int suit;
} Card;

typedef struct {
  Card cards[NUM_CARDS_PER_HAND];
  int score;
} Hand;

Card deck[NUM_CARDS];
Hand hands[MAX_PLAYERS];

void shuffleDeck()
{
  srand(time(NULL));
  for (int i = 0; i < NUM_CARDS; i++) {
    int j = rand() % NUM_CARDS;
    Card temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void initDeck()
{
  int card = 0;
  for (int suit = 0; suit < NUM_SUITS; suit++) {
    for (int rank = 0; rank < NUM_RANKS; rank++) {
      deck[card].suit = suit;
      deck[card].rank = rank;
      card++;
    }
  }
}

int getScore(Card cards[NUM_CARDS_PER_HAND])
{
  int score = 0;
  for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
    Card c = cards[i];
    if (c.rank >= 10) {
      score += 10;
    } else if (c.rank == 1) {
      score += 11;
    } else {
      score += c.rank;
    }
  }
  return score;
}

void printCard(Card c)
{
  char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
  char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
  printf("%s of %s\n", ranks[c.rank], suits[c.suit]);
}

void printHand(Hand h)
{
  for (int i = 0; i < NUM_CARDS_PER_HAND; i++) {
    printCard(h.cards[i]);
  }
}

void dealHands(int numPlayers)
{
  for (int i = 0; i < numPlayers; i++) {
    for (int j = 0; j < NUM_CARDS_PER_HAND; j++) {
      hands[i].cards[j] = deck[i * NUM_CARDS_PER_HAND + j];
    }
    hands[i].score = getScore(hands[i].cards);
  }
}

Hand* getWinner(int numPlayers)
{
  Hand* winner = NULL;
  int highestScore = 0;
  for (int i = 0; i < numPlayers; i++) {
    if (hands[i].score > highestScore && hands[i].score <= 21) {
      highestScore = hands[i].score;
      winner = &hands[i];
    }
  }
  return winner;
}

void printWinner(Hand* winner)
{
  if (winner == NULL) {
    printf("No winner\n");
  } else {
    printf("Winner:\n");
    printHand(*winner);
  }
}

int main()
{
  initDeck();
  shuffleDeck();
  dealHands(2);
  printf("Player 1\n");
  printHand(hands[0]);
  printf("Player 2\n");
  printHand(hands[1]);
  Hand* winner = getWinner(2);
  printWinner(winner);
  return 0;
}