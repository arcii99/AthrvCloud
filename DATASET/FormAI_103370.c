//FormAI DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>

// Define the size of the Sudoku board
#define N 9

/* Define a struct for the board cells */
typedef struct {
    int row;
    int col;
    int value;
} cell;

/* Define a function to print the board */
void print_board(cell board[N][N]) {
    printf("  _______________________________________\n");
    for (int i=0; i<N; i++) {
        printf(" |");
        for (int j=0; j<N; j++) {
            if (board[i][j].value == 0) {
                printf("   |");
            }
            else {
                printf(" %d |", board[i][j].value);
            }
        }
        printf("\n");
        printf(" |___|___|___|___|___|___|___|___|___|\n");
    }
}

/* Define a function to check if a value can be placed in a cell */
int is_valid(cell board[N][N], int row, int col, int value) {
    // Check row and column
    for (int i=0; i<N; i++) {
        if (board[row][i].value == value) return 0;
        if (board[i][col].value == value) return 0;
    }
    // Check box
    int box_row = row / 3 * 3;
    int box_col = col / 3 * 3;
    for (int i=box_row; i<box_row+3; i++) {
        for (int j=box_col; j<box_col+3; j++) {
            if (board[i][j].value == value) return 0;
        }
    }
    // If none of the checks fail, value can be placed in cell
    return 1;
}

/* Define the main solve function */
int solve(cell board[N][N], int row, int col) {
    // If we reached the end of the row, move to the next row
    if (col == N) {
        row++;
        col = 0;
        if (row == N) {
            // If we reached the end of the board, the Sudoku is solved
            return 1;
        }
    }
    // If this cell already has a value, move to the next cell
    if (board[row][col].value != 0) {
        return solve(board, row, col+1);
    }
    // Try all possible values in the cell
    for (int i=1; i<=N; i++) {
        if (is_valid(board, row, col, i)) {
            board[row][col].value = i;
            // If the value leads to a valid solution, return 1
            if (solve(board, row, col+1)) {
                return 1;
            }
        }
    }
    // If no value leads to a valid solution, backtrack
    board[row][col].value = 0;
    return 0;
}

int main() {
    // Define the starting board
    cell board[N][N] = {
        {{0,0,0},{0,6,0},{0,0,0}},
        {{1,0,0},{0,0,7},{0,9,6}},
        {{0,3,0},{0,0,5},{0,8,1}},
        {{0,0,0},{0,0,3},{0,0,7}},
        {{0,0,7},{0,4,0},{0,0,0}},
        {{6,0,0},{1,0,0},{0,0,5}},
        {{0,0,4},{0,0,0},{0,0,0}},
        {{0,9,0},{0,0,0},{0,2,0}},
        {{3,1,0},{0,0,0},{0,0,0}}
    };
    // Print the starting board
    printf("Welcome to the Medieval Sudoku Solver!\n");
    printf("Here is your starting board:\n");
    print_board(board);
    // Solve the Sudoku
    if (solve(board, 0, 0)) {
        printf("Congratulations, your Sudoku has been solved!\n");
        print_board(board);
    }
    else {
        printf("Sorry, your Sudoku could not be solved.\n");
    }
    return 0;
}