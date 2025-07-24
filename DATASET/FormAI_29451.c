//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];  // declaring the sudoku board

// Function to print current state of the board
void print_board() {
    printf("-------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0) printf("| ");
        }
        printf("\n");
        if ((i + 1) % 3 == 0) printf("-------------------------\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int num, int row, int col) {
    // Check if num exists in row
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) return 0;
    }
    // Check if num exists in col
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) return 0;
    }
    // Check if num exists in 3x3 box
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) return 0;
        }
    }
    return 1;  // if num can be placed in given row, col
}

// Function to solve the sudoku puzzle using backtracking algorithm
int solve_sudoku() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {  // if cell is empty
                for (int k = 1; k <= SIZE; k++) {  // try each number
                    if (is_valid_move(k, i, j)) {  // check if number can be placed
                        board[i][j] = k;
                        if (solve_sudoku()) return 1;
                        board[i][j] = 0;
                    }
                }
                return 0;  // if no number can be placed, backtrack
            }
        }
    }
    return 1;  // if board is filled, solution is found
}

// Function to initialize the sudoku board
void initialize_board() {
    // Enter the puzzle configuration here
    int puzzle[SIZE][SIZE] = {
        {0, 9, 0, 0, 0, 0, 8, 5, 3},
        {0, 0, 0, 8, 0, 0, 0, 0, 4},
        {0, 0, 8, 2, 0, 3, 0, 6, 9},
        {5, 7, 4, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 0, 6, 3, 7},
        {9, 4, 0, 1, 0, 8, 5, 0, 0},
        {7, 0, 0, 0, 0, 6, 0, 0, 0},
        {6, 8, 2, 0, 0, 0, 0, 1, 0}
    };
    // Copy puzzle to board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = puzzle[i][j];
        }
    }
}

int main() {
    initialize_board();
    printf("Puzzle:\n");
    print_board();
    if (solve_sudoku()) {
        printf("Solution:\n");
        print_board();
    } else {
        printf("No solution found.\n");
    }
    return 0;
}