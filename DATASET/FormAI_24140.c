//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void initBoard(int board[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

int countNeighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    int checkRow;
    int checkCol;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            checkRow = (row + i + ROWS) % ROWS;
            checkCol = (col + j + COLS) % COLS;

            if (board[checkRow][checkCol] == 1) {
                count++;
            }
        }
    }

    if (board[row][col] == 1) {
        count--;
    }

    return count;
}

void computeNextBoard(int board[ROWS][COLS], int nextBoard[ROWS][COLS]) {
    int neighbors;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            neighbors = countNeighbors(board, i, j);

            if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                nextBoard[i][j] = 1;
            }
            else if (board[i][j] == 0 && neighbors == 3) {
                nextBoard[i][j] = 1;
            }
            else {
                nextBoard[i][j] = 0;
            }
        }
    }
}

int main() {
    int board[ROWS][COLS];
    int nextBoard[ROWS][COLS];

    initBoard(board);

    printf("Starting board:\n");
    printBoard(board);

    while (1) {
        computeNextBoard(board, nextBoard);
        printf("\nNext board:\n");
        printBoard(nextBoard);
        memcpy(board, nextBoard, sizeof(int) * ROWS * COLS);
    }

    return 0;
}