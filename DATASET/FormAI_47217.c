//FormAI DATASET v1.0 Category: Game of Life ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_board(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

int count_live_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i < 0 || i >= ROWS || j < 0 || j >= COLS)
                continue;
            if(i == row && j == col)
                continue;
            if(board[i][j])
                count++;
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int live_neighbors = count_live_neighbors(board, i, j);
            if(board[i][j]) {
                if(live_neighbors == 2 || live_neighbors == 3)
                    new_board[i][j] = 1;
                else
                    new_board[i][j] = 0;
            }
            else {
                if(live_neighbors == 3)
                    new_board[i][j] = 1;
                else
                    new_board[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Initialize board randomly
    int board[ROWS][COLS];
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    // Run the game of life for 100 iterations
    for(int i = 0; i < 100; i++) {
        print_board(board);
        printf("\n");
        update_board(board);
    }
    return 0;
}