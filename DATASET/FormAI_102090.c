//FormAI DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 20

// Function to initialize the game board
void initBoard(int board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the game board
void printBoard(int board[HEIGHT][WIDTH]) {
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 0) {
                printf(".");
            }
            else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors
int countNeighbors(int board[HEIGHT][WIDTH], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            // Check if the cell is not out of bounds
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
                // Check if the cell is a live cell
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    // We need to subtract the current cell from the count
    count -= board[row][col];
    return count;
}

// Function to update the game board
void updateBoard(int board[HEIGHT][WIDTH]) {
    int newBoard[HEIGHT][WIDTH] = {{0}};
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(board, i, j);
            // Check if the cell is alive
            if (board[i][j] == 1) {
                // Check the number of live neighbors
                if (neighbors < 2 || neighbors > 3) {
                    // Cell dies due to underpopulation or overpopulation
                    newBoard[i][j] = 0;
                }
                else {
                    // Cell survives to the next generation
                    newBoard[i][j] = 1;
                }
            }
            else {
                // Cell is dead
                if (neighbors == 3) {
                    // Cell becomes alive due to reproduction
                    newBoard[i][j] = 1;
                }
            }
        }
    }
    // Copy the new board to the old board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    // Initialize the random number generator
    srand(time(NULL));
    // Initialize the game board
    initBoard(board);
    // Start the game loop
    int generation = 1;
    while (1) {
        printf("Generation: %d\n", generation++);
        printBoard(board);
        updateBoard(board);
        // Wait for 1 second before updating the board again
        usleep(1000000);
    }
    return 0;
}