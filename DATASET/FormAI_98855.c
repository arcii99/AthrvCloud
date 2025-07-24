//FormAI DATASET v1.0 Category: Game of Life ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60
#define ALIVE '*'
#define DEAD ' '

// Function prototypes
void initialize_board(char board[ROWS][COLS]);
void print_board(char board[ROWS][COLS]);
void next_generation(char current[ROWS][COLS], char next[ROWS][COLS]);

int main() {
    char current[ROWS][COLS];
    char next[ROWS][COLS];
    
    // Set a random seed for the simulation
    srand(time(NULL));
    
    // Initialize the board
    initialize_board(current);
    
    // Print out the initial board
    print_board(current);
    
    // Run the simulation for 50 generations
    for (int i = 0; i < 50; i++) {
        // Generate the next generation based on the current one
        next_generation(current, next);
        
        // Copy the next generation to the current one
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                current[r][c] = next[r][c];
            }
        }
        
        // Print out the board for this generation
        print_board(current);
    }
    
    return 0;
}

void initialize_board(char board[ROWS][COLS]) {
    // Set all cells to dead
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = DEAD;
        }
    }
    
    // Randomly set some cells to alive
    for (int i = 0; i < (ROWS * COLS) / 3; i++) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        board[r][c] = ALIVE;
    }
}

void print_board(char board[ROWS][COLS]) {
    // Print out the board
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%c", board[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

void next_generation(char current[ROWS][COLS], char next[ROWS][COLS]) {
    int num_neighbors;
    
    // Generate the next generation based on the current one
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            // Calculate the number of live neighbors
            num_neighbors = 0;
            if (r > 0 && c > 0 && current[r - 1][c - 1] == ALIVE) {
                num_neighbors++;
            }
            if (r > 0 && current[r - 1][c] == ALIVE) {
                num_neighbors++;
            }
            if (r > 0 && c < COLS - 1 && current[r - 1][c + 1] == ALIVE) {
                num_neighbors++;
            }
            if (c > 0 && current[r][c - 1] == ALIVE) {
                num_neighbors++;
            }
            if (c < COLS - 1 && current[r][c + 1] == ALIVE) {
                num_neighbors++;
            }
            if (r < ROWS - 1 && c > 0 && current[r + 1][c - 1] == ALIVE) {
                num_neighbors++;
            }
            if (r < ROWS - 1 && current[r + 1][c] == ALIVE) {
                num_neighbors++;
            }
            if (r < ROWS - 1 && c < COLS - 1 && current[r + 1][c + 1] == ALIVE) {
                num_neighbors++;
            }
            
            // Update the cell based on the number of live neighbors
            if (current[r][c] == ALIVE && (num_neighbors == 2 || num_neighbors == 3)) {
                next[r][c] = ALIVE;
            } else if (current[r][c] == DEAD && num_neighbors == 3) {
                next[r][c] = ALIVE;
            } else {
                next[r][c] = DEAD;
            }
        }
    }
}