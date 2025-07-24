//FormAI DATASET v1.0 Category: Poker Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the card structure
typedef struct {
    int value;
    char suit;
} Card;

// Define function prototypes
void shuffleDeck(Card deck[], int n);
void printHand(Card hand[], int n);
int checkHand(Card hand[], int n);
int getHighestCardValue(Card hand[], int n);
int checkFlush(Card hand[], int n);
int checkStraight(Card hand[], int n);
int checkStraightFlush(Card hand[], int n);
int checkRoyalFlush(Card hand[], int n);

int main() {
    // Define the deck
    Card deck[52] = {
        {2, 'H'}, {3, 'H'}, {4, 'H'}, {5, 'H'}, {6, 'H'}, {7, 'H'}, {8, 'H'}, {9, 'H'}, {10, 'H'}, {11, 'H'}, {12, 'H'}, {13, 'H'}, {14, 'H'},
        {2, 'D'}, {3, 'D'}, {4, 'D'}, {5, 'D'}, {6, 'D'}, {7, 'D'}, {8, 'D'}, {9, 'D'}, {10, 'D'}, {11, 'D'}, {12, 'D'}, {13, 'D'}, {14, 'D'},
        {2, 'C'}, {3, 'C'}, {4, 'C'}, {5, 'C'}, {6, 'C'}, {7, 'C'}, {8, 'C'}, {9, 'C'}, {10, 'C'}, {11, 'C'}, {12, 'C'}, {13, 'C'}, {14, 'C'},
        {2, 'S'}, {3, 'S'}, {4, 'S'}, {5, 'S'}, {6, 'S'}, {7, 'S'}, {8, 'S'}, {9, 'S'}, {10, 'S'}, {11, 'S'}, {12, 'S'}, {13, 'S'}, {14, 'S'}
    };

    // Shuffle the deck
    srand(time(NULL));
    shuffleDeck(deck, 52);

    // Deal two cards to each player
    Card player1[2];
    Card player2[2];
    for (int i = 0; i < 2; i++) {
        player1[i] = deck[i];
        player2[i] = deck[i + 2];
    }

    // Print players' hands
    printf("Player 1's cards:\n");
    printHand(player1, 2);
    printf("\nPlayer 2's cards:\n");
    printHand(player2, 2);

    // Determine winner
    int player1HandValue = checkHand(player1, 2);
    int player2HandValue = checkHand(player2, 2);
    if (player1HandValue > player2HandValue) {
        printf("\nPlayer 1 wins!\n");
    } else if (player2HandValue > player1HandValue) {
        printf("\nPlayer 2 wins!\n");
    } else {
        int player1HighestCardValue = getHighestCardValue(player1, 2);
        int player2HighestCardValue = getHighestCardValue(player2, 2);
        if (player1HighestCardValue > player2HighestCardValue) {
            printf("\nPlayer 1 wins!\n");
        } else if (player2HighestCardValue > player1HighestCardValue) {
            printf("\nPlayer 2 wins!\n");
        } else {
            printf("\nTie game!\n");
        }
    }

    return 0;
}

// Shuffle the deck
void shuffleDeck(Card deck[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Print a player's hand
void printHand(Card hand[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
}

// Check a player's hand for a specific combination
int checkHand(Card hand[], int n) {
    if (checkRoyalFlush(hand, n)) {
        return 10;
    } else if (checkStraightFlush(hand, n)) {
        return 9;
    } else if (checkFlush(hand, n)) {
        return 6;
    } else if (checkStraight(hand, n)) {
        return 5;
    } else {
        return 1;
    }
}

// Get the highest value card in a player's hand
int getHighestCardValue(Card hand[], int n) {
    int highestValue = 0;
    for (int i = 0; i < n; i++) {
        if (hand[i].value > highestValue) {
            highestValue = hand[i].value;
        }
    }
    return highestValue;
}

// Check for a flush in a player's hand
int checkFlush(Card hand[], int n) {
    char firstSuit = hand[0].suit;
    for (int i = 1; i < n; i++) {
        if (hand[i].suit != firstSuit) {
            return 0;
        }
    }
    return 1;
}

// Check for a straight in a player's hand
int checkStraight(Card hand[], int n) {
    int values[n];
    for (int i = 0; i < n; i++) {
        values[i] = hand[i].value;
    }
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (values[j] < values[minIndex]) {
                minIndex = j;
            }
        }
        int temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
    for (int i = 0; i < n - 1; i++) {
        if (values[i + 1] != values[i] + 1) {
            return 0;
        }
    }
    return 1;
}

// Check for a straight flush in a player's hand
int checkStraightFlush(Card hand[], int n) {
    if (checkFlush(hand, n) && checkStraight(hand, n)) {
        return 1;
    } else {
        return 0;
    }
}

// Check for a royal flush in a player's hand
int checkRoyalFlush(Card hand[], int n) {
    if (checkStraightFlush(hand, n) && getHighestCardValue(hand, n) == 14) {
        return 1;
    } else {
        return 0;
    }
}