//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the grid

void percolate(int grid[][SIZE]) {
    int i, j, counter = 0;
    int visited[SIZE][SIZE] = {0}; // create a visited array and initialize it to 0
    
    for(i = 0; i < SIZE; i++) {
        if(grid[0][i] == 1 && !visited[0][i]) { // if the top row has a 1, call dfs to check for percolation
            counter++;
            dfs(grid, visited, 0, i, counter);
        }
    }
    
    if(counter == 1) { // if only one component is found, percolation has occurred
        printf("The grid percolates\n");
    } else { // otherwise, percolation has not occurred
        printf("The grid does not percolate\n");
    }
}

void dfs(int grid[][SIZE], int visited[][SIZE], int i, int j, int counter) {
    if(i < 0 || i >= SIZE || j < 0 || j >= SIZE || visited[i][j]) { // base case 1: out of bounds or already visited
        return;
    }
    
    if(grid[i][j] != 1) { // base case 2: empty cell
        return;
    }
    
    visited[i][j] = counter; // mark the cell as visited with the component number
    
    dfs(grid, visited, i+1, j, counter); // call dfs on all neighbors
    dfs(grid, visited, i-1, j, counter);
    dfs(grid, visited, i, j+1, counter);
    dfs(grid, visited, i, j-1, counter);
}

int main() {
    int i, j;
    int grid[SIZE][SIZE];
    
    srand(time(NULL)); // seed the random number generator with the current time
    
    for(i = 0; i < SIZE; i++) { // fill the grid with random 1s and 0s
        for(j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    printf("Grid:\n");
    for(i = 0; i < SIZE; i++) { // print the initial grid
        for(j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    percolate(grid); // call the percolation function
    
    return 0;
}