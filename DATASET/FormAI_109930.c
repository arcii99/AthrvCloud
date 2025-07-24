//FormAI DATASET v1.0 Category: Game of Life ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20
#define GENERATIONS 100
#define DELAY 100000

// Function to initialize the game board with random values
void initializeBoard(int board[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to display the game board
void displayBoard(int board[HEIGHT][WIDTH]) {
    system("clear"); // Clear the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 1) {
                printf("🟢 ");
            } else {
                printf("⬜️ ");
            }
        }
        printf("\n");
    }
}

// Function to get the value of a cell considering the edges
int getCellValue(int board[HEIGHT][WIDTH], int row, int col) {
    if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) {
        return 0; // Cell is outside the board, return 0
    } else {
        return board[row][col];
    }
}

// Function to count the number of alive neighbors of a cell
int countNeighbors(int board[HEIGHT][WIDTH], int row, int col) {
    int count = 0;
    count += getCellValue(board, row-1, col-1);
    count += getCellValue(board, row-1, col);
    count += getCellValue(board, row-1, col+1);
    count += getCellValue(board, row, col-1);
    count += getCellValue(board, row, col+1);
    count += getCellValue(board, row+1, col-1);
    count += getCellValue(board, row+1, col);
    count += getCellValue(board, row+1, col+1);
    return count;
}

// Function to apply the rules of the game to update the board
void applyRules(int board[HEIGHT][WIDTH]) {
    int tempBoard[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j] == 1) { // Cell is alive
                if (neighbors < 2 || neighbors > 3) {
                    // Cell dies due to underpopulation or overpopulation
                    tempBoard[i][j] = 0;
                } else {
                    // Cell survives
                    tempBoard[i][j] = 1;
                }
            } else { // Cell is dead
                if (neighbors == 3) {
                    // Cell becomes alive due to reproduction
                    tempBoard[i][j] = 1;
                } else {
                    // Cell remains dead
                    tempBoard[i][j] = 0;
                }
            }
        }
    }
    // Copy the temporary board in the original board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = tempBoard[i][j];
        }
    }
}

// Main function
int main() {
    int board[HEIGHT][WIDTH];
    initializeBoard(board);
    for (int i = 0; i < GENERATIONS; i++) {
        displayBoard(board);
        applyRules(board);
        usleep(DELAY);
    }
    return 0;
}