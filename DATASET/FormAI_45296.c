//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
// A Sudoku Solver Program in C

#include<stdio.h>
#include<stdlib.h>

// Define the board size
#define N 9

// Function to check if a number can be placed in the given cell
int isSafe(int board[N][N], int row, int col, int num)
{
    // Check if the number is present in the row
    for (int i = 0; i < N; i++)
        if (board[row][i] == num)
            return 0;
    
    // Check if the number is present in the column
    for (int i = 0; i < N; i++)
        if (board[i][col] == num)
            return 0;
    
    // Check if the number is present in the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return 0;
    
    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku(int board[N][N], int row, int col)
{
    // Base case: if all cells are filled, puzzle is solved
    if (row == N - 1 && col == N)
        return 1;
    
    // If a row is filled, move to next row
    if (col == N)
    {
        row++;
        col = 0;
    }
    
    // If the cell is already filled, move to next cell
    if (board[row][col] != 0)
        return solveSudoku(board, row, col + 1);
    
    // Try all valid numbers in the cell
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(board, row, col, num))
        {
            // Place the number in the cell
            board[row][col] = num;
            
            // Recursively solve the puzzle
            if (solveSudoku(board, row, col + 1))
                return 1;
            
            // If puzzle cannot be solved with the current number, backtrack
            board[row][col] = 0;
        }
    }
    
    // If no valid number can be placed in the cell, backtrack
    return 0;
}

int main()
{
    // Sample Sudoku puzzle
    int board[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    
    // Solve the puzzle
    if (solveSudoku(board, 0, 0))
    {
        // Print the solved puzzle
        printf("Solution:\n");
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
    else
        printf("No solution exists");
    
    return 0;
}