//FormAI DATASET v1.0 Category: Poker Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global variables for the deck and hands
const char* suits[] = {"hearts", "diamonds", "clubs", "spades"};
const char* ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
int deck[52];
int player1[2];
int player2[2];

// Function to shuffle the deck
void shuffleDeck() {
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int randomIndex = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

// Function to deal the cards
void dealCards() {
    player1[0] = deck[0];
    player1[1] = deck[1];
    player2[0] = deck[2];
    player2[1] = deck[3];
    printf("Player 1's hand: %s of %s and %s of %s\n", ranks[player1[0] % 13], suits[player1[0] / 13], ranks[player1[1] % 13], suits[player1[1] / 13]);
    printf("Player 2's hand: %s of %s and %s of %s\n", ranks[player2[0] % 13], suits[player2[0] / 13], ranks[player2[1] % 13], suits[player2[1] / 13]);
}

// Function to determine the winner
void determineWinner() {
    int player1Total = player1[0] % 13 + player1[1] % 13;
    int player2Total = player2[0] % 13 + player2[1] % 13;
    printf("Player 1's total: %d\n", player1Total);
    printf("Player 2's total: %d\n", player2Total);
    if (player1Total > player2Total) {
        printf("Player 1 wins!\n");
    } else if (player2Total > player1Total) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}

int main() {
    // Initialize the deck
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    shuffleDeck();
    dealCards();
    determineWinner();

    return 0;
}