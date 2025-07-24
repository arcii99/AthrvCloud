//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to fill the grid with random numbers
void fillGrid(int grid[ROWS][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 10;
        }
    }
}

// Function to display the grid on the terminal
void displayGrid(int grid[ROWS][COLS], int row, int col) {
    printf(" ");
    for (int j = 0; j < col; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < row; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < col; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int isGameOver(int grid[ROWS][COLS], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int grid[ROWS][COLS];

    fillGrid(grid);
    int moves = 0;

    printf("Welcome to the Scientific Game!\n");
    printf("The objective of the game is to make all the numbers on the grid to 0 by replacing the cells.\n");
    printf("You can replace the cell with the sum of its adjacent cells, i.e., left, right, top, and bottom cells.\n");
    printf("The game is over only when all the numbers on the grid are 0.\n");
    printf("Let's start the game!\n\n");

    while (!isGameOver(grid, ROWS, COLS)) {
        displayGrid(grid, ROWS, COLS);
        int row, col;
        do {
            printf("Enter the row and column number (space separated) of the cell you want to replace: ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
                printf("Invalid row or column number! ");
            } else if (grid[row][col] == 0) {
                printf("You cannot replace a cell that already contains 0! ");
            }
        } while (row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] == 0);

        int sum = 0, count = 0;
        if (row - 1 >= 0) {
            sum += grid[row - 1][col];
            count++;
        }
        if (row + 1 < ROWS) {
            sum += grid[row + 1][col];
            count++;
        }
        if (col - 1 >= 0) {
            sum += grid[row][col - 1];
            count++;
        }
        if (col + 1 < COLS) {
            sum += grid[row][col + 1];
            count++;
        }

        grid[row][col] = sum / count;

        moves++;
    }
    printf("\nCongratulations! You have completed the game in %d moves!\n", moves);
    return 0;
}