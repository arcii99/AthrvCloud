//FormAI DATASET v1.0 Category: Poker Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants for the deck size and number of players
#define DECK_SIZE 52
#define NUM_PLAYERS 4

typedef struct {
    char suit;
    int rank;
} Card;

void shuffleDeck(Card* deck) {
    // Use Fisher-Yates shuffle algorithm to shuffle deck
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(Card* deck) {
    // Print each card in the deck
    for (int i = 0; i < DECK_SIZE; i++) {
        printf("%c%d ", deck[i].suit, deck[i].rank);
    }
    printf("\n");
}

void dealCards(Card* deck, Card* hand, int numCards) {
    // Deal numCards cards from deck to hand
    for (int i = 0; i < numCards; i++) {
        hand[i] = deck[i];
    }
}

int getHandValue(Card* hand, int numCards) {
    // Calculate the value of the hand
    int value = 0;
    for (int i = 0; i < numCards; i++) {
        if (hand[i].rank == 1) { // Ace is worth 11 by default
            value += 11;
        } else if (hand[i].rank >= 10) { // Face cards are worth 10
            value += 10;
        } else { // Number cards are worth their face value
            value += hand[i].rank;
        }
    }
    // Handle aces being worth 1 instead of 11 if it would cause the hand to bust
    for (int i = 0; i < numCards; i++) {
        if (hand[i].rank == 1 && value > 21) {
            value -= 10;
        }
    }
    return value;
}

int compareHands(Card* hand1, int numCards1, Card* hand2, int numCards2) {
    // Compare hand values
    int value1 = getHandValue(hand1, numCards1);
    int value2 = getHandValue(hand2, numCards2);
    if (value1 > value2) {
        return 1; // Hand 1 wins
    } else if (value2 > value1) {
        return 2; // Hand 2 wins
    } else {
        return 0; // Tie game
    }
}

int main() {
    // Create deck
    Card deck[DECK_SIZE];
    char suits[4] = {'C', 'D', 'H', 'S'};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[i * 13 + j - 1].suit = suits[i];
            deck[i * 13 + j - 1].rank = j;
        }
    }
    // Shuffle deck
    shuffleDeck(deck);
    // Deal cards to each player
    Card hands[NUM_PLAYERS][2];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        dealCards(deck, hands[i], 2);
    }
    // Print each player's hand
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand: ", i + 1);
        for (int j = 0; j < 2; j++) {
            printf("%c%d ", hands[i][j].suit, hands[i][j].rank);
        }
        printf("\n");
    }
    // Deal the flop
    Card flop[3];
    dealCards(deck, flop, 3);
    printf("Flop: ");
    for (int i = 0; i < 3; i++) {
        printf("%c%d ", flop[i].suit, flop[i].rank);
    }
    printf("\n");
    // Deal the turn
    Card turn;
    dealCards(deck, &turn, 1);
    printf("Turn: %c%d\n", turn.suit, turn.rank);
    // Deal the river
    Card river;
    dealCards(deck, &river, 1);
    printf("River: %c%d\n", river.suit, river.rank);
    // Compare each player's hand to the community cards and determine the winner
    int winner = 1;
    for (int i = 1; i < NUM_PLAYERS; i++) {
        if (compareHands(hands[i], 2, flop, 3) > compareHands(hands[winner], 2, flop, 3)) {
            winner = i;
        }
        if (compareHands(hands[i], 2, &turn, 1) > compareHands(hands[winner], 2, &turn, 1)) {
            winner = i;
        }
        if (compareHands(hands[i], 2, &river, 1) > compareHands(hands[winner], 2, &river, 1)) {
            winner = i;
        }
    }
    printf("Player %d wins!\n", winner + 1);
    return 0;
}