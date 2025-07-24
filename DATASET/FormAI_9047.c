//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 30

// The board is a 2D array of cells, represented as 0 or 1
int board[WIDTH][HEIGHT];

// Function to initialize the board with random values
void initBoard() {
    srand(time(NULL));
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to get the number of living neighbors for a given cell
int getNumNeighbors(int x, int y) {
    int numNeighbors = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || i >= WIDTH || j < 0 || j >= HEIGHT) {
                continue;
            }
            if (i == x && j == y) {
                continue;
            }
            if (board[i][j] == 1) {
                numNeighbors++;
            }
        }
    }
    return numNeighbors;
}

// Function to update the board based on the Game of Life rules
void updateBoard() {
    int newBoard[WIDTH][HEIGHT];
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int numNeighbors = getNumNeighbors(i, j);
            if (board[i][j] == 1) {
                if (numNeighbors < 2 || numNeighbors > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if (numNeighbors == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    // Initialize the board
    initBoard();

    // Run the Game of Life
    for (int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i);
        printBoard();
        updateBoard();
    }

    return 0;
}