//FormAI DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void initializeBoard(int board[ROWS][COLS]) {
    // Initialize each cell as 0 or 1 randomly
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void printBoard(int board[ROWS][COLS]) {
    // Print the current state of the board
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int board[ROWS][COLS], int row, int col) {
    // Count the number of living neighbors around a cell
    int count = 0;
    int rowStart = (row == 0) ? row : row - 1;
    int rowEnd = (row == ROWS - 1) ? row : row + 1;
    int colStart = (col == 0) ? col : col - 1;
    int colEnd = (col == COLS - 1) ? col : col + 1;
    for(int i = rowStart; i <= rowEnd; i++) {
        for(int j = colStart; j <= colEnd; j++) {
            if(i == row && j == col) {
                continue;
            }
            count += board[i][j];
        }
    }
    return count;
}

void updateBoard(int board[ROWS][COLS]) {
    // Update the board based on the rules of the Game of Life
    int newBoard[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(board, i, j);
            if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newBoard[i][j] = 0; // Cell dies
            } else if(board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1; // Cell is born
            } else {
                newBoard[i][j] = board[i][j]; // Cell remains as is
            }
        }
    }
    // Copy the new board back to the original board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initializeBoard(board);
    for(int i = 0; i < 100; i++) {
        printBoard(board);
        updateBoard(board);
    }
    return 0;
}