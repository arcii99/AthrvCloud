//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to print the board
void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

// function to check the cell's state in the next generation
int next_state(int board[ROWS][COLS], int row, int col) {
    int neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && board[i][j])
                neighbors++;
        }
    }
    if (board[row][col]) {
        if (neighbors == 2 || neighbors == 3) return 1;
        else return 0;
    } else {
        if (neighbors == 3) return 1;
        else return 0;
    }
}

int main() {
    int board[ROWS][COLS];
    
    // initialize board with random values
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    // print initial board
    printf("Initial board:\n");
    print_board(board);
    
    // simulate generations
    for (int gen = 0; gen < 10; gen++) {
        // create next generation board
        int next_board[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                next_board[i][j] = next_state(board, i, j);
            }
        }
        // copy next generation to current board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                board[i][j] = next_board[i][j];
            }
        }
        // print current board
        printf("\nGeneration %d:\n", gen + 1);
        print_board(board);
    }
    
    return 0;
}