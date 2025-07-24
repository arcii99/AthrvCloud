//FormAI DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 50

void init_board(int board[][COL]) {
    // Set all cells to dead initially
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = 0;
        }
    }
    // Randomly set some cells to alive
    srand(time(NULL));  // Seed the random generator
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int r = rand() % 100;  // Generate a random number between 0 and 99
            if (r < 20) {  // 20% chance of a cell being alive initially
                board[i][j] = 1;
            }
        }
    }
}

void print_board(int board[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == 1) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[][COL], int row, int col) {
    int count = 0;
    // Check neighbors to the left, right, top, and bottom
    if (col > 0 && board[row][col-1] == 1) {
        count++;
    }
    if (col < COL-1 && board[row][col+1] == 1) {
        count++;
    }
    if (row > 0 && board[row-1][col] == 1) {
        count++;
    }
    if (row < ROW-1 && board[row+1][col] == 1) {
        count++;
    }
    // Check diagonal neighbors
    if (row > 0 && col > 0 && board[row-1][col-1] == 1) {
        count++;
    }
    if (row > 0 && col < COL-1 && board[row-1][col+1] == 1) {
        count++;
    }
    if (row < ROW-1 && col > 0 && board[row+1][col-1] == 1) {
        count++;
    }
    if (row < ROW-1 && col < COL-1 && board[row+1][col+1] == 1) {
        count++;
    }
    return count;
}

void update_board(int board[][COL]) {
    int new_board[ROW][COL];
    // Copy the board to a new board to avoid updating in place
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            new_board[i][j] = board[i][j];
        }
    }
    // Update each cell based on its neighbors
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int count = count_neighbors(board, i, j);
            if (board[i][j] == 1) {
                if (count < 2 || count > 3) {
                    new_board[i][j] = 0;  // Die due to under/overpopulation
                }
            }
            else {
                if (count == 3) {
                    new_board[i][j] = 1;  // Birth due to reproduction
                }
            }
        }
    }
    // Copy the new board back to the original board
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROW][COL];
    init_board(board);
    while (1) {
        print_board(board);
        update_board(board);
        printf("\033[%dA",ROW);
        fflush(stdout);  // Flush stdout to update the output immediately
    }
    return 0;
}