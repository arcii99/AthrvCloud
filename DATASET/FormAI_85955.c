//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define PROBABILITY 0.6 // Probability of a site being open

// Initialize the grid
void initialize_grid(bool grid[][SIZE]) 
{
    srand(time(NULL)); // Seed the random number generator
    
    // Generate random states for each element of the grid
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            grid[i][j] = (rand() / (float)RAND_MAX) < PROBABILITY;
        }
    }
}

// Print the grid
void print_grid(bool grid[][SIZE]) 
{
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if(grid[i][j]) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Recursive method that checks if a site percolates
bool percolates_dfs(bool grid[][SIZE], int i, int j, bool visited[][SIZE]) 
{
    // Check if the current site is open and hasn't been visited yet
    if(!grid[i][j] || visited[i][j]) {
        return false;
    }
    
    // Mark the current site as visited
    visited[i][j] = true;
    
    // Check if any of the neighboring sites percolate
    if(i > 0 && percolates_dfs(grid, i - 1, j, visited)) { // Top
        return true;
    } 
    if(j > 0 && percolates_dfs(grid, i, j - 1, visited)) { // Left
        return true;
    }
    if(i < SIZE - 1 && percolates_dfs(grid, i + 1, j, visited)) { // Bottom
        return true;
    }
    if(j < SIZE - 1 && percolates_dfs(grid, i, j + 1, visited)) { // Right
        return true;
    }
    
    return false;
}

// Check if the grid percolates using depth-first search
bool percolates(bool grid[][SIZE]) 
{
    bool visited[SIZE][SIZE] = {false}; // Initialize all sites as unvisited
    
    // For each site in the top row, check if it percolates
    for(int j = 0; j < SIZE; ++j) {
        if(percolates_dfs(grid, 0, j, visited)) {
            return true;
        }
    }
    
    return false;
}

// Main method
int main() 
{
    bool grid[SIZE][SIZE];
    
    initialize_grid(grid);
    print_grid(grid);
    
    if(percolates(grid)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate :(\n");
    }
    
    return 0;
}