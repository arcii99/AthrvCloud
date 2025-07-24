//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

// Initializes the board randomly with live (1) or dead (0) cells
void initialize_board(int board[ROWS][COLS]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j=0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Prints the board as ASCII characters
void print_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Computes the number of live neighbors for a given cell
int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if ((i >= 0) && (i < ROWS) && (j >= 0) && (j < COLS) &&
                    (i != row || j != col)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

// Updates the board for the next generation
void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    for (int i = 1; i <= 10; i++) {
        printf("Generation %d:\n", i);
        print_board(board);
        update_board(board);
    }
    return 0;
}