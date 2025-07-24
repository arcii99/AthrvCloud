//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// function to initialize the game board
void initialize_board(int board[ROWS][COLS]){
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // randomly generate 0 or 1 for each cell
            board[i][j] = rand() % 2;
        }
    }
}

// function to print the game board
void print_board(int board[ROWS][COLS]){
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to count the number of live neighbors
int count_neighbors(int board[ROWS][COLS], int row, int col){
    int count = 0;
    // check the neighbors of the cell
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            // skip checking the current cell
            if (i == row && j == col){
                continue;
            }
            // check if the neighbor cell is within the game board boundaries
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

// function to update the state of the game board
void update_board(int board[ROWS][COLS]){
    int next_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    next_board[i][j] = 0;
                } else {
                    next_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next_board[i][j] = 1;
                } else {
                    next_board[i][j] = 0;
                }
            }
        }
    }
    // update the game board to the next state
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = next_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    printf("Initial board:\n");
    print_board(board);
    // iterate the game for 10 generations
    for (int i = 0; i < 10; i++) {
        update_board(board);
        printf("Generation %d:\n", i+1);
        print_board(board);
    }
    return 0;
}