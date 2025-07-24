//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10

void initialize_grid(bool grid[GRID_SIZE][GRID_SIZE]) {
    for(int i=0;i<GRID_SIZE;i++) {
        for(int j=0;j<GRID_SIZE;j++) {
            grid[i][j] = false;
        }
    }
}

void display_grid(bool grid[GRID_SIZE][GRID_SIZE]) {
    printf("\n");
    for(int i=0;i<GRID_SIZE;i++) {
        for(int j=0;j<GRID_SIZE;j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void percolate(bool grid[GRID_SIZE][GRID_SIZE]) {
    bool top_row[GRID_SIZE] = {0};
    bool bottom_row[GRID_SIZE] = {0};
    bool visited[GRID_SIZE][GRID_SIZE] = {false};

    // Check for percolation using DFS algorithm
    for(int j=0;j<GRID_SIZE;j++) {
        if(grid[0][j]) {
            dfs(0, j, top_row, visited, grid);
        }
        if(grid[GRID_SIZE-1][j]) {
            dfs(GRID_SIZE-1, j, bottom_row, visited, grid);
        }
    }

    // Mark all cells that are connected to a cell in both top and bottom row
    for(int i=0;i<GRID_SIZE;i++) {
        for(int j=0;j<GRID_SIZE;j++) {
            if(top_row[j] && bottom_row[j] && visited[i][j]) {
                grid[i][j] = true;
            }
        }
    }
}

void dfs(int i, int j, bool *row, bool visited[GRID_SIZE][GRID_SIZE], bool grid[GRID_SIZE][GRID_SIZE]) {
    if(i<0 || i>=GRID_SIZE || j<0 || j>=GRID_SIZE) return;
    if(visited[i][j]) return;
    visited[i][j] = true;
    if(grid[i][j]) {
        if(i==0) row[j]=true;
        if(i>0) dfs(i-1, j, row, visited, grid);
        if(i<GRID_SIZE-1) dfs(i+1, j, row, visited, grid);
        if(j>0) dfs(i, j-1, row, visited, grid);
        if(j<GRID_SIZE-1) dfs(i, j+1, row, visited, grid);
    }
}

int main() {
    srand(time(NULL));
    bool grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);

    // Fill with random sites
    for(int i=0;i<GRID_SIZE;i++) {
        for(int j=0;j<GRID_SIZE;j++) {
            if(rand()/(double)RAND_MAX>0.7) {
                grid[i][j] = true;
            }
        }
    }

    // Display initial grid
    printf("Initial Grid:\n");
    display_grid(grid);

    // Percolate the grid
    percolate(grid);

    // Display final grid
    printf("Final Grid:\n");
    display_grid(grid);

    return 0;
}