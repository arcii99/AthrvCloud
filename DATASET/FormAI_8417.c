//FormAI DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50
#define ALIVE 1
#define DEAD 0

/**
 * Generate initial game board with random alive cells
 */
void init_board(int board[][COLS]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

/**
 * Get the number of neighbours around the given cell
 */
int get_neighbour_count(int board[][COLS], int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                if (board[i][j] == ALIVE && !(i == row && j == col)) {
                    count++;
                }
            }
        }
    }
    return count;
}

/**
 * Check if a cell should be alive or dead in the next generation
 */
int get_next_state(int board[][COLS], int row, int col) {
    int neighbours = get_neighbour_count(board, row, col);
    if (neighbours < 2 || neighbours > 3) {
        return DEAD;
    }
    if (neighbours == 3) {
        return ALIVE;
    }
    return board[row][col];
}

/**
 * Update the game board to the next generation
 */
void update_board(int board[][COLS]) {
    int i, j;
    int next_board[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            next_board[i][j] = get_next_state(board, i, j);
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

/**
 * Print the game board as a matrix of asterisks
 */
void print_board(int board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == ALIVE) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    init_board(board);
    while (1) {
        system("clear");
        print_board(board);
        update_board(board);
        usleep(50000);
    }
    return 0;
}