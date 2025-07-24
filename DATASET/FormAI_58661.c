//FormAI DATASET v1.0 Category: Poker Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_VALUES 13
#define NUM_SUITS 4

typedef struct {
    int rank;
    int suit;
} Card;

void shuffleDeck(Card deck[]) {
    int i, j;
    Card tempCard;

    srand(time(NULL));
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        tempCard = deck[i];
        deck[i] = deck[j];
        deck[j] = tempCard;
    }
}

void dealCards(Card deck[], Card hands[][5], int numPlayers) {
    int i, j, k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < numPlayers; j++) {
            hands[j][i] = deck[k++];
        }
    }
}

void printCard(Card card) {
    char rankChar, suitChar;

    switch (card.rank) {
        case 0: rankChar = 'A'; break;
        case 1: rankChar = '2'; break;
        case 2: rankChar = '3'; break;
        case 3: rankChar = '4'; break;
        case 4: rankChar = '5'; break;
        case 5: rankChar = '6'; break;
        case 6: rankChar = '7'; break;
        case 7: rankChar = '8'; break;
        case 8: rankChar = '9'; break;
        case 9: rankChar = 'T'; break;
        case 10: rankChar = 'J'; break;
        case 11: rankChar = 'Q'; break;
        case 12: rankChar = 'K'; break;
    }

    switch (card.suit) {
        case 0: suitChar = 'C'; break;
        case 1: suitChar = 'D'; break;
        case 2: suitChar = 'H'; break;
        case 3: suitChar = 'S'; break;
    }

    printf("%c%c ", rankChar, suitChar);
}

void printHand(Card hand[]) {
    int i;
    for (i = 0; i < 5; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

void printAllHands(Card hands[][5], int numPlayers) {
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("Player %d: ", i+1);
        printHand(hands[i]);
    }
}

int main() {
    Card deck[NUM_CARDS];
    Card hands[4][5];
    int i, j;

    for (i = 0; i < NUM_VALUES; i++) {
        for (j = 0; j < NUM_SUITS; j++) {
            deck[i*4 + j].rank = i;
            deck[i*4 + j].suit = j;
        }
    }

    shuffleDeck(deck);
    dealCards(deck, hands, 4);

    printAllHands(hands, 4);

    return 0;
}