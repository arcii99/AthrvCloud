//FormAI DATASET v1.0 Category: Game of Life ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

void initialize_board(int board[][COLS]) {
    srand(time(0)); // seed for randomization
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % 2; // random value of 0 or 1
            board[i][j] = r;
        }
    }
}

void print_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("\u2588"); // full block character
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update_board(int board[][COLS]) {
    int updated_board[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbours = 0;
            
            // count neighbouring cells
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i+k >= 0 && i+k < ROWS && j+l >= 0 && j+l < COLS) {
                        if (!(k == 0 && l == 0) && board[i+k][j+l] == 1) {
                            neighbours++;
                        }
                    }
                }
            }
            
            // apply Game of Life rules to determine new cell state
            if (board[i][j] == 1 && neighbours < 2) {
                updated_board[i][j] = 0; // under-population
            } else if (board[i][j] == 1 && neighbours > 3) {
                updated_board[i][j] = 0; // over-population
            } else if (board[i][j] == 0 && neighbours == 3) {
                updated_board[i][j] = 1; // reproduction
            } else {
                updated_board[i][j] = board[i][j]; // no change
            }
        }
    }
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = updated_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    
    initialize_board(board);
    
    for (int i = 0; i < 100; i++) {
        system("clear"); // clear screen on Unix/Linux (change to "cls" for Windows)
        print_board(board);
        update_board(board);
        usleep(50000); // delay to slow down animation
    }
    
    return 0;
}