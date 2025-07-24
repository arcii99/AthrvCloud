//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number based on upper and lower limit
int getRandomNumber(int lower, int upper) 
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // Initialize the game board, defaulting all spots to 0
    int board[5][5] = {{0}};

    // Seed the RNG with the current time
    srand(time(NULL));

    // Fill in the center spot with a star
    board[2][2] = 1;

    // Draw the initial game board
    printf("  B   I   N   G   O\n");
    for (int i = 0; i < 5; i++) {
        printf("--------------------\n");
        for (int j = 0; j < 5; j++) {
            if (j == 0) printf("|"); // Formatting
            if (board[i][j] == 1) printf("* "); // Center spot
            else printf("%d ", board[i][j]); // Number spot
            if (j == 4) printf("|"); // Formatting
        }
        printf("\n");
    }
    printf("--------------------\n");

    // Main game loop
    int round = 1;
    while (1) {
        printf("\nRound %d\n", round);

        // Get a random number and mark it on the board
        int number = getRandomNumber(1, 25);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == number) {
                    board[i][j] = -1; // Mark it as called
                    printf("%d is called!\n", number);
                    break;
                }
            }
        }

        // Check for a win
        int bingo = 0;
        for (int i = 0; i < 5; i++) {
            int sum_row = 0;
            int sum_col = 0;
            for (int j = 0; j < 5; j++) {
                sum_row += board[i][j];
                sum_col += board[j][i];
                if (i == j) bingo += board[i][j];
                if (i + j == 4) bingo += board[i][j];
            }
            if (sum_row == -5 || sum_col == -5) { // Win by row or column
                bingo = -5;
                break;
            }
        }
        if (bingo == -5 || bingo == 5) { // Win by diagonal
            printf("BINGO!\n");
            break; // Exit the loop
        }

        // Redraw the game board
        printf("\n  B   I   N   G   O\n");
        for (int i = 0; i < 5; i++) {
            printf("--------------------\n");
            for (int j = 0; j < 5; j++) {
                if (j == 0) printf("|"); // Formatting
                if (board[i][j] == 1) printf("* "); // Center spot
                else if (board[i][j] == -1) printf("  "); // Called spot
                else printf("%d ", board[i][j]); // Number spot
                if (j == 4) printf("|"); // Formatting
            }
            printf("\n");
        }
        printf("--------------------\n");

        round += 1;
    }

    return 0;
}