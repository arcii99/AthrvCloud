//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include<stdio.h>

// Function to print the Sudoku
void print(int grid[9][9]){
    printf("\n-------------------------\n");
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf(" %d ", grid[i][j]);
            if ((j + 1) % 3 == 0)
                printf("|");
        }
        if ((i + 1) % 3 == 0){
            printf("\n-------------------------");
        }
        printf("\n");
    }
    printf("\n\n");
}

// Function to check if the cell is empty
int is_empty(int grid[9][9], int *row, int *col){
    for (*row = 0; *row < 9; (*row)++){
        for (*col = 0; *col < 9; (*col)++){
            if (grid[*row][*col] == 0){
                return 1;
            }
        }
    }
    return 0;
}

// Function to check the row if number already exists
int used_in_row(int grid[9][9], int row, int num){
    for (int col = 0; col < 9; col++){
        if (grid[row][col] == num){
            return 1;
        }
    }
    return 0;
}

// Function to check the column if number already exists
int used_in_col(int grid[9][9], int col, int num){
    for (int row = 0; row < 9; row++){
        if (grid[row][col] == num){
            return 1;
        }
    }
    return 0;
}

// Function to check the grid if number already exists
int used_in_grid(int grid[9][9], int start_row, int start_col, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (grid[row + start_row][col + start_col] == num){
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the number is valid or not
int is_valid(int grid[9][9], int row, int col, int num){
    return !used_in_row(grid, row, num) && !used_in_col(grid, col, num) && !used_in_grid(grid, row - row % 3, col - col % 3, num);
}

// Function to solve Sudoku
int solve_sudoku(int grid[9][9]){
    int row, col;
    if (!is_empty(grid, &row, &col)){
        return 1;
    }
    for (int num = 1; num <= 9; num++){
        if (is_valid(grid, row, col, num)){
            grid[row][col] = num;
            if (solve_sudoku(grid)){
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main(){
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 0, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    printf("Sudoku before solving:\n\n");
    print(grid);
    if (solve_sudoku(grid)){
        printf("Sudoku after solving:\n\n");
        print(grid);
    }
    else{
        printf("No solution found\n");
    }
    return 0;
}