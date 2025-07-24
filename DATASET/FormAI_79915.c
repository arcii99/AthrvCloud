//FormAI DATASET v1.0 Category: Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize game board with random values
    int board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2; // 0 or 1
        }
    }

    // Game loop
    while (1) {
        // Print current board state
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Determine next board state
        int next_board[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                // Count number of living neighbors
                int num_neighbors = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if ((k != 0 || l != 0) &&
                            i + k >= 0 && i + k < ROWS && 
                            j + l >= 0 && j + l < COLS &&
                            board[i + k][j + l] == 1) {
                            num_neighbors++;
                        }
                    }
                }

                // Determine if current cell survives, dies, or is born
                if (board[i][j] == 1) {
                    if (num_neighbors < 2 || num_neighbors > 3) {
                        next_board[i][j] = 0; // Dies
                    } else {
                        next_board[i][j] = 1; // Survives
                    }
                } else {
                    if (num_neighbors == 3) {
                        next_board[i][j] = 1; // Born
                    } else {
                        next_board[i][j] = 0; // Stays dead
                    }
                }
            }
        }

        // Update current board state with next board state
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = next_board[i][j];
            }
        }
        
        // Pause between iterations
        printf("\nPress Enter to continue...");
        getchar();
    }

    return 0;
}