//FormAI DATASET v1.0 Category: Poker Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Generates a random number between two integers, inclusive
int randomNum(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    printf("\nWelcome to Happy Poker Game!\n");
    printf("May luck be on your side!\n");

    char suits[][10] = {"Hearts", "Diamonds", "Spades", "Clubs"};
    char ranks[][5] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int deck[52];
    int i,j,k;
    int playerScore = 0, dealerScore = 0;
    char c;
    int playerStands = 0, dealerStands = 0;

    // Initialize deck
    for (i = 0; i < 52; i++) 
        deck[i] = i;

    // Shuffle deck
    for (i = 51; i >= 0; i--) {
        j = randomNum(0,i);
        k = deck[i];
        deck[i] = deck[j];
        deck[j] = k;
    }

    // Initial deal
    printf("\nDealing cards...\n\n");
    printf("Player's cards:\n");
    for (i = 0; i < 2; i++) {
        j = deck[i];
        printf("%s of %s\n", ranks[j%13], suits[j/13]);
        playerScore += (j%13) + 1;
    }

    printf("\nDealer's cards:\n");
    for (i = 2; i < 4; i++) {
        j = deck[i];
        if (i == 2) {
            printf("%s of %s\n", ranks[j%13], suits[j/13]);
            dealerScore += (j%13) + 1;
        }
        else
            printf("Hidden Card\n");
    }

    printf("\n");

    // Player's turn
    while (!playerStands) {
        printf("Player's Turn - Enter 'h' to hit or 's' to stand: ");
        scanf("%c", &c);
        getchar();

        if (c == 'h') {
            j = deck[i++];
            printf("\nPlayer received the %s of %s\n", ranks[j%13], suits[j/13]);
            playerScore += (j%13) + 1;
            if (playerScore > 21) {
                printf("\nBust! Dealer wins.\n");
                return 0;
            }
        }
        else if (c == 's')
            playerStands = 1;
    }

    printf("\n");

    // Dealer's turn
    while (!dealerStands) {
        if (dealerScore < 16) {
            j = deck[i++];
            printf("Dealer received the %s of %s\n", ranks[j%13], suits[j/13]);
            dealerScore += (j%13) + 1;
            if (dealerScore > 21) {
                printf("\nDealer bust! Player wins.\n");
                return 0;
            }
        }
        else {
            dealerStands = 1;
            printf("Dealer stands.\n\n");
        }
    }

    // Determine winner
    if (playerScore > dealerScore)
        printf("\nPlayer wins!\n");
    else if (dealerScore > playerScore)
        printf("\nDealer wins!\n");
    else
        printf("\nIt's a tie!\n");

    return 0;
}