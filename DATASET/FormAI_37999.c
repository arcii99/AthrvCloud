//FormAI DATASET v1.0 Category: Poker Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Declare variables
    int playerHand[5], computerHand[5];
    char suits[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char ranks[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int i, j, k, playerScore = 0, computerScore = 0;
    
    // Introduce the game
    printf("Welcome to the game of love and poker!\n");
    printf("You will be playing against the computer, but the true winner will be love!\n");
    printf("Let's begin!\n\n");
    
    // Deal player and computer hands
    printf("Dealing hands...\n\n");
    for (i = 0; i < 5; i++) {
        playerHand[i] = rand() % 13;
        computerHand[i] = rand() % 13;
        printf("You received a %s of %s.\n", ranks[playerHand[i]], suits[rand() % 4]);
    }
    printf("\n");
    
    // Calculate player and computer scores
    printf("Calculating scores...\n\n");
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (playerHand[i] == playerHand[j]) playerScore += 2;
            if (computerHand[i] == computerHand[j]) computerScore += 2;
        }
        for (k = 0; k < 5; k++) {
            if (playerHand[i] == computerHand[k]) playerScore++;
            if (computerHand[i] == playerHand[k]) computerScore++;
        }
    }
    
    // Determine winner and display results
    printf("Time to reveal the hands!\n\n");
    printf("You have a score of %d.\n", playerScore);
    printf("The computer has a score of %d.\n\n", computerScore);
    if (playerScore > computerScore) {
        printf("Congratulations, you won!\n");
        printf("Love has surely won tonight!\n");
    } else if (playerScore < computerScore) {
        printf("Oh no, the computer won...\n");
        printf("But don't worry, love always wins in the end!\n");
    } else {
        printf("It's a tie!\n");
        printf("Looks like the universe wants you two to try again...\n");
    }
    
    return 0;
}