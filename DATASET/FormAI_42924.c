//FormAI DATASET v1.0 Category: Poker Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Poker Game!\n");

    // Seeding the random number generator
    srand(time(NULL));

    // Creating a deck of cards
    char *suits[4] = {"Spades", "Diamonds", "Hearts", "Clubs"};
    char *values[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int deck[52];
    int i;
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffling the deck
    int j;
    for (j = 0; j < 52; j++) {
        int randomIndex = rand() % 52;
        int temp = deck[j];
        deck[j] = deck[randomIndex];
        deck[randomIndex] = temp;
    }

    // Dealing the cards
    int playerHand[5];
    int dealerHand[5];
    int k;
    for (k = 0; k < 5; k++) {
        playerHand[k] = deck[k*2];
        dealerHand[k] = deck[k*2+1];
    }

    // Showing the hands
    printf("Your hand:\n");
    for (k = 0; k < 5; k++) {
        printf("%s of %s\n", values[playerHand[k] % 13], suits[playerHand[k] / 13]);
    }
    printf("Dealer's hand:\n");
    for (k = 0; k < 5; k++) {
        printf("%s of %s\n", values[dealerHand[k] % 13], suits[dealerHand[k] / 13]);
    }

    // Evaluating the hands
    int playerScore = 0;
    int dealerScore = 0;
    for (k = 0; k < 5; k++) {
        playerScore += playerHand[k] % 13 + 1;
        dealerScore += dealerHand[k] % 13 + 1;
    }
    if (playerScore > dealerScore) {
        printf("Congratulations! You win!\n");
    } else if (dealerScore > playerScore) {
        printf("Sorry, you lose!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}