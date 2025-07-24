//FormAI DATASET v1.0 Category: Sudoku solver ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define BOARD_SIZE 9
#define SUB_GRID_SIZE 3
#define EMPTY_CELL 0
#define MAX_SOLUTIONS 10

int board[BOARD_SIZE][BOARD_SIZE];
int solutions[MAX_SOLUTIONS][BOARD_SIZE][BOARD_SIZE];
int num_solutions = 0;
bool finished = false;

// Struct to hold data for each thread
typedef struct {
    int row;
    int col;
} thread_data;

// Check if a number can be placed at a given cell
bool valid_placement(int num, int row, int col) {
    // Check row and column
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    
    // Check sub-grid
    int sub_grid_row = (row / SUB_GRID_SIZE) * SUB_GRID_SIZE;
    int sub_grid_col = (col / SUB_GRID_SIZE) * SUB_GRID_SIZE;
    for (int i = sub_grid_row; i < sub_grid_row + SUB_GRID_SIZE; i++) {
        for (int j = sub_grid_col; j < sub_grid_col + SUB_GRID_SIZE; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

// Solve Sudoku board using backtracking algorithm
void* solve_board(void* data_void) {
    thread_data data = *(thread_data*) data_void;
    int row = data.row;
    int col = data.col;
    
    // Initialize next row and column values
    int next_row = row;
    int next_col = col + 1;
    if (next_col == BOARD_SIZE) {
        next_row = row + 1;
        next_col = 0;
    }
    
    if (board[row][col] != EMPTY_CELL) {
        // Cell is already filled, move on to next cell
        if (next_row == BOARD_SIZE) {
            // Board is completely filled and a solution is found
            if (num_solutions < MAX_SOLUTIONS) {
                // Save solution
                for (int i = 0; i < BOARD_SIZE; i++) {
                    for (int j = 0; j < BOARD_SIZE; j++) {
                        solutions[num_solutions][i][j] = board[i][j];
                    }
                }
                num_solutions++;
            }
            else {
                // Maximum number of solutions reached, stop searching
                finished = true;
            }
            return NULL;
        }
        else {
            // Recursively move to next cell
            thread_data next_data = {next_row, next_col};
            solve_board(&next_data);
        }
    }
    else {
        // Cell is empty, try placing numbers 1-9
        for (int i = 1; i <= BOARD_SIZE; i++) {
            if (valid_placement(i, row, col)) {
                // Place number and recursively move to next cell
                board[row][col] = i;
                if (next_row == BOARD_SIZE) {
                    // Board is completely filled and a solution is found
                    if (num_solutions < MAX_SOLUTIONS) {
                        // Save solution
                        for (int i = 0; i < BOARD_SIZE; i++) {
                            for (int j = 0; j < BOARD_SIZE; j++) {
                                solutions[num_solutions][i][j] = board[i][j];
                            }
                        }
                        num_solutions++;
                    }
                    else {
                        // Maximum number of solutions reached, stop searching
                        finished = true;
                    }
                }
                else {
                    // Recursively move to next cell
                    thread_data next_data = {next_row, next_col};
                    solve_board(&next_data);
                }
                // Remove number to backtrack
                if (!finished) {
                    board[row][col] = EMPTY_CELL;
                }
            }
        }
    }
    
    return NULL;
}

// Print Sudoku board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize board with example puzzle
    int example_board[BOARD_SIZE][BOARD_SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = example_board[i][j];
        }
    }
    
    // Initialize thread variables
    pthread_t threads[BOARD_SIZE][BOARD_SIZE];
    thread_data data[BOARD_SIZE][BOARD_SIZE];
    
    // Create and start threads for each cell on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            data[i][j] = (thread_data) {i, j};
            int result = pthread_create(&threads[i][j], NULL, solve_board, &data[i][j]);
            if (result != 0) {
                printf("Error creating thread at row %d, column %d\n", i, j);
                return 1;
            }
        }
    }
    
    // Join threads to wait for all solutions to be found or maximum number of solutions is reached
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int result = pthread_join(threads[i][j], NULL);
            if (result != 0) {
                printf("Error joining thread at row %d, column %d\n", i, j);
                return 1;
            }
        }
    }
    
    // Print all found solutions
    printf("\nFound %d solutions:\n", num_solutions);
    for (int i = 0; i < num_solutions; i++) {
        print_board(solutions[i]);
    }
    
    return 0;
}