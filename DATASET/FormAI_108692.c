//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
/*
 * Game of Life - A unique example program
 * By [Your Name Here]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

void initializeBoard(int board[ROWS][COLS]) {
    srand(time(0));
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int value = rand() % 2;
            board[i][j] = value;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (board[i][j]) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i=row-1; i<=row+1; i++) {
        for (int j=col-1; j<=col+1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                if (board[i][j]) {
                    count++;
                }
            }
        }
    }
    return count;
}

void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS] = {0};
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newBoard[i][j] = 1;
                }
            }
        }
    }
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    initializeBoard(board);
    printBoard(board);
    for (int i=0; i<10; i++) {
        updateBoard(board);
        printBoard(board);
    }
    return 0;
}