//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // set initial values for players
    int player1Score = 0;
    int player2Score = 0;

    // main game loop
    while (1) {
        // roll dice for player 1
        int roll1 = rand() % 6 + 1;

        // display roll for player 1
        printf("Player 1 rolled a %d\n", roll1);

        // update player 1's score
        player1Score += roll1;

        // check if player 1 wins
        if (player1Score >= 100) {
            printf("Player 1 wins with a score of %d\n", player1Score);
            break;
        }

        // roll dice for player 2
        int roll2 = rand() % 6 + 1;

        // display roll for player 2
        printf("Player 2 rolled a %d\n", roll2);

        // update player 2's score
        player2Score += roll2;

        // check if player 2 wins
        if (player2Score >= 100) {
            printf("Player 2 wins with a score of %d\n", player2Score);
            break;
        }
    }

    return 0;
}