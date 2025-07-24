//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 80

void init_board(int board[ROWS][COLS]) {
    // Initialize the board with random values
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    // Print the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int i, int j) {
    // Count the number of live neighbors around cell (i,j)
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            int row = (i + x + ROWS) % ROWS;
            int col = (j + y + COLS) % COLS;
            if (board[row][col] == 1 && !(x == 0 && y == 0)) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    // Update the board according to the rules of the game
    int new_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    // Copy the new board to the old board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    init_board(board);
    for (int i = 0; i < 100; i++) {
        system("clear");
        printf("Generation %d:\n", i+1);
        print_board(board);
        update_board(board);
        usleep(100000); // Sleep for 100ms to slow down the animation
    }
    return 0;
}