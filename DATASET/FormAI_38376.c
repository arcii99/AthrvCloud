//FormAI DATASET v1.0 Category: Table Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare and initialize variables
    int numPlayers = 2;
    int numCards = 52;
    int numRounds = numCards / numPlayers;
    int currentPlayer = 0;
    int playerScore[numPlayers];

    // Seed random number generator
    srand(time(NULL));

    // Initialize player scores to 0
    for (int i = 0; i < numPlayers; i++) {
        playerScore[i] = 0;
    }

    // Create card deck
    int deck[numCards];
    for (int i = 0; i < numCards; i++) {
        deck[i] = i;
    }

    // Shuffle card deck
    for (int i = 0; i < numCards; i++) {
        int j = rand() % numCards;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal cards to players
    for (int i = 0; i < numRounds; i++) {
        for (int j = 0; j < numPlayers; j++) {
            int cardIndex = i * numPlayers + j;
            int cardValue = deck[cardIndex] % 13 + 1;
            playerScore[j] += cardValue;
            printf("Player %d drew a %d\n", j+1, cardValue);
        }
    }

    // Determine winner and print scores
    int maxScore = 0;
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d scored %d points\n", i+1, playerScore[i]);
        if (playerScore[i] > maxScore) {
            maxScore = playerScore[i];
            currentPlayer = i;
        }
    }
    printf("Player %d wins the game!\n", currentPlayer+1);

    return 0;
}