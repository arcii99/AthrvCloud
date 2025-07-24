//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_board(int board[][COLS]) {
    printf("Current Board: \n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolate(int board[][COLS]) { 
    // Check if the top and bottom rows are connected
    for(int i=0; i<COLS; i++) {
        if(board[0][i] == 1 && board[ROWS-1][i] == 1) {
            return 1;
        }
    }
    return 0;
}

void simulate(int board[][COLS]) {
    // Set top row to 1's
    for(int i=0; i<COLS; i++) {
        board[0][i] = 1;
    }
    print_board(board);
    // Randomly turn on cells until the board percolates
    int percolated = 0;
    while(!percolated) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if(board[row][col] == 0) {
            board[row][col] = 1;
            percolated = percolate(board);
            print_board(board);
        }
    }
    printf("Board has percolated!\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    int board[ROWS][COLS] = {0}; // Initialize board to all 0's
    simulate(board);
    return 0;
}