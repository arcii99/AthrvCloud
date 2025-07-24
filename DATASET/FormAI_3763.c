//FormAI DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 100

int generate_board(int board[ROWS][COLS]) {
    int i, j;
    srand(time(NULL));  // initialize random seed
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;  // randomly assign 0 or 1 to each cell
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int i, j, count=0;
    for (i=row-1; i<=row+1; i++) {
        for (j=col-1; j<=col+1; j++) {
            if ((i==row && j==col) || i<0 || j<0 || i>ROWS-1 || j>COLS-1) {  // skip cell itself and out of bounds
                continue;
            }
            count += board[i][j];
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS], int new_board[ROWS][COLS]) {
    int i, j, neighbors;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0;  // underpopulation or overcrowding leads to death
            } else if (board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;  // reproduction from exactly 3 neighbors
            } else {
                new_board[i][j] = board[i][j];  // copy status for unchanged cell
            }
        }
    }
    memcpy(board, new_board, ROWS*COLS*sizeof(int));  // copy new board to original board
}

int main() {
    int board[ROWS][COLS], new_board[ROWS][COLS], i, generation;
    generate_board(board);
    printf("Initial board:\n");
    print_board(board);
    for (generation=1; generation<=GENERATIONS; generation++) {
        update_board(board, new_board);
        printf("\nGeneration %d:\n", generation);
        print_board(board);
    }
    return 0;
}