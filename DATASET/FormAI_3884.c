//FormAI DATASET v1.0 Category: Game of Life ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Define the grid size
#define WIDTH 40
#define HEIGHT 20

// Define the update rate
#define UPDATE_RATE 500000

// Function to randomly initialize the grid
void init_grid(int grid[][WIDTH]) {
    srand(time(NULL));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void print_grid(int grid[][WIDTH]) {
    printf("\n");
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

// Function to update the grid
void update_grid(int grid[][WIDTH]) {
    int tmp_grid[HEIGHT][WIDTH];

    // Copy the original grid
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            tmp_grid[i][j] = grid[i][j];
        }
    }

    // Update the grid according to the Game of Life rules
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int neighbors = 0;
            
            // Count the number of neighbors
            for(int k=-1; k<=1; k++) {
                for(int l=-1; l<=1; l++) {
                    if(!(k == 0 && l == 0) && i+k >= 0 && i+k < HEIGHT && j+l >= 0 && j+l < WIDTH) {
                        if(grid[i+k][j+l]) {
                            neighbors++;
                        }
                    }
                }
            }
            
            // Update the cell state
            if(grid[i][j]) {
                if(neighbors < 2 || neighbors > 3) {
                    tmp_grid[i][j] = 0;
                }
            } else {
                if(neighbors == 3) {
                    tmp_grid[i][j] = 1;
                }
            }
        }
    }

    // Copy the updated grid back to the main grid
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = tmp_grid[i][j];
        }
    }
}

int main() {
    // Initialize the grid
    int grid[HEIGHT][WIDTH];
    init_grid(grid);

    // Start the Game of Life
    while(1) {
        // Print the grid
        print_grid(grid);
        // Update the grid
        update_grid(grid);
        // Wait for the specified amount of time
        usleep(UPDATE_RATE);
    }

    return 0;
}