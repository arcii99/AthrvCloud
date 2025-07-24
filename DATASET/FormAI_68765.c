//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows = 10, columns = 10;

    srand(time(NULL));
    int board[rows][columns];
    int nextBoard[rows][columns];

    // Populate board with random cells
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Print initial board state
    printf("\n----------------\n");
    printf(" Welcome to the Game of Life!\n");
    printf("----------------\n\n");
    printf("Initial Board State:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");

    // Iterate through each cell on the board and update its state
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            int neighbors = 0;

            // Check each neighbor to count the number of live cells
            for(int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    if(i+x >= 0 && i+x < rows && j+y >= 0 && j+y < columns) {
                        if (board[i+x][j+y]) {
                            neighbors++;
                        }
                    }
                }
            }

            // Subtract current cell from count if it's alive
            if(board[i][j]) {
                neighbors--;
            }

            // Update cell based on Game of Life rules
            if(board[i][j] == 1 && neighbors < 2) {
                nextBoard[i][j] = 0;
            } else if(board[i][j] == 1 && neighbors > 3) {
                nextBoard[i][j] = 0;
            } else if(board[i][j] == 0 && neighbors == 3) {
                nextBoard[i][j] = 1;
            } else {
                nextBoard[i][j] = board[i][j];
            }
        }
    }
    printf("\n----------------\nNew Board State:\n");

    // Print updated board state
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", nextBoard[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");

    return 0;
}