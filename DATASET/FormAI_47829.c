//FormAI DATASET v1.0 Category: Poker Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13

typedef struct {
    int rank; // 0-12 represents A-K
    int suit; // 0-3 represents clubs, diamonds, hearts, spades
} card;

void initializeDeck(card deck[]);
void shuffleDeck(card deck[]);
void dealCards(card deck[], card players[][NUM_CARDS/NUM_PLAYERS]);

int main() {
    card deck[NUM_CARDS];
    card players[NUM_PLAYERS][NUM_CARDS/NUM_PLAYERS];

    srand(time(NULL));
    initializeDeck(deck);
    shuffleDeck(deck);
    dealCards(deck, players);

    // game logic goes here

    return 0;
}

void initializeDeck(card deck[]) {
    int i, j, index = 0;
    for (i = 0; i < NUM_RANKS; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck[index].rank = i;
            deck[index].suit = j;
            index++;
        }
    }
}

void shuffleDeck(card deck[]) {
    int i, j;
    card temp;
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(card deck[], card players[][NUM_CARDS/NUM_PLAYERS]) {
    int i, j, index = 0;
    for (j = 0; j < NUM_CARDS/NUM_PLAYERS; j++) {
        for (i = 0; i < NUM_PLAYERS; i++) {
            players[i][j] = deck[index];
            index++;
        }
    }
}