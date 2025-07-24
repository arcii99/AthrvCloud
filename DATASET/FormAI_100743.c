//FormAI DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define constants
#define ROWS 20
#define COLUMNS 50
#define GENERATIONS 50

// Function prototypes
void print_board(bool board[ROWS][COLUMNS]);
void populate_board(bool board[ROWS][COLUMNS]);
int count_neighbors(bool board[ROWS][COLUMNS], int row, int column);
void next_generation(bool board[ROWS][COLUMNS]);

int main() {
    srand(time(NULL));  // Set random seed

    // Create game board
    bool board[ROWS][COLUMNS];
    populate_board(board);
    print_board(board);

    // Simulate generations
    for (int i = 0; i < GENERATIONS; i++) {
        next_generation(board);
        printf("Generation %d:\n", i+1);
        print_board(board);
    }

    return 0;
}

// Prints the game board
void print_board(bool board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Populates the game board with random cells
void populate_board(bool board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Counts the number of living neighbors of a cell
int count_neighbors(bool board[ROWS][COLUMNS], int row, int column) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int neighbor_row = row + i;
            int neighbor_column = column + j;
            if (neighbor_row < 0 || neighbor_row >= ROWS) continue;
            if (neighbor_column < 0 || neighbor_column >= COLUMNS) continue;
            if (board[neighbor_row][neighbor_column]) count++;
        }
    }
    return count;
}

// Computes the next generation of the game board
void next_generation(bool board[ROWS][COLUMNS]) {
    bool temp_board[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    temp_board[i][j] = false;
                } else {
                    temp_board[i][j] = true;
                }
            } else {
                if (neighbors == 3) {
                    temp_board[i][j] = true;
                } else {
                    temp_board[i][j] = false;
                }
            }
        }
    }
    // Copy the temporary board back to the main board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}