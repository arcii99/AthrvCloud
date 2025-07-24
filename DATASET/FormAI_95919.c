//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, num, player_1, player_2, computer, sum1, sum2;
    int board[20];

    // Initialize the game board with random numbers between 1 and 6
    srand(time(0));
    for (i = 0; i < 20; i++) {
        board[i] = rand() % 6 + 1;
    }

    // Print the game board
    printf("Game Board:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", board[i]);
    }
    printf("\n");

    // Initialize the players' scores
    player_1 = player_2 = sum1 = sum2 = 0;

    // Loop through the board
    for (i = 0; i < 20; i++) {
        printf("Round %d:\n", i+1);

        // Player 1's turn
        printf("Player 1: ");
        printf("Enter a position between 1-20: ");
        scanf("%d", &num);
        player_1 += board[num-1];
        printf("You rolled a %d\n", board[num-1]);
        sum1 += board[num-1];

        // Player 2's turn
        printf("Player 2: ");
        printf("Enter a position between 1-20: ");
        scanf("%d", &num);
        player_2 += board[num-1];
        printf("You rolled a %d\n", board[num-1]);
        sum2 += board[num-1];

        // Computer's turn
        printf("Computer: ");
        num = rand() % 20 + 1;
        computer += board[num-1];
        printf("The computer rolled a %d\n", board[num-1]);
    }

    // Determine the winner
    if (player_1 > player_2 && player_1 > computer) {
        printf("Player 1 wins!\n");
    } else if (player_2 > player_1 && player_2 > computer) {
        printf("Player 2 wins!\n");
    } else {
        printf("The computer wins!\n");
    }

    // Print the scores
    printf("Player 1 score: %d\n", sum1);
    printf("Player 2 score: %d\n", sum2);
    printf("Computer score: %d\n", computer);

    return 0;
}