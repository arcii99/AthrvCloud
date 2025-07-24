//FormAI DATASET v1.0 Category: Poker Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct {
    int rank;
    int suit;
} Card;

void shuffleDeck(Card *deck);
void dealCards(Card *deck, Card *hand);

int main() {
    Card deck[DECK_SIZE];
    Card playerHand[HAND_SIZE];

    shuffleDeck(deck);
    dealCards(deck, playerHand);

    // Poker logic and gameplay goes here...

    return 0;
}

void shuffleDeck(Card *deck) {
    int i, j;
    Card temp;

    srand(time(NULL)); // Seed for random number generator

    for (i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = i % 13; // Set rank
        deck[i].suit = i / 13; // Set suit

        // Shuffle the deck
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(Card *deck, Card *hand) {
    int i;

    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}