//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the board size
#define M 20
#define N 20

int board[M][N] = {0};

// Function to initialize the board with random values
void init_board() {
    for(int i=0 ; i<M ; i++) {
        for(int j=0 ; j<N ; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Function to print the board
void print_board() {
    printf("\033[2J"); // Clear the screen
    for(int i=0 ; i<M ; i++) {
        for(int j=0 ; j<N ; j++) {
            if(board[i][j] == 1) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to count the number of alive neighbors for a given cell
int count_neighbors(int i, int j) {
    int count = 0;
    for(int x=-1 ; x<=1 ; x++) {
        for(int y=-1 ; y<=1 ; y++) {
            if(x == 0 && y == 0) {
                continue;
            }
            int row = (i+x+M) % M;
            int col = (j+y+N) % N;
            count += board[row][col];
        }
    }
    return count;
}

// Function to update the board for the next generation
void update_board() {
    int new_board[M][N] = {0};
    for(int i=0 ; i<M ; i++) {
        for(int j=0 ; j<N ; j++) {
            int neighbors = count_neighbors(i, j);
            if(board[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if(neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    // Copy the new board to the old board
    for(int i=0 ; i<M ; i++) {
        for(int j=0 ; j<N ; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the board
    init_board();
    
    // Run the simulation
    while(1) {
        print_board();
        update_board();
        usleep(100000);
    }
    
    return 0;
}