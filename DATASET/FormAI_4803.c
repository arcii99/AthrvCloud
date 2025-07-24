//FormAI DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

/* This function initializes the board with random values */
void init_board(bool board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

/* This function prints the board*/
void print_board(bool board[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j])
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

/* This function returns the number of alive neighbors for a given cell */
int get_alive_neighbors(bool board[ROWS][COLS], int row, int col) {
    int count = 0;
    int i, j;
    for(i = row-1; i <= row+1; i++) {
        for(j = col-1; j <= col+1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

/* This recursive function updates the board according to the rules of the game */
void update_board(bool board[ROWS][COLS], int row, int col) {
    int alive_neighbors = get_alive_neighbors(board, row, col);
    
    if(board[row][col]) {
        if(alive_neighbors < 2 || alive_neighbors > 3)
            board[row][col] = false;
    } else {
        if(alive_neighbors == 3)
            board[row][col] = true;
    }
    
    if(col < COLS - 1)
        update_board(board, row, col+1);
    else if(row < ROWS - 1)
        update_board(board, row+1, 0);
}

int main() {
    bool board[ROWS][COLS];
    int generations = 10;
    int i;
    srand(42);
    
    init_board(board);
    print_board(board);
    
    for(i = 0; i < generations; i++) {
        update_board(board, 0, 0);
        print_board(board);
    }
    
    return 0;
}