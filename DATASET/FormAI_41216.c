//FormAI DATASET v1.0 Category: Poker Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card symbols
enum { SPADES, HEARTS, DIAMONDS, CLUBS };
char *symbol[] = {"Spades", "Hearts", "Diamonds", "Clubs"};

// Define card values
enum { ACE = 1, JACK = 11, QUEEN = 12, KING = 13};

int main() {
    // Initialize random seed using current time
    srand(time(NULL));

    // Initialize deck with 52 cards
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal each player 5 cards
    int player1[5];
    int player2[5];
    for (int i = 0; i < 5; i++) {
        player1[i] = deck[i * 2];
        player2[i] = deck[i * 2 + 1];
    }

    // Print out each player's hand
    printf("Player 1's Hand:\n");
    for (int i = 0; i < 5; i++) {
        int card = player1[i];
        int suit = card / 13;
        int rank = card % 13 + 1;

        printf("%d of %s\n", rank, symbol[suit]);
    }

    printf("\nPlayer 2's Hand:\n");
    for (int i = 0; i < 5; i++) {
        int card = player2[i];
        int suit = card / 13;
        int rank = card % 13 + 1;

        printf("%d of %s\n", rank, symbol[suit]);
    }

    // Determine winner
    int player1Score = 0;
    int player2Score = 0;
    for (int i = 0; i < 5; i++) {
        int card1 = player1[i];
        int card2 = player2[i];
        int rank1 = card1 % 13 + 1;
        int rank2 = card2 % 13 + 1;

        if (rank1 > rank2) {
            player1Score++;
        } else if (rank2 > rank1) {
            player2Score++;
        }
    }

    if (player1Score > player2Score) {
        printf("\nPlayer 1 wins!\n");
    } else if (player2Score > player1Score) {
        printf("\nPlayer 2 wins!\n");
    } else {
        printf("\nIt's a tie!\n");
    }

    return 0;
}