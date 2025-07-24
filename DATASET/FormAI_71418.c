//FormAI DATASET v1.0 Category: Sudoku solver ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

typedef struct {
    int row;
    int column;
} cell_t;

bool find_empty_cell(int board[][BOARD_SIZE], cell_t *cell) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
            if (board[row][column] == 0) {
                cell->row = row;
                cell->column = column;
                return true;
            }
        }
    }
    return false;
}

bool is_valid_number(int board[][BOARD_SIZE], cell_t cell, int number) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[cell.row][i] == number || board[i][cell.column] == number) {
            return false;
        }
    }

    int subgrid_size = 3;
    int subgrid_row = (cell.row / subgrid_size) * subgrid_size;
    int subgrid_column = (cell.column / subgrid_size) * subgrid_size;
    for (int row = subgrid_row; row < subgrid_row + subgrid_size; row++) {
        for (int column = subgrid_column; column < subgrid_column + subgrid_size; column++) {
            if (board[row][column] == number) {
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int board[][BOARD_SIZE]) {
    cell_t cell;
    if (!find_empty_cell(board, &cell)) {
        return true;
    }

    for (int number = 1; number <= BOARD_SIZE; number++) {
        if (is_valid_number(board, cell, number)) {
            board[cell.row][cell.column] = number;
            if (solve_sudoku(board)) {
                return true;
            }
            board[cell.row][cell.column] = 0;
        }
    }

    return false;
}

void print_board(int board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
            printf("%d ", board[row][column]);
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
            {0, 3, 0, 0, 0, 7, 5, 0, 0},
            {5, 0, 0, 0, 9, 0, 0, 0, 6},
            {0, 9, 8, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 2, 0},
            {0, 0, 0, 0, 5, 0, 1, 0, 0},
            {0, 0, 0, 4, 0, 0, 0, 0, 9},
            {1, 0, 0, 7, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 4, 0, 0, 1, 8, 0, 0, 0}
    };

    if (solve_sudoku(board)) {
        print_board(board);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}