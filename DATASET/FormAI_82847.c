//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void printBoard(int board[ROWS][COLS]) {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%c", board[row][col] ? '#' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

int getNeighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    int r, c;
    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c]) {
                count++;
            }
        }
    }
    if (board[row][col]) {
        count--;
    }
    return count;
}

void updateBoard(int board[ROWS][COLS]) {
    int row, col;
    int copy[ROWS][COLS];
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            int neighbors = getNeighbors(board, row, col);
            if (neighbors == 3) {
                copy[row][col] = 1;
            } else if (neighbors == 2 && board[row][col]) {
                copy[row][col] = 1;
            } else {
                copy[row][col] = 0;
            }
        }
    }
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = copy[row][col];
        }
    }
}

int main(void) {
    int board[ROWS][COLS];
    int row, col;
    srand(time(NULL));
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }
    while (1) {
        printBoard(board);
        updateBoard(board);
    }
    return 0;
}