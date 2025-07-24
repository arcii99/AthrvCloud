//FormAI DATASET v1.0 Category: Poker Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECKSIZE 52
#define HANDSIZE 5

// Initialize the deck
void initializeDeck(int deck[]) {
    int index = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            deck[index] = rank + (13 * suit);
            index++;
        }
    }
}

// Shuffle the deck
void shuffleDeck(int deck[]) {
    srand(time(0)); // seed the random number generator
    for (int i = 0; i < DECKSIZE; i++) {
        int j = rand() % DECKSIZE;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deal the hands
void dealHands(int deck[], int* hands[]) {
    for (int i = 0; i < HANDSIZE; i++) {
        for (int j = 0; j < 2; j++) {
            hands[j][i] = deck[(2 * i) + j];
        }
    }
}

// Sort a hand by rank
void sortHand(int hand[]) {
    int temp;
    for (int i = 0; i < HANDSIZE - 1; i++) {
        for (int j = i + 1; j < HANDSIZE; j++) {
            if (hand[j] % 13 < hand[i] % 13) {
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

// Print a hand
void printHand(int hand[]) {
    char* suits[] = {"hearts", "diamonds", "clubs", "spades"};
    char* ranks[] = {"two", "three", "four", "five", "six", "seven", "eight",
                     "nine", "ten", "jack", "queen", "king", "ace"};

    for (int i = 0; i < HANDSIZE; i++) {
        printf("%s of %s\n", ranks[hand[i] % 13], suits[hand[i] / 13]);
    }
}

// Determine if hand contains a pair
int hasPair(int hand[]) {
    for (int i = 0; i < HANDSIZE - 1; i++) {
        for (int j = i + 1; j < HANDSIZE; j++) {
            if (hand[i] % 13 == hand[j] % 13) {
                return 1; // found a pair
            }
        }
    }
    return 0; // no pair found
}

int main() {
    int deck[DECKSIZE];
    int hand1[HANDSIZE];
    int hand2[HANDSIZE];

    initializeDeck(deck);
    shuffleDeck(deck);
    dealHands(deck, (int* []){hand1, hand2});
    sortHand(hand1);
    sortHand(hand2);

    printf("Player 1\n");
    printHand(hand1);
    printf("\nPlayer 2\n");
    printHand(hand2);

    if (hasPair(hand1)) {
        printf("\nPlayer 1 has a pair!\n");
    }
    if (hasPair(hand2)) {
        printf("Player 2 has a pair!\n");
    }

    return 0;
}