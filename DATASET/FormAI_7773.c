//FormAI DATASET v1.0 Category: Poker Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Struct for each card in the deck
struct Card {
    char suit;
    int value;
};

// Function to initialize the deck
void initDeck(struct Card *deck) {
    char suits[4] = {'C', 'D', 'H', 'S'};
    int values[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int i, j, n = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            deck[n].suit = suits[i];
            deck[n].value = values[j];
            n++;
        }
    }
}

// Function to shuffle the deck
void shuffleDeck(struct Card *deck) {
    srand(time(NULL)); // Seed for rand() function
    int i, n = DECK_SIZE;
    for (i = 0; i < DECK_SIZE; i++) {
        // Choose a random card from the deck
        int r = rand() % n;
        if (r != n-1) {
            // Swap the chosen card with the last card in the deck
            struct Card temp = deck[r];
            deck[r] = deck[n-1];
            deck[n-1] = temp;
        }
        n--;
    }
}

// Function to print a card
void printCard(struct Card c) {
    if (c.value < 11) {
        printf("%d", c.value);
    } else if (c.value == 11) {
        printf("J");
    } else if (c.value == 12) {
        printf("Q");
    } else if (c.value == 13) {
        printf("K");
    } else if (c.value == 14) {
        printf("A");
    }
    printf("%c ", c.suit);
}

// Function to print a hand
void printHand(struct Card *hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printCard(hand[i]);
    }
    printf("\n");
}

// Function to evaluate the hand and return its rank
int evaluateHand(struct Card *hand) {
    int values[13] = {0};
    int suits[4] = {0};
    int i, flush = 0, straight = 0, pairs = 0, three = 0, four = 0;
    for (i = 0; i < HAND_SIZE; i++) {
        values[hand[i].value-2]++;
        suits[hand[i].suit-67]++;
    }
    for (i = 0; i < 13; i++) {
        if (values[i] == 2) {
            pairs++;
        } else if (values[i] == 3) {
            three++;
        } else if (values[i] == 4) {
            four++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (suits[i] == 5) {
            flush = 1;
        }
    }
    for (i = 0; i < 13 && i+4 < 13; i++) {
        if (values[i] && values[i+1] && values[i+2] && values[i+3] && values[i+4]) {
            straight = 1;
        }
    }
    if (flush && straight && values[12]) {
        return 10; // Royal flush
    } else if (flush && straight) {
        return 9; // Straight flush
    } else if (four) {
        return 8; // Four of a kind
    } else if (pairs && three) {
        return 7; // Full house
    } else if (flush) {
        return 6; // Flush
    } else if (straight) {
        return 5; // Straight
    } else if (three) {
        return 4; // Three of a kind
    } else if (pairs == 2) {
        return 3; // Two pairs
    } else if (pairs) {
        return 2; // One pair
    } else {
        return 1; // High card
    }
}

int main() {
    struct Card deck[DECK_SIZE];
    struct Card hand[HAND_SIZE];
    int i;
    initDeck(deck);
    shuffleDeck(deck);

    // Deal a hand
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }

    // Print the hand and evaluate its rank
    printf("Your hand: ");
    printHand(hand);
    int rank = evaluateHand(hand);
    printf("Rank: %d\n", rank);
    return 0;
}