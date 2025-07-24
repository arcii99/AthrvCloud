//FormAI DATASET v1.0 Category: Game of Life ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the board
#define BOARD_SIZE 20

// Define a struct to represent a cell in the board
typedef struct cell {
    int state;
    int next_state;
} cell_t;

// Function declarations
void initialize_board(cell_t board[BOARD_SIZE][BOARD_SIZE]);
void print_board(cell_t board[BOARD_SIZE][BOARD_SIZE]);
int count_live_neighbors(cell_t board[BOARD_SIZE][BOARD_SIZE], int x, int y);

// Main function
int main() {
    cell_t board[BOARD_SIZE][BOARD_SIZE];
    int i, j, k;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    initialize_board(board);

    // Print the initial board
    printf("Initial board:\n");
    print_board(board);

    // Run the game for 50 generations
    for (k = 0; k < 50; k++) {
        // Update each cell's next state based on its neighbors' states
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                int live_neighbors = count_live_neighbors(board, i, j);
                if (board[i][j].state == 0 && live_neighbors == 3) {
                    board[i][j].next_state = 1;
                } else if (board[i][j].state == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                    board[i][j].next_state = 0;
                } else {
                    board[i][j].next_state = board[i][j].state;
                }
            }
        }

        // Update each cell's state based on its next state
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                board[i][j].state = board[i][j].next_state;
            }
        }

        // Print the current board
        printf("\nGeneration %d:\n", k + 1);
        print_board(board);
    }

    return 0;
}

// Function definitions
void initialize_board(cell_t board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j].state = rand() % 2;
        }
    }
}

void print_board(cell_t board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].state == 1 ? '*' : ' ');
        }
        printf("\n");
    }
}

int count_live_neighbors(cell_t board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    int i, j, count = 0;
    for (i = x - 1; i <= x + 1; i++) {
        for (j = y - 1; j <= y + 1; j++) {
            if (!(i == x && j == y) && i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE) {
                if (board[i][j].state == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}