//FormAI DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 10
#define COLS 10
#define GENERATIONS 20

// Function Declarations
void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize board
    int board[ROWS][COLS];
    init_board(board);
    
    // Print starting board
    printf("Starting Board:\n");
    print_board(board);
    
    // Run through generations
    for (int gen = 1; gen <= GENERATIONS; gen++) {
        printf("Generation %d:\n", gen);
        update_board(board);
        print_board(board);
    }
    
    return 0;
}

// Initializes board with random cells
void init_board(int board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2;
        }
    }
}

// Prints the current state of the board
void print_board(int board[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

// Updates the board to the next generation
void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int live_neighbors = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int neighbor_row = row + i;
                    int neighbor_col = col + j;
                    if (neighbor_row >= 0 && neighbor_row < ROWS && neighbor_col >= 0 && neighbor_col < COLS) {
                        live_neighbors += board[neighbor_row][neighbor_col];
                    }
                }
            }
            live_neighbors -= board[row][col];
            if (board[row][col] == 1 && live_neighbors < 2) {
                new_board[row][col] = 0;
            } else if (board[row][col] == 1 && live_neighbors > 3) {
                new_board[row][col] = 0;
            } else if (board[row][col] == 0 && live_neighbors == 3) {
                new_board[row][col] = 1;
            } else {
                new_board[row][col] = board[row][col];
            }
        }
    }
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = new_board[row][col];
        }
    }
}