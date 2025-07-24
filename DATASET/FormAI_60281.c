//FormAI DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board size
#define WIDTH 20
#define HEIGHT 20

// Define the number of iterations to run the game
#define ITERATIONS 100

// Define the rules for cell birth and survival
#define BIRTH_MIN_NEIGHBORS 3
#define BIRTH_MAX_NEIGHBORS 3
#define SURVIVAL_MIN_NEIGHBORS 2
#define SURVIVAL_MAX_NEIGHBORS 3

// Define the board as a global variable
int board[HEIGHT][WIDTH];

// Function to initialize the board with random values
void initialize_board() {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board
void print_board() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

// Function to get the number of live neighbors for a given cell
int get_live_neighbors(int row, int col) {
    int neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH && !(i == row && j == col)) {
                if (board[i][j] == 1) {
                    neighbors++;
                }
            }
        }
    }
    return neighbors;
}

// Function to update the board based on the rules of the game
void update_board() {
    int new_board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int live_neighbors = get_live_neighbors(i, j);
            if (board[i][j] == 1) {
                if (live_neighbors >= SURVIVAL_MIN_NEIGHBORS && live_neighbors <= SURVIVAL_MAX_NEIGHBORS) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            } else {
                if (live_neighbors >= BIRTH_MIN_NEIGHBORS && live_neighbors <= BIRTH_MAX_NEIGHBORS) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    // Copy the new board to the original board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Initialize the board with random values
    initialize_board();

    // Print the initial board
    printf("Initial Board:\n");
    print_board();

    // Run the game for the specified number of iterations
    for (int i = 1; i <= ITERATIONS; i++) {
        printf("Iteration %d:\n", i);
        update_board();
        print_board();
    }

    return 0;
}