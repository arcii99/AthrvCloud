//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

int grid[ROWS][COLS];

// Function to initialize the game board
void init_board() {
    srand(time(NULL));
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the game board
void print_board() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to check if a cell is alive or dead
int is_alive(int row, int col) {
    int count = 0;
    for (int i=row-1; i<=row+1; i++) {
        for (int j=col-1; j<=col+1; j++) {
            if (i>=0 && i<ROWS && j>=0 && j<COLS && !(i==row && j==col)) {
                count += grid[i][j];
            }
        }
    }
    if (grid[row][col] == 1 && (count == 2 || count == 3)) {
        return 1;
    } else if (grid[row][col] == 0 && count == 3) {
        return 1;
    } else {
        return 0;
    }
}

// Function to update the game board
void update_board() {
    int new_grid[ROWS][COLS];
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            new_grid[i][j] = is_alive(i,j);
        }
    }
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// Main function to run the Game of Life
int main() {
    init_board();
    int generations = 10;
    for (int i=0; i<generations; i++) {
        printf("Generation %d:\n", i+1);
        print_board();
        update_board();
    }
    return 0;
}