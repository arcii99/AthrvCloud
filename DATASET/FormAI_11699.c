//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function to initialize the game board with random values
void initialize_board(int board[][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int rand_num = rand() % 2;
            board[i][j] = rand_num;
        }
    }
}

// Function to print the game board
void print_board(int board[][COLS]) {
    printf("\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                printf(" ");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}

// Function to count the number of neighbors of a cell
int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i == row && j == col) {
                continue;
            }

            if(i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }

            if(board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to simulate one generation of the game
void simulate_generation(int board[][COLS]) {
    int new_board[ROWS][COLS];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num_neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 0 && num_neighbors == 3) {
                new_board[i][j] = 1;
            } else if(board[i][j] == 1 && (num_neighbors == 2 || num_neighbors == 3)) {
                new_board[i][j] = 1;
            } else {
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
    int board[ROWS][COLS];

    // Initialize board
    initialize_board(board);

    // Simulate the game for 100 generations
    for(int i = 0; i < 100; i++) {
        print_board(board);
        simulate_generation(board);
    }

    return 0;
}