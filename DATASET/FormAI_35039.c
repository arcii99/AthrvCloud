//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int checkForWin(int board[SIZE][SIZE]) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int i, j, row = 0, col = 0, winner = 0, numMoves = 0;
    int board[SIZE][SIZE];

    // fill board with random numbers
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = rand() % 10 + 1;
        }
    }

    // display board
    printf("Here is the board:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    // game loop
    while (!winner) {
        printf("Enter row and col to zero out: ");
        scanf("%d %d", &row, &col);

        // check bounds
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid input. Try again.\n");
        }
        else {
            // check if spot has already been zeroed out
            if (board[row][col] == 0) {
                printf("That spot has already been zeroed out. Try again.\n");
            }
            else {
                // zero out row and col
                for (i = 0; i < SIZE; i++) {
                    board[row][i] = 0;
                    board[i][col] = 0;
                }
                numMoves++;

                // check for win
                winner = checkForWin(board);
            }
        }
    }

    printf("Congratulations, you won in %d moves!", numMoves);

    return 0;
}