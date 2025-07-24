//FormAI DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Helper functions
void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int count_neighbors(int board[ROWS][COLS], int row, int col);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize board
    int board[ROWS][COLS];
    initialize_board(board);
    printf("Initial board:\n");
    print_board(board);

    // Run game of life for 100 generations
    for (int gen = 1; gen <= 100; gen++) {
        // Create new board for next generation
        int new_board[ROWS][COLS] = {0};

        // Check each cell to determine its fate
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                int num_neighbors = count_neighbors(board, row, col);
                int this_cell = board[row][col];

                // Determine if cell lives or dies
                if (this_cell && (num_neighbors < 2 || num_neighbors > 3)) {
                    new_board[row][col] = 0;
                } else if (!this_cell && num_neighbors == 3) {
                    new_board[row][col] = 1;
                } else {
                    new_board[row][col] = this_cell;
                }
            }
        }

        // Set current board to new board
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                board[row][col] = new_board[row][col];
            }
        }

        // Print current board
        printf("Generation %d:\n", gen);
        print_board(board);
    }

    return 0;
}

void initialize_board(int board[ROWS][COLS]) {
    // Initialize board with random values
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    // Print board to console
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col] ? '#' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    // Count number of live neighbors for a cell
    int count = 0;
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
                continue;
            }
            if (r == row && c == col) {
                continue;
            }
            if (board[r][c]) {
                count++;
            }
        }
    }
    return count;
}