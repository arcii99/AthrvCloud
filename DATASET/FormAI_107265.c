//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

typedef struct _BOARD {
    int board[ROWS][COLS];
} Board;

// Randomly generates the initial state of the game board
void initialize(Board *board) {
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board->board[i][j] = rand() % 2;
        }
    }
}

// Prints the current state of the game board
void printBoard(Board board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board.board[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Calculates the next state of the game board
void getNextState(Board *board) {
    int copyBoard[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighborCount = 0;

            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) {
                        continue;
                    }

                    int row = i + k;
                    int col = j + l;

                    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
                        continue;
                    }

                    if (board->board[row][col]) {
                        neighborCount++;
                    }
                }
            }

            if (board->board[i][j]) {
                if (neighborCount == 2 || neighborCount == 3) {
                    copyBoard[i][j] = 1;
                } else {
                    copyBoard[i][j] = 0;
                }
            } else {
                if (neighborCount == 3) {
                    copyBoard[i][j] = 1;
                } else {
                    copyBoard[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board->board[i][j] = copyBoard[i][j];
        }
    }
}

int main() {
    Board board;
    initialize(&board);

    for (int i = 0; i < 10; i++) {
        printf("Generation %d:\n", i);
        printBoard(board);
        getNextState(&board);
    }

    return 0;
}