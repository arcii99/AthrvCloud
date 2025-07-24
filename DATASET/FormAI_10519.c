//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int playerHand[5];
    int computerHand[5];
    int deck[52];
    char suits[4] = {'H', 'D', 'C', 'S'};
    char cardValues[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    int playerChoice;
    int i, j, k;
    
    srand(time(NULL));
    
    // Initialize deck
    for (i = 0; i < 52; i++) {
        deck[i] = i;
    }
    
    // Deal cards to player and computer
    for (i = 0; i < 5; i++) {
        playerHand[i] = deck[rand() % 52];
        computerHand[i] = deck[rand() % 52];
    }
    
    // Display player hand
    printf("Your hand: ");
    for (i = 0; i < 5; i++) {
        printf("%c%c ", cardValues[playerHand[i] % 13], suits[playerHand[i] / 13]);
    }
    
    // Ask user which cards to replace
    printf("\n");
    for (i = 0; i < 5; i++) {
        printf("Keep card %d? (1 for yes, 0 for no): ", i+1);
        scanf("%d", &playerChoice);
        if (!playerChoice) {
            playerHand[i] = deck[rand() % 52];
        }
    }
    
    // Re-draw computer hand
    for (i = 0; i < 5; i++) {
        if (playerHand[i] == computerHand[i]) {
            computerHand[i] = deck[rand() % 52];
        }
    }
    
    // Display final hands
    printf("Your final hand: ");
    for (i = 0; i < 5; i++) {
        printf("%c%c ", cardValues[playerHand[i] % 13], suits[playerHand[i] / 13]);
    }
    printf("\n");
    printf("Computer's final hand: ");
    for (i = 0; i < 5; i++) {
        printf("%c%c ", cardValues[computerHand[i] % 13], suits[computerHand[i] / 13]);
    }
    
    // Determine winner
    for (i = 0; i < 5; i++) {
        if (playerHand[i] % 13 > computerHand[i] % 13) {
            playerScore++;
        } else if (playerHand[i] % 13 < computerHand[i] % 13) {
            computerScore++;
        }
    }
    
    // Display win/loss message
    if (playerScore > computerScore) {
        printf("\n\nCongratulations! You won!\n");
    } else if (playerScore < computerScore) {
        printf("\n\nSorry, computer wins. Try again!\n");
    } else {
        printf("\n\nIt's a tie!\n");
    }
    
    return 0;
}