//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 100

// Initialize the game board with random values
void initialize_board(int board[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Print the game board
void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Update the game board for the next generation
void update_board(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count the number of live neighbors
            int count = 0;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    if (a == 0 && b == 0) continue;
                    if (i+a < 0 || i+a >= ROWS) continue;
                    if (j+b < 0 || j+b >= COLS) continue;
                    count += board[i+a][j+b];
                }
            }

            // Apply the rules of life to update the board
            if (board[i][j] == 1) {
                if (count < 2 || count > 3)
                    newBoard[i][j] = 0;
                else
                    newBoard[i][j] = 1;
            } else {
                if (count == 3)
                    newBoard[i][j] = 1;
                else
                    newBoard[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main(void) {
    int board[ROWS][COLS];
    initialize_board(board);

    for (int i = 0; i < GENERATIONS; i++) {
        printf("Generation %d:\n", i);
        print_board(board);
        update_board(board);
    }

    return 0;
}