//FormAI DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 50

void draw_board(int board[][COLS]);
int count_neighbors(int board[][COLS], int row, int col);
void update_board(int board[][COLS]);

int main() {
    srand(time(NULL)); // initialize random seed
    int board[ROWS][COLS] = {}; // initialize board to all zeros

    // randomly place living cells on board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (rand() % 2 == 0) {
                board[row][col] = 1; // set cell to living
            }
        }
    }

    // run game of life
    for (int i = 0; i < 100; i++) {
        system("clear"); // clear terminal screen
        draw_board(board); // display current board
        update_board(board); // update board based on rules
    }

    return 0;
}

void draw_board(int board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == 1) {
                printf("*"); // living cell
            } else {
                printf(" "); // dead cell
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;

    // check north, south, east, west
    if (row > 0 && board[row-1][col] == 1) { // north
        count++;
    }
    if (row < ROWS-1 && board[row+1][col] == 1) { // south
        count++;
    }
    if (col > 0 && board[row][col-1] == 1) { // west
        count++;
    }
    if (col < COLS-1 && board[row][col+1] == 1) { // east
        count++;
    }

    // check diagonal directions
    if (row > 0 && col > 0 && board[row-1][col-1] == 1) { // northwest
        count++;
    }
    if (row > 0 && col < COLS-1 && board[row-1][col+1] == 1) { // northeast
        count++;
    }
    if (row < ROWS-1 && col > 0 && board[row+1][col-1] == 1) { // southwest
        count++;
    }
    if (row < ROWS-1 && col < COLS-1 && board[row+1][col+1] == 1) { // southeast
        count++;
    }

    return count;
}

void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS] = {}; // initialize new board to all zeros

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int neighbors = count_neighbors(board, row, col);
            if (board[row][col] == 1) { // living cell
                if (neighbors < 2 || neighbors > 3) {
                    // cell dies due to underpopulation or overcrowding
                    new_board[row][col] = 0;
                } else {
                    // cell survives
                    new_board[row][col] = 1;
                }
            } else { // dead cell
                if (neighbors == 3) {
                    // cell becomes alive due to reproduction
                    new_board[row][col] = 1;
                } else {
                    // cell remains dead
                    new_board[row][col] = 0;
                }
            }
        }
    }

    // copy new board over old board
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = new_board[row][col];
        }
    }
}