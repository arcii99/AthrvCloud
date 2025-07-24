//FormAI DATASET v1.0 Category: Table Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1Score = 0, player2Score = 0;
    int turnScore = 0, roll = 0;
    char player1Name[20], player2Name[20];
    srand(time(NULL)); // seed for random number generator

    printf("Welcome to the C Table Game!\n\n");
    printf("Player 1, enter your name: ");
    fgets(player1Name, 20, stdin);
    printf("Player 2, enter your name: ");
    fgets(player2Name, 20, stdin);

    printf("\n%s and %s, are you ready to play? Let's begin!\n", player1Name, player2Name);

    // game loop
    while (player1Score < 100 && player2Score < 100) {

        // Player 1 turn
        printf("\n%s's turn.\n", player1Name);
        roll = rand() % 6 + 1; // roll dice
        printf("Roll: %d\n", roll);
        if (roll == 1) { // check for 1, lose turn
            printf("Oh no, you rolled a 1. Your turn is over.\n");
        } else { // add to turn score
            turnScore += roll;
            printf("Turn score: %d\n", turnScore);
            printf("Press 'r' to roll again or 'h' to hold: ");
            char choice = getchar();
            getchar();
            while (choice != 'h') { // keep rolling until hold
                roll = rand() % 6 + 1;
                printf("Roll: %d\n", roll);
                if (roll == 1) { // lose turn
                    turnScore = 0;
                    printf("Oh no, you rolled a 1. Your turn is over.\n");
                    break;
                } else { // add to turn score
                    turnScore += roll;
                    printf("Turn score: %d\n", turnScore);
                    printf("Press 'r' to roll again or 'h' to hold: ");
                    choice = getchar();
                    getchar();
                }
            }
            player1Score += turnScore; // add turn score to total score
            printf("\n%s's total score: %d\n", player1Name, player1Score);
            turnScore = 0; // reset turn score for next player
        }

        // Player 2 turn
        printf("\n%s's turn.\n", player2Name);
        roll = rand() % 6 + 1;
        printf("Roll: %d\n", roll);
        if (roll == 1) {
            printf("Oh no, you rolled a 1. Your turn is over.\n");
        } else {
            turnScore += roll;
            printf("Turn score: %d\n", turnScore);
            printf("Press 'r' to roll again or 'h' to hold: ");
            char choice = getchar();
            getchar();
            while (choice != 'h') {
                roll = rand() % 6 + 1;
                printf("Roll: %d\n", roll);
                if (roll == 1) {
                    turnScore = 0;
                    printf("Oh no, you rolled a 1. Your turn is over.\n");
                    break;
                } else {
                    turnScore += roll;
                    printf("Turn score: %d\n", turnScore);
                    printf("Press 'r' to roll again or 'h' to hold: ");
                    choice = getchar();
                    getchar();
                }
            }
            player2Score += turnScore;
            printf("\n%s's total score: %d\n", player2Name, player2Score);
            turnScore = 0;
        }
    }

    // declare winner
    if (player1Score >= 100) {
        printf("\nCongratulations %s, you win!\n", player1Name);
    } else {
        printf("\nCongratulations %s, you win!\n", player2Name);
    }

    return 0;
}