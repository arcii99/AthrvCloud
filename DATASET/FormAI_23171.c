//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20

void print_grid(int grid[][WIDTH]);
void populate_grid(int grid[][WIDTH]);
void evolve(int grid[][WIDTH]);

int main() {
    int grid[HEIGHT][WIDTH];
    populate_grid(grid);
    while(1) {
        print_grid(grid);
        evolve(grid);
        usleep(50000); // Wait for 50ms
    }

    return 0;
}

// Populate the grid randomly with 1's and 0's
void populate_grid(int grid[][WIDTH]) {
    srand(time(NULL)); // Initialize random generator with the current time
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the current state of the grid
void print_grid(int grid[][WIDTH]) {
    system("clear"); // Clear the console output
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            printf("%c ", grid[i][j] ? '*' : '-');
        }
        printf("\n");
    }
}

// Calculate the next state of the grid based on the current state
void evolve(int grid[][WIDTH]) {
    int next[HEIGHT][WIDTH] = {0};
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int neighbors = -grid[i][j];
            for(int x=-1; x<=1; x++) {
                for(int y=-1; y<=1; y++) {
                    if(i+x >=0 && i+x <HEIGHT && j+y >=0 && j+y <WIDTH) {
                        neighbors += grid[i+x][j+y];
                    }
                }
            }
            if(grid[i][j] && (neighbors == 2 || neighbors == 3)) {
                next[i][j] = 1; // Live cell with 2 or 3 neighbors stays alive
            }
            else if(!grid[i][j] && neighbors == 3) {
                next[i][j] = 1; // Dead cell with 3 neighbors becomes alive
            }
        }
    }
    // Copy the next state to the current state
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            grid[i][j] = next[i][j];
        }
    }
}