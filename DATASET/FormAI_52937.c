//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#define ROWS 20
#define COLS 20

// Function to initialize the board
void initialize(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // Set all cells to 0
            board[i][j] = 0;
        }
    }
    // Add initial pattern
    board[5][5] = 1;
    board[5][6] = 1;
    board[5][7] = 1;
}

// Function to print the board
void print_board(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors
int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    // Check all 8 neighbors
    if (board[row-1][col-1] == 1) count++;
    if (board[row-1][col] == 1) count++;
    if (board[row-1][col+1] == 1) count++;
    if (board[row][col-1] == 1) count++;
    if (board[row][col+1] == 1) count++;
    if (board[row+1][col-1] == 1) count++;
    if (board[row+1][col] == 1) count++;
    if (board[row+1][col+1] == 1) count++;
    return count;
}

// Function to update the board according to the rules of the game
void update_board(int board[][COLS]) {
    int i, j;
    int new_board[ROWS][COLS];
    // Initialize the new board
    initialize(new_board);
    for (i = 1; i < ROWS-1; i++) {
        for (j = 1; j < COLS-1; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                // Any live cell with fewer than two live neighbors dies
                // Any live cell with more than three live neighbors dies
                new_board[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                // Any dead cell with exactly three live neighbors becomes a live cell
                new_board[i][j] = 1;
            } else {
                // Any other live cell stays alive, and any other dead cell stays dead
                new_board[i][j] = board[i][j];
            }
        }
    }
    // Update the board
    for (i = 1; i < ROWS-1; i++) {
        for (j = 1; j < COLS-1; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// Main function
int main() {
    int board[ROWS][COLS];
    // Initialize the board
    initialize(board);
    while (1) {
        // Print the board
        print_board(board);
        // Update the board
        update_board(board);
    }
    return 0;
}