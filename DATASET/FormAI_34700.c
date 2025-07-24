//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// function to print the current state of the game board
void print_board(int board[][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 1) {
                printf("X ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to count the number of alive neighbors for a given cell
int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i >= 0 && j >= 0 && i < ROWS && j < COLS && (i != row || j != col)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

// function to update the game board based on the rules of the game
void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0;
            }
            else if(board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            }
            else {
                new_board[i][j] = board[i][j];
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
    int board[ROWS][COLS] = {0};
    srand(time(0));
    // randomly initialize the game board
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int rand_num = (rand() % 100) + 1;
            if(rand_num <= 30) {
                board[i][j] = 1;
            }
        }
    }
    // run the game for 50 generations
    for(int i = 0; i < 50; i++) {
        printf("Generation %d:\n", i + 1);
        print_board(board);
        update_board(board);
    }
    return 0;
}