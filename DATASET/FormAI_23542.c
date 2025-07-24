//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

typedef struct {
    int rank;
    char suit;
} Card;

void shuffleDeck(Card *deck) {
    srand((unsigned int) time(NULL));
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(Card *deck) {
    for(int i = 0; i < DECK_SIZE; i++) {
        printf("%d%c ", deck[i].rank, deck[i].suit);
    }
    printf("\n");
}

void populateDeck(Card *deck) {
    char suits[] = {'C', 'D', 'H', 'S'};
    int ranks[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    for(int i = 0; i < DECK_SIZE; i++) {
        deck[i].suit = suits[i % 4];
        deck[i].rank = ranks[i % 13];
    }
}

int main() {
    Card deck[DECK_SIZE];
    populateDeck(deck);

    printf("Initial deck:\n");
    printDeck(deck);

    shuffleDeck(deck);

    printf("\nShuffled deck:\n");
    printDeck(deck);

    return 0;
}