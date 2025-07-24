//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initialize_board(int board[][SIZE]);
void print_board(int board[][SIZE]);
void percolate(int board[][SIZE]);

int main() {
    int board[SIZE][SIZE];
    initialize_board(board);
    printf("Initial board:\n");
    print_board(board);
    percolate(board);
    printf("Final board:\n");
    print_board(board);
    return 0;
}

void initialize_board(int board[][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int rand_num = rand() % 100;
            if (rand_num < 60) {
                board[i][j] = 0;
            } else {
                board[i][j] = 1;
            }
        }
    }
}

void print_board(int board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void percolate(int board[][SIZE]) {
    int percolating = 1; // flag to indicate if percolation has stopped or not
    while (percolating) {
        percolating = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 1) {
                    // check if there are any neighboring cells that can drain to
                    if (i > 0 && board[i - 1][j] == 2) {
                        percolating = 1;
                        board[i][j] = 2;
                    }
                    if (i < SIZE - 1 && board[i + 1][j] == 2) {
                        percolating = 1;
                        board[i][j] = 2;
                    }
                    if (j > 0 && board[i][j - 1] == 2) {
                        percolating = 1;
                        board[i][j] = 2;
                    }
                    if (j < SIZE - 1 && board[i][j + 1] == 2) {
                        percolating = 1;
                        board[i][j] = 2;
                    }
                }
            }
        }
        // mark the cells in the bottom row as draining cells
        for (int j = 0; j < SIZE; j++) {
            if (board[SIZE - 1][j] == 1) {
                percolating = 1;
                board[SIZE - 1][j] = 2;
            }
        }
    }
}