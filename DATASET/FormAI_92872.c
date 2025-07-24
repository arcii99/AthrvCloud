//FormAI DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create the Game of Life board
#define ROWS 20
#define COLS 40
int board[ROWS][COLS];

// Initialize the board with random values
void initialize() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Print the board
void printBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", board[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

// Get the number of live neighbors for a cell
int getLiveNeighbors(int x, int y) {
    int count = 0;
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && (i != x || j != y)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

// Update the board state
void update() {
    int newBoard[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = getLiveNeighbors(i, j);
            newBoard[i][j] = board[i][j];
            if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newBoard[i][j] = 0;
            } else if(board[i][j] == 0 && neighbors == 3) {
                newBoard[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    initialize();
    while(1) {
        printBoard();
        printf("\n");
        update();
        getchar();
        system("clear");
    }
    return 0;
}