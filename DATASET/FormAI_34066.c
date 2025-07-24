//FormAI DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function to print the current generation
void printBoard(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] % 2 == 0) {
                printf(". ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Function to check if a cell is alive or dead
int checkCell(int board[ROWS][COLS], int row, int col) {
    int numAlive = 0;
    if(row > 0) {
        numAlive += board[row-1][col];
    }
    if(row < ROWS-1) {
        numAlive += board[row+1][col];
    }
    if(col > 0) {
        numAlive += board[row][col-1];
    }
    if(col < COLS-1) {
        numAlive += board[row][col+1];
    }
    if(row > 0 && col > 0) {
        numAlive += board[row-1][col-1];
    }
    if(row < ROWS-1 && col > 0) {
        numAlive += board[row+1][col-1];
    }
    if(row > 0 && col < COLS-1) {
        numAlive += board[row-1][col+1];
    }
    if(row < ROWS-1 && col < COLS-1) {
        numAlive += board[row+1][col+1];
    }
    
    if(board[row][col] == 1) {
        if(numAlive < 2 || numAlive > 3) {
            return 0;
        } else {
            return 1;
        }
    } else {
        if(numAlive == 3) {
            return 1;
        } else {
            return 0;
        }
    }
}

// Function to update the board for the next generation
void updateBoard(int board[ROWS][COLS]) {
    int newBoard[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            newBoard[i][j] = checkCell(board, i, j);
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    printf("Initial State:\n");
    printBoard(board);
    for(int i=1; i<=10; i++) {
        printf("\nGeneration %d:\n", i);
        updateBoard(board);
        printBoard(board);
    }
    return 0;
}