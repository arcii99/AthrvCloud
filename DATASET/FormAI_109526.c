//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the grid
#define GRID_SIZE 10

// Function to print the status of the grid
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("Grid:\n");
    for(int i=0; i<GRID_SIZE; i++) {
        for(int j=0; j<GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_percolating(int grid[GRID_SIZE][GRID_SIZE]) {
    // Check if there is a path from the top row to the bottom row
    int visited[GRID_SIZE][GRID_SIZE] = {0};
    for(int j=0; j<GRID_SIZE; j++) {
        if(grid[0][j] == 1) {
            visited[0][j] = 1;
            // Use a stack to perform depth-first search
            int stack[GRID_SIZE*GRID_SIZE][2];
            int top = -1;
            stack[++top][0] = 0;
            stack[top][1] = j;
            while(top >= 0) {
                int i = stack[top][0];
                int j = stack[top][1];
                top--;
                // Check the neighbors - up, right, down, left
                if(i > 0 && grid[i-1][j] == 1 && visited[i-1][j] == 0) {
                    visited[i-1][j] = 1;
                    stack[++top][0] = i-1;
                    stack[top][1] = j;
                }
                if(j < GRID_SIZE-1 && grid[i][j+1] == 1 && visited[i][j+1] == 0) {
                    visited[i][j+1] = 1;
                    stack[++top][0] = i;
                    stack[top][1] = j+1;
                }
                if(i < GRID_SIZE-1 && grid[i+1][j] == 1 && visited[i+1][j] == 0) {
                    visited[i+1][j] = 1;
                    stack[++top][0] = i+1;
                    stack[top][1] = j;
                }
                if(j > 0 && grid[i][j-1] == 1 && visited[i][j-1] == 0) {
                    visited[i][j-1] = 1;
                    stack[++top][0] = i;
                    stack[top][1] = j-1;
                }
            }
            // Check if any cell in the last row is visited
            for(int jj=0; jj<GRID_SIZE; jj++) {
                if(visited[GRID_SIZE-1][jj] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));
    // Initialize the grid with all cells blocked
    int grid[GRID_SIZE][GRID_SIZE] = {0};
    // Open cells randomly until percolation occurs
    while(!is_percolating(grid)) {
        int i = rand() % GRID_SIZE;
        int j = rand() % GRID_SIZE;
        if(grid[i][j] == 0) {
            grid[i][j] = 1;
        }
    }
    // Print the final status of the grid
    print_grid(grid);
    return 0;
}