//FormAI DATASET v1.0 Category: Game of Life ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Game of Life constants
#define ROWS 10
#define COLS 20
#define MAX_GEN 100

// Function declarations
void print_board(int board[][COLS], int gen);
void initialize_board(int board[][COLS]);
void update_board(int board[][COLS]);

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize board to all zeros
    int board[ROWS][COLS] = {0};
    
    // Initialize board with random living cells
    initialize_board(board);
    
    // Print initial board
    print_board(board, 0);
    
    // Run simulation for specified number of generations
    for (int i = 1; i <= MAX_GEN; i++) {
        update_board(board);
        print_board(board, i);
    }
    
    return 0;
}

// Function to print board to console
void print_board(int board[][COLS], int gen)
{
    printf("Generation %d:\n", gen);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] == 1 ? 'X' : '.');
        }
        printf("\n");
    }
    
    printf("\n");
}

// Function to initialize board with random living cells
void initialize_board(int board[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to update board for next generation
void update_board(int board[][COLS])
{
    // Copy board to temporary board
    int temp_board[ROWS][COLS];
    memcpy(temp_board, board, sizeof(board));
    
    // Update each cell based on Game of Life rules
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count number of living neighbors
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        // Current cell is not a neighbor
                        continue;
                    }
                    
                    int row = (i + x + ROWS) % ROWS;
                    int col = (j + y + COLS) % COLS;
                    
                    if (board[row][col] == 1) {
                        // Neighbor is living
                        neighbors++;
                    }
                }
            }
            
            // Determine new state of cell based on number of neighbors
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                // Living cell dies
                temp_board[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                // Dead cell becomes alive
                temp_board[i][j] = 1;
            }
        }
    }
    
    // Copy temporary board back to original board
    memcpy(board, temp_board, sizeof(board));
}