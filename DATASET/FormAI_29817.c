//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototypes */
void shuffle(int deck[52]);
void deal(int deck[52], int players[5][2]);

int main() {
    int deck[52];   // Array to represent the deck
    int players[5][2];  // Two dimensional array to represent the five players

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the deck
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle the deck
    shuffle(deck);

    // Deal the cards to the players
    deal(deck, players);

    // Print each player's hand
    printf("Player 1: %d %d\n", players[0][0], players[0][1]);
    printf("Player 2: %d %d\n", players[1][0], players[1][1]);
    printf("Player 3: %d %d\n", players[2][0], players[2][1]);
    printf("Player 4: %d %d\n", players[3][0], players[3][1]);
    printf("Player 5: %d %d\n", players[4][0], players[4][1]);

    return 0;
}

/* Function to shuffle the deck */
void shuffle(int deck[52]) {
    int temp;
    int randomIndex;

    // Swap each card with a randomly selected card
    for (int i = 0; i < 52; i++) {
        randomIndex = rand() % 52;
        temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

/* Function to deal cards to the players */
void deal(int deck[52], int players[5][2]) {
    // Deal two cards to each player in a round-robin fashion
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            players[j][i] = deck[(i * 5) + j];
        }
    }
}