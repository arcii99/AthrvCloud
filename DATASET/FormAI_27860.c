//FormAI DATASET v1.0 Category: Game of Life ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the game board
#define WIDTH 20
#define HEIGHT 20

// Initialize the game board to all zeros
int game_board[WIDTH][HEIGHT] = {0};

// Function to display the game board
void display_board() {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c", game_board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

// Function to generate the next iteration of the game board based on the current state
void next_iteration() {
    // Copy the game board
    int new_board[WIDTH][HEIGHT];
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            new_board[i][j] = game_board[i][j];
        }
    }
    
    // Iterate through the game board to check each cell
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            // Count the live neighbors of each cell
            int live_neighbors = 0;
            for(int x=-1; x<=1; x++) {
                for(int y=-1; y<=1; y++) {
                    int neighbor_x = i + x;
                    int neighbor_y = j + y;
                    // Skip the center cell
                    if(x == 0 && y == 0) {
                        continue;
                    }
                    // Skip cells that are out of bounds
                    if(neighbor_x < 0 || neighbor_x >= HEIGHT || neighbor_y < 0 || neighbor_y >= WIDTH) {
                        continue;
                    }
                    if(game_board[neighbor_x][neighbor_y] == 1) {
                        live_neighbors++;
                    }
                }
            }
            // Apply the rules of Game of Life to determine the next state of each cell
            if(game_board[i][j] == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                new_board[i][j] = 0;
            }
            else if(game_board[i][j] == 0 && live_neighbors == 3) {
                new_board[i][j] = 1;
            }
        }
    }
    
    // Copy the new board over to the old board
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            game_board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Initialize the game board with some initial configuration
    game_board[5][5] = 1;
    game_board[5][6] = 1;
    game_board[5][7] = 1;
    game_board[6][5] = 1;
    game_board[7][5] = 1;
    
    // Run the simulation for 10 iterations and display the board after each iteration
    printf("Initial state:\n");
    display_board();
    for(int i=0; i<10; i++) {
        next_iteration();
        printf("Iteration %d:\n", i+1);
        display_board();
    }
    
    return 0;
}