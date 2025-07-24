//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the game board
#define ROWS 10
#define COLS 10

// Define the number of generations to run the game for
#define GENERATIONS 10

// Function to initialize the game board randomly
void initialize_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int random_number = rand() % 2;
            board[i][j] = random_number;
        }
    }
}

// Function to print the game board
void print_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to count the number of live neighbors of a given cell
int count_live_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int x = row+i;
            int y = col+j;
            if(x >= 0 && x < ROWS && y >= 0 && y < COLS && (i != 0 || j != 0)) {
                if(board[x][y] == 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Function to update the game board for the next generation
void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int live_neighbors = count_live_neighbors(board, i, j);
            if(board[i][j] == 1) {
                if(live_neighbors < 2 || live_neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if(live_neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Initialize the game board
    int board[ROWS][COLS];
    initialize_board(board);
    
    // Run the game for a fixed number of generations
    for(int generation=1; generation<=GENERATIONS; generation++) {
        printf("Generation %d:\n", generation);
        print_board(board);
        update_board(board);
    }
    
    return 0;
}