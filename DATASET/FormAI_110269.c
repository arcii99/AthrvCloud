//FormAI DATASET v1.0 Category: Poker Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define DECK_SIZE 52
#define SUIT_SIZE 13

// Define structures
struct Card {
    int value;
    char suit;
    int isDealt;
};

// Function prototypes
void shuffleDeck(struct Card deck[]);
void dealCards(struct Card deck[], struct Card player1[], struct Card player2[]);
void printCards(struct Card hand[]);
int getHandValue(struct Card hand[]);

int main() {
    struct Card deck[DECK_SIZE];
    struct Card player1[5];
    struct Card player2[5];
    int player1Value, player2Value;

    // Initialize the deck
    int cardIndex = 0;
    for (int i = 1; i <= SUIT_SIZE; i++) {
        for (char j = 'H'; j <= 'S'; j++) {
            struct Card newCard = {i, j, 0};
            deck[cardIndex] = newCard;
            cardIndex++;
        }
    }

    // Shuffle the deck
    shuffleDeck(deck);

    // Deal the cards
    dealCards(deck, player1, player2);

    // Print player hands
    printf("Player 1's hand:\n");
    printCards(player1);
    printf("\nPlayer 2's hand:\n");
    printCards(player2);

    // Get hand values
    player1Value = getHandValue(player1);
    player2Value = getHandValue(player2);

    // Determine winner
    if (player1Value > player2Value) {
        printf("\nPlayer 1 wins!\n");
    } else if (player2Value > player1Value) {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}

// Shuffle the deck
void shuffleDeck(struct Card deck[]) {
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++) {
        int randomIndex = rand() % DECK_SIZE;
        struct Card temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

// Deal the cards
void dealCards(struct Card deck[], struct Card player1[], struct Card player2[]) {
    int player1Index = 0;
    int player2Index = 0;
    for (int i = 0; i < DECK_SIZE; i++) {
        if (deck[i].isDealt == 0) {
            if (player1Index < 5) {
                player1[player1Index] = deck[i];
                deck[i].isDealt = 1;
                player1Index++;
            } else if (player2Index < 5) {
                player2[player2Index] = deck[i];
                deck[i].isDealt = 1;
                player2Index++;
            } else {
                break;
            }
        }
    }
}

// Print a player's hand
void printCards(struct Card hand[]) {
    for (int i = 0; i < 5; i++) {
        printf("%d%c ", hand[i].value, hand[i].suit);
    }
}

// Get the value of a hand
int getHandValue(struct Card hand[]) {
    int value = 0;
    for (int i = 0; i < 5; i++) {
        if (hand[i].value == 1) {
            value += 14;
        } else {
            value += hand[i].value;
        }
    }
    return value;
}