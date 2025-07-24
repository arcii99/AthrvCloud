//FormAI DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to print the board
void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) printf("* ");
            else printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// function to calculate the next generation of the board
void next_generation(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS] = {0};
    
    // loop through each cell on the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // count the live neighbors
            int live_neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int row = i + x;
                    int col = j + y;
                    // check if the neighbor is on the board and alive
                    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 1 && !(x == 0 && y == 0)) {
                        live_neighbors++;
                    }
                }
            }
            // apply the Game of Life rules
            if (board[i][j] == 1 && (live_neighbors == 2 || live_neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && live_neighbors == 3) {
                new_board[i][j] = 1;
            }
        }
    }
    // copy the new board to the original board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // initialize the board with random values
    int board[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    // print the initial board
    printf("Initial board:\n");
    print_board(board);
    
    // run the Game of Life for 10 generations
    for (int i = 0; i < 10; i++) {
        next_generation(board);
        printf("Generation %d:\n", i+1);
        print_board(board);
    }
    
    return 0;
}