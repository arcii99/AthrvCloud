//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HAND_SIZE 5
#define MAX_DECK_SIZE 52

/* Card structure */
typedef struct {
    int rank;
    char suit;
} Card;

/* Function prototypes */
void initializeDeck(Card *deck);
void shuffleDeck(Card *deck);
void dealCards(Card *deck, Card *hand, int numCards);
void printHand(Card *hand, int numCards);

/* Main function */
int main() {
    int numPlayers, i, j, k;
    Card deck[MAX_DECK_SIZE], hand[MAX_HAND_SIZE];

    /* Initialize and shuffle deck */
    initializeDeck(deck);
    shuffleDeck(deck);

    /* Get number of players */
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);
    printf("\n");

    /* Deal cards to each player */
    for (i = 1; i <= numPlayers; i++) {
        printf("Player %d's hand:\n", i);
        dealCards(deck, hand, MAX_HAND_SIZE);
        printHand(hand, MAX_HAND_SIZE);
        printf("\n");
    }

    return 0;
}

/* Function to initialize deck */
void initializeDeck(Card *deck) {
    int i, j, k = 0;

    for (i = 1; i <= 13; i++) {
        for (j = 0; j < 4; j++) {
            deck[k].rank = i;
            switch (j) {
            case 0:
                deck[k].suit = 'C';
                break;
            case 1:
                deck[k].suit = 'D';
                break;
            case 2:
                deck[k].suit = 'H';
                break;
            case 3:
                deck[k].suit = 'S';
                break;
            }
            k++;
        }
    }
}

/* Function to shuffle deck */
void shuffleDeck(Card *deck) {
    srand(time(NULL));
    int i, j;
    Card temp;

    for (i = 0; i < MAX_DECK_SIZE; i++) {
        j = rand() % MAX_DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Function to deal cards */
void dealCards(Card *deck, Card *hand, int numCards) {
    int i;

    for (i = 0; i < numCards; i++) {
        hand[i] = deck[i];
    }
}

/* Function to print hand */
void printHand(Card *hand, int numCards) {
    int i;

    for (i = 0; i < numCards; i++) {
        printf("%d%c ", hand[i].rank, hand[i].suit);
    }
}