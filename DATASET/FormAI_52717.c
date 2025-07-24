//FormAI DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

void print_board(bool board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", board[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int count_live_neighbors(bool board[ROWS][COLUMNS], int row, int column) {
    int count = 0;
    int start_row = row - 1 < 0 ? 0 : row - 1; 
    int start_column = column - 1 < 0 ? 0 : column - 1; 
    int end_row = row + 1 > ROWS - 1 ? ROWS - 1 : row + 1; 
    int end_column = column + 1 > COLUMNS - 1 ? COLUMNS - 1 : column + 1; 

    for (int i = start_row; i <= end_row; i++) {        
        for (int j = start_column; j <= end_column; j++) {    
            if (board[i][j] && !(i == row && j == column))
                count++;
        }
    }

    return count;
}

bool check_cell_rule(bool board[ROWS][COLUMNS], int row, int column) {
    int live_neighbors = count_live_neighbors(board, row, column);

    if (board[row][column] && (live_neighbors < 2 || live_neighbors > 3)) {
        // Any live cell with fewer than two live neighbors dies, as if by underpopulation.
        // Any live cell with more than three live neighbors dies, as if by overpopulation.
        return false;
    } else if (!board[row][column] && live_neighbors == 3) {
        // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
        return true;
    } else {
        return board[row][column];
    }
}

void next_generation(bool board[ROWS][COLUMNS], int row, int column) {
    bool next_board[ROWS][COLUMNS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            next_board[i][j] = check_cell_rule(board, i, j);
        }
    }

    print_board(next_board);
    next_generation(next_board, row, column);
}

int main() {
    bool board[ROWS][COLUMNS] = {
        {false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false},
        {false, false, false, true, true, true, false, false, false, false},
        {false, false, false, true, false, true, false, false, false, false},
        {false, false, false, true, true, true, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false, false},
    };

    print_board(board);
    next_generation(board, 0, 0);

    return 0;
}