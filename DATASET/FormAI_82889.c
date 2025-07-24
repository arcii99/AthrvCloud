//FormAI DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_HAND_CARDS 5

typedef struct {
    int rank;
    int suit;
} Card;

void shuffleDeck(Card *deck);
void dealHand(Card *deck, Card *hand, int numCards);
void printHand(Card *hand, int numCards);
int isFlush(Card *hand, int numCards);
int isStraight(Card *hand, int numCards);
int getTopCard(Card *hand, int numCards);

int main(void) {
    Card deck[NUM_SUITS * NUM_RANKS];
    Card hand[NUM_HAND_CARDS];
    int numCards = 5;
    int i;

    srand((unsigned) time(NULL));

    // Create deck of cards
    for (i = 0; i < NUM_SUITS; i++) {
        int j;
        for (j = 0; j < NUM_RANKS; j++) {
            deck[(NUM_RANKS * i) + j].rank = j;
            deck[(NUM_RANKS * i) + j].suit = i;
        }
    }

    shuffleDeck(deck);
    dealHand(deck, hand, numCards);
    printHand(hand, numCards);

    printf("\n");
    if (isFlush(hand, numCards)) {
        printf("Flush\n");
    }
    if (isStraight(hand, numCards)) {
        printf("Straight\n");
    }
    printf("%d\n", getTopCard(hand, numCards));

    return 0;
}

void shuffleDeck(Card *deck) {
    int i;
    for (i = 0; i < NUM_SUITS * NUM_RANKS; i++) {
        int j = rand() % (NUM_SUITS * NUM_RANKS);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealHand(Card *deck, Card *hand, int numCards) {
    int i;
    for (i = 0; i < numCards; i++) {
        hand[i] = deck[i];
    }
}

void printHand(Card *hand, int numCards) {
    int i;
    for (i = 0; i < numCards; i++) {
        printf("%d of suit %d\n", hand[i].rank, hand[i].suit);
    }
}

int isFlush(Card *hand, int numCards) {
    int i;
    int suit = hand[0].suit;
    for (i = 1; i < numCards; i++) {
        if (hand[i].suit != suit) {
            return 0;
        }
    }
    return 1;
}

int isStraight(Card *hand, int numCards) {
    int i;
    int consecutiveCount = 0;
    int consecutiveRank = -1;
    for (i = 0; i < numCards; i++) {
        if (hand[i].rank == consecutiveRank + 1) {
            consecutiveCount++;
        } else if (hand[i].rank != consecutiveRank) {
            consecutiveCount = 1;
        }
        if (consecutiveCount == 5) {
            return 1;
        }
        consecutiveRank = hand[i].rank;
    }
    return 0;
}

int getTopCard(Card *hand, int numCards) {
    int i;
    int topCard = 0;
    for (i = 1; i < numCards; i++) {
        if (hand[i].rank > hand[topCard].rank) {
            topCard = i;
        }
    }
    return hand[topCard].rank;
}