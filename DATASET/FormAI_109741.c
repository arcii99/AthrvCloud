//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

// Function to initialize the game board randomly
void initializeGameBoard(int gameBoard[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = rand() % 2;
        }
    }
}

// Function to print the game board
void printGameBoard(int gameBoard[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (gameBoard[i][j] == 1) {
                printf("@ ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to count the living neighbours of a cell
int countLivingNeighbours(int gameBoard[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int neighbourRow = row + i;
            int neighbourCol = col + j;

            if (neighbourRow < 0) neighbourRow = ROWS - 1;
            if (neighbourRow >= ROWS) neighbourRow = 0;
            if (neighbourCol < 0) neighbourCol = COLS - 1;
            if (neighbourCol >= COLS) neighbourCol = 0;

            if (gameBoard[neighbourRow][neighbourCol] == 1) count++;
        }
    }
    return count;
}

// Function to update the game board
void updateGameBoard(int gameBoard[ROWS][COLS]) {
    int newGameBoard[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int count = countLivingNeighbours(gameBoard, i, j);

            if (gameBoard[i][j] == 1) {
                if (count == 2 || count == 3) {
                    newGameBoard[i][j] = 1;
                } else {
                    newGameBoard[i][j] = 0;
                }
            } else {
                if (count == 3) {
                    newGameBoard[i][j] = 1;
                } else {
                    newGameBoard[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = newGameBoard[i][j];
        }
    }
}

int main(void) {
    srand(time(NULL));

    int gameBoard[ROWS][COLS];
    initializeGameBoard(gameBoard);

    for (int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i + 1);
        printGameBoard(gameBoard);
        printf("\n");
        updateGameBoard(gameBoard);
    }

    return 0;
}