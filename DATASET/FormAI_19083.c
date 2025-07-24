//FormAI DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52

// Structure for representing a card
struct card {
    int rank;
    int suit;
};
typedef struct card Card;

// Function to shuffle the deck
void shuffleDeck(Card deck[]) {
    srand(time(0));
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print a card
void printCard(Card card) {
    char *ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    char *suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    printf("%s of %s\n", ranks[card.rank], suits[card.suit]);
}

// Function to print a hand
void printHand(Card hand[], int size) {
    for (int i = 0; i < size; i++) {
        printCard(hand[i]);
    }
}

// Function to evaluate a hand and return its rank
int evaluateHand(Card hand[], int size) {
    bool flush = true;
    bool straight = true;
    int pairs = 0;
    int threeOfAKind = -1;
    int fourOfAKind = -1;
    int ranks[NUM_CARDS / 4] = {0};
    for (int i = 0; i < size; i++) {
        ranks[hand[i].rank]++;
        if (i > 0) {
            if (hand[i].suit != hand[i-1].suit) {
                flush = false;
            }
            if (hand[i].rank != hand[i-1].rank + 1) {
                straight = false;
            }
        }
    }
    if (flush && straight) {
        return 9; // Straight flush
    }
    for (int i = 0; i < NUM_CARDS / 4; i++) {
        if (ranks[i] == 2) {
            pairs++;
        } else if (ranks[i] == 3) {
            threeOfAKind = i;
        } else if (ranks[i] == 4) {
            fourOfAKind = i;
        }
    }
    if (fourOfAKind != -1) {
        return 8; // Four of a kind
    }
    if (pairs == 1 && threeOfAKind != -1) {
        return 7; // Full house
    }
    if (flush) {
        return 6;
    }
    if (straight) {
        return 5;
    }
    if (threeOfAKind != -1) {
        return 4;
    }
    if (pairs == 2) {
        return 3;
    }
    if (pairs == 1) {
        return 2;
    }
    return 1;
}

int main() {
    Card deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].rank = i % (NUM_CARDS / 4);
        deck[i].suit = i / (NUM_CARDS / 4);
    }
    shuffleDeck(deck);
    Card hand[5];
    for (int i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }
    printf("Your hand:\n");
    printHand(hand, 5);
    printf("\n");
    int handRank = evaluateHand(hand, 5);
    printf("Hand rank: %d\n", handRank);
    return 0;
}