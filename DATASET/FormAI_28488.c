//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_CALLS 75

int main() {
    int board[ROWS][COLS] = {0};
    int numCalls = 1;

    // Seed the random number generator 
    srand(time(NULL));

    // Fill the bingo board with random numbers 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 75 + 1;
        }
    }

    // Print the initialized board 
    printf("Initial Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }

    // Generate random calls until we reach 75 or bingo is reached
    while (numCalls <= MAX_CALLS) {
        int call = rand() % 75 + 1;
        printf("Call %d: %d\n", numCalls, call);

        // Check if the call exists on the board and mark it off if found
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == call) {
                    board[i][j] = -1;
                }
            }
        }

        // Check if bingo has been reached
        int bingo = 0;
        for (int i = 0; i < ROWS; i++) {
            // Check rows
            if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) {
                bingo = 1;
            }

            // Check columns
            if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1 && board[3][i] == -1 && board[4][i] == -1) {
                bingo = 1;
            }
        }

        // Check diagonals
        if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
            bingo = 1;
        }
        if (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
            bingo = 1;
        }

        // If bingo is reached, print message and break loop
        if (bingo) {
            printf("Bingo! It took %d calls.\n", numCalls);
            break;
        }

        numCalls++;
    }

    // Print the final board
    printf("Final Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}