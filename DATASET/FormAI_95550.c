//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

typedef struct cell {
    int row;
    int col;
    int value;
    bool fixed;
} Cell;

typedef struct board {
    Cell cells[SIZE][SIZE];
} Board;

Board init_board(Cell cells[SIZE][SIZE]) {
    Board board;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board.cells[i][j] = cells[i][j];
        }
    }
    return board;
}

bool can_place_value(Board board, int row, int col, int value) {
    if (board.cells[row][col].fixed) {
        return false;
    }

    for (int i = 0; i < SIZE; i++) {
        // Check row
        if (board.cells[row][i].value == value) {
            return false;
        }
        // Check column
        if (board.cells[i][col].value == value) {
            return false;
        }
    }

    // Check subgrid
    int subgrid_row = row / 3 * 3;
    int subgrid_col = col / 3 * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (board.cells[i][j].value == value) {
                return false;
            }
        }
    }

    return true;
}

bool solve(Board *board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board->cells[row][col].value == 0) {
                for (int value = 1; value <= SIZE; value++) {
                    if (can_place_value(*board, row, col, value)) {
                        board->cells[row][col].value = value;
                        if (solve(board)) {
                            return true;
                        }
                        board->cells[row][col].value = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void print_board(Board board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board.cells[i][j].value);
        }
        printf("\n");
    }
}

int main() {
    Cell cells[SIZE][SIZE] = {
        {{0, 0, 0, false}, {0, 1, 0, false}, {0, 2, 0, false}, {0, 3, 9, true}, {0, 4, 0, false}, {0, 5, 0, false}, {0, 6, 0, false}, {0, 7, 0, false}, {0, 8, 2, true}},
        {{1, 0, 0, false}, {1, 1, 5, true}, {1, 2, 0, false}, {1, 3, 0, false}, {1, 4, 8, true}, {1, 5, 7, true}, {1, 6, 0, false}, {1, 7, 0, false}, {1, 8, 0, false}},
        {{2, 0, 0, false}, {2, 1, 0, false}, {2, 2, 6, true}, {2, 3, 0, false}, {2, 4, 0, false}, {2, 5, 0, false}, {2, 6, 7, true}, {2, 7, 0, false}, {2, 8, 4, true}},
        {{3, 0, 4, true}, {3, 1, 0, false}, {3, 2, 8, true}, {3, 3, 0, false}, {3, 4, 0, false}, {3, 5, 0, false}, {3, 6, 0, false}, {3, 7, 1, true}, {3, 8, 0, false}},
        {{4, 0, 6, true}, {4, 1, 1, true}, {4, 2, 3, true}, {4, 3, 7, true}, {4, 4, 0, false}, {4, 5, 0, false}, {4, 6, 0, false}, {4, 7, 0, false}, {4, 8, 8, true}},
        {{5, 0, 0, false}, {5, 1, 0, false}, {5, 2, 0, false}, {5, 3, 0, false}, {5, 4, 0, false}, {5, 5, 0, false}, {5, 6, 0, false}, {5, 7, 0, false}, {5, 8, 3, true}},
        {{6, 0, 0, false}, {6, 1, 7, true}, {6, 2, 5, true}, {6, 3, 0, false}, {6, 4, 0, false}, {6, 5, 0, false}, {6, 6, 1, true}, {6, 7, 0, false}, {6, 8, 0, false}},
        {{7, 0, 0, false}, {7, 1, 0, false}, {7, 2, 0, false}, {7, 3, 2, true}, {7, 4, 6, true}, {7, 5, 0, false}, {7, 6, 0, false}, {7, 7, 7, true}, {7, 8, 0, false}},
        {{8, 0, 1, true}, {8, 1, 0, false}, {8, 2, 0, false}, {8, 3, 0, false}, {8, 4, 0, false}, {8, 5, 0, false}, {8, 6, 0, false}, {8, 7, 0, false}, {8, 8, 0, false}}
    };

    Board board = init_board(cells);

    printf("Original board:\n");
    print_board(board);

    if (solve(&board)) {
        printf("\nSolution:\n");
        print_board(board);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}