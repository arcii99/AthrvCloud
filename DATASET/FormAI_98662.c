//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define SIZE 9

int is_valid(int puzzle[SIZE][SIZE], int row, int col, int num);
void print_board(int puzzle[SIZE][SIZE]);
int solve_sudoku(int puzzle[SIZE][SIZE]);

int main()
{
    int puzzle[SIZE][SIZE] = {
        {0, 0, 4, 0, 0, 0, 7, 0, 0},
        {0, 8, 0, 0, 3, 0, 0, 0, 2},
        {0, 0, 0, 7, 0, 0, 0, 8, 0},
        {0, 0, 5, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    printf("Before solving:\n");
    print_board(puzzle);
    
    if (solve_sudoku(puzzle)) {
        printf("\nAfter solving:\n");
        print_board(puzzle);
    } else {
        printf("No solution found.");
    }
    
    return 0;
}

int is_valid(int puzzle[SIZE][SIZE], int row, int col, int num)
{
    // Check if num is already present in row
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[row][i] == num) {
            return 0;
        }
    }
    
    // Check if num is already present in column
    for (int i = 0; i < SIZE; i++) {
        if (puzzle[i][col] == num) {
            return 0;
        }
    }
    
    // Check if num is already present in 3x3 subgrid
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (puzzle[i][j] == num) {
                return 0;
            }
        }
    }
    
    // If num is not present in row, column or subgrid, it is a valid move
    return 1;
}

void print_board(int puzzle[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", puzzle[row][col]);
        }
        printf("\n");
    }
}

int solve_sudoku(int puzzle[SIZE][SIZE])
{
    int row = -1, col = -1, is_empty = 0;
    
    // Check if there is any empty cell in the puzzle
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (puzzle[i][j] == EMPTY) {
                row = i;
                col = j;
                is_empty = 1;
                break;
            }
        }
        if (is_empty) {
            break;
        }
    }
    
    // If there is no empty cell, the puzzle is solved
    if (!is_empty) {
        return 1;
    }
    
    // Try filling numbers from 1 to 9 in empty cell
    for (int num = 1; num <= 9; num++) {
        if (is_valid(puzzle, row, col, num)) {
            puzzle[row][col] = num;
            
            // Recursive call to solve the remaining puzzle
            if (solve_sudoku(puzzle)) {
                return 1;
            }
            
            // If the above recursive call failed, backtrack and try another number
            puzzle[row][col] = EMPTY;
        }
    }
    
    // If none of the numbers worked, the puzzle has no solution
    return 0;
}