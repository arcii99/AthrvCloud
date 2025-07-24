//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Initialize the board randomly
void initialize_board(int board[][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Print the current board
void print_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j] ? '*' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

// Count the neighbors of a cell
int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int r = row + i;
            int c = col + j;
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
                continue;
            }
            count += board[r][c];
        }
    }
    return count;
}

// Apply the rules of Game of Life to update the board
void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j]) { // alive
                if (neighbors == 2 || neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            } else { // dead
                if (neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }

    // Copy the new board back to the original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];

    initialize_board(board);

    for (int i = 0; i < 10; i++) {
        print_board(board);
        update_board(board);
    }

    return 0;
}