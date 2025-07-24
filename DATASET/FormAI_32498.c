//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 20
#define COLS 40
#define MAX_LIFE 5

// Function prototypes
void initialize_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
void evolve_board(int board[ROWS][COLS]);

int main(void) {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize board
    int board[ROWS][COLS];
    initialize_board(board);

    // Print initial board
    print_board(board);

    // Evolve board continuously
    while (1) {
        // Sleep for a short time (for visual effect)
        usleep(100000);

        // Clear screen
        system("clear");

        // Evolve board
        evolve_board(board);

        // Print board
        print_board(board);
    }

    return 0;
}

void initialize_board(int board[ROWS][COLS]) {
    // Iterate over board and assign random life
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % MAX_LIFE; // Assign random life (0~MAX_LIFE-1)
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    // Iterate over board and print visual representation
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(" "); // Dead cell
                    break;
                case 1:
                    printf("."); // Simple lifeform
                    break;
                case 2:
                    printf("*"); // Complex lifeform
                    break;
                case 3:
                    printf("#"); // Large lifeform
                    break;
                case 4:
                    printf("+"); // Shapeshifting lifeform
                    break;
                default:
                    printf("?"); // Unknown lifeform
                    break;
            }
        }
        printf("\n");
    }
}

void evolve_board(int board[ROWS][COLS]) {
    // Iterate over board and apply Game of Life rules
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count neighbors
            int neighbors = 0;
            for (int ii = i-1; ii <= i+1; ii++) {
                for (int jj = j-1; jj <= j+1; jj++) {
                    if (ii < 0 || ii >= ROWS) continue; // Out of bounds
                    if (jj < 0 || jj >= COLS) continue; // Out of bounds
                    if (ii == i && jj == j) continue; // Current cell
                    if (board[ii][jj] > 0) neighbors++; // Alive cell
                }
            }

            // Apply rules
            if (board[i][j] > 0 && (neighbors < 2 || neighbors > 3)) {
                board[i][j] = 0; // Overpopulation or isolation
            } else if (board[i][j] == 0 && neighbors == 3) {
                board[i][j] = rand() % MAX_LIFE; // Birth
            } else if (board[i][j] == 4) {
                board[i][j] = rand() % MAX_LIFE; // Shapeshift
            }
        }
    }
}