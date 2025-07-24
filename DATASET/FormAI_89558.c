//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Function to print the current state of the board
void print_board(int board[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check the number of live neighbors
int check_neighbors(int board[HEIGHT][WIDTH], int row, int col) {
    int count = 0;
    
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i == row && j == col) continue; // skip current cell
            
            if(i < 0 || i >= HEIGHT) continue; // out of bounds
            if(j < 0 || j >= WIDTH) continue; // out of bounds
            
            count += board[i][j];
        }
    }
    
    return count;
}

// Function to update the board based on the rules of the game
void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH] = {0}; // initialize new board with zeros
    
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int neighbors = check_neighbors(board, i, j);
            
            if(board[i][j] == 1) { // current cell is alive
                if(neighbors == 2 || neighbors == 3) {
                    new_board[i][j] = 1; // cell stays alive
                }
            } else { // current cell is dead
                if(neighbors == 3) {
                    new_board[i][j] = 1; // cell becomes alive
                }
            }
        }
    }
    
    // copy new board to original board
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH] = {0}; // initialize board with zeros
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Populate the board with random cells
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    // Run the game of life
    for(int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i+1);
        print_board(board);
        update_board(board);
    }
    
    return 0;
}