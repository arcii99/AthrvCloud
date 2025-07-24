//FormAI DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 20 

void initialize_board(bool board[][COLS]);
void print_board(bool board[][COLS]);
int count_neighbors(bool board[][COLS], int row, int col);
void update_board(bool board[][COLS]);

int main() {
    bool board[ROWS][COLS];
    srand(time(NULL)); // seed random number generator

    initialize_board(board);
    print_board(board);

    for (int i = 0; i < 10; i++) {
        update_board(board);
        print_board(board);
    }
    return 0;
}

void initialize_board(bool board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = rand() % 2; // randomly assign cell as alive or dead
        }
    }
}

void print_board(bool board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board[row][col] ? 'O' : '.'); // print O for alive cells, . for dead cells
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(bool board[][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;

            if (neighbor_row == row && neighbor_col == col) { // current cell
                continue;
            }
            if (neighbor_row < 0 || neighbor_row >= ROWS) { // out of bounds
                continue;
            }
            if (neighbor_col < 0 || neighbor_col >= COLS) { // out of bounds
                continue;
            }
            if (board[neighbor_row][neighbor_col]) { // neighbor is alive
                count++;
            }
        }
    }
    return count;
}

void update_board(bool board[][COLS]) {
    bool new_board[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(board, row, col);

            if (board[row][col] && (neighbors < 2 || neighbors > 3)) { // alive cell dies
                new_board[row][col] = false;
            }
            else if (!board[row][col] && neighbors == 3) { // dead cell becomes alive
                new_board[row][col] = true;
            }
            else { // cell remains the same
                new_board[row][col] = board[row][col];
            }
        }
    }
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = new_board[row][col]; // update original board
        }
    }
}