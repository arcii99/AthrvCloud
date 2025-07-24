//FormAI DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>

#define SIZE 10

void printBoard(int board[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int getNeighborCount(int board[][SIZE], int row, int col) {
    int count = 0, i, j;

    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }

            if (i < 0 || i > SIZE - 1) {
                continue;
            }

            if (j < 0 || j > SIZE - 1) {
                continue;
            }

            if (board[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

void updateBoard(int board[][SIZE]) {
    int newBoard[SIZE][SIZE], i, j, count;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            count = getNeighborCount(board, i, j);
            if (board[i][j] == 1) {
                if (count < 2) {
                    newBoard[i][j] = 0;
                } else if (count == 2 || count == 3) {
                    newBoard[i][j] = 1;
                } else if (count > 3) {
                    newBoard[i][j] = 0;
                }
            } else if (board[i][j] == 0) {
                if (count == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

void simulateLife(int board[][SIZE], int generations) {
    int i;
    for (i = 0; i < generations; i++) {
        printf("Generation %d:\n", i + 1);
        printBoard(board);
        printf("\n");
        updateBoard(board);
    }
}

int main() {
    int board[SIZE][SIZE] = {0};
    board[4][4] = 1;
    board[4][5] = 1;
    board[4][6] = 1;

    simulateLife(board, 10);
    return 0;
}