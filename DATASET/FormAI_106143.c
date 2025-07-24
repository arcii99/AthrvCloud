//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int board[ROWS][COLS];

int main() {
    int num, row, col;
    srand(time(NULL));
    
    // initialize board with zeros
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = 0;
        }
    }
    
    // randomly generate numbers from 1 to 25
    for (int i = 0; i < ROWS * COLS; i++) {
        num = rand() % 25 + 1;
        
        // check if number already exists on board
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == num) {
                    num = rand() % 25 + 1;
                    r = 0; // start loop over to check again
                    c = -1;
                }
            }
        }
        
        // place number on board
        row = rand() % ROWS;
        col = rand() % COLS;
        while (board[row][col] != 0) {
            row = rand() % ROWS;
            col = rand() % COLS;
        }
        board[row][col] = num;
    }
    
    printf("BINGO BOARD:\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }
    
    return 0;
}