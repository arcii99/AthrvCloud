//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_WIDTH 20
#define GRID_HEIGHT 20

// Create a struct for each site in the grid
typedef struct{
    int id;
    int isOpen;
} Site;

// Initialize the grid with closed sites
void initializeGrid(Site grid[GRID_WIDTH][GRID_HEIGHT]){
    for(int i = 0; i < GRID_WIDTH; i++){
        for(int j = 0; j < GRID_HEIGHT; j++){
            grid[i][j].id = i * GRID_HEIGHT + j;
            grid[i][j].isOpen = 0;
        }
    }
}

// Print the grid to the console
void printGrid(Site grid[GRID_WIDTH][GRID_HEIGHT]){
    for(int i = 0; i < GRID_WIDTH; i++){
        for(int j = 0; j < GRID_HEIGHT; j++){
            if(grid[i][j].isOpen){
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Check if two sites are connected
int isConnected(Site grid[GRID_WIDTH][GRID_HEIGHT], int id1, int id2){
    int row1 = id1 / GRID_HEIGHT;
    int col1 = id1 % GRID_HEIGHT;
    int row2 = id2 / GRID_HEIGHT;
    int col2 = id2 % GRID_HEIGHT;
    
    if(row1 == row2 && abs(col1 - col2) == 1 && grid[row1][col1].isOpen && grid[row2][col2].isOpen){
        return 1;
    }
    
    if(col1 == col2 && abs(row1 - row2) == 1 && grid[row1][col1].isOpen && grid[row2][col2].isOpen){
        return 1;
    }
    
    return 0;
}

// Connect two sites by opening a path between them
void connect(Site grid[GRID_WIDTH][GRID_HEIGHT], int id1, int id2){
    int row1 = id1 / GRID_HEIGHT;
    int col1 = id1 % GRID_HEIGHT;
    int row2 = id2 / GRID_HEIGHT;
    int col2 = id2 % GRID_HEIGHT;
    
    if(row1 == row2 && abs(col1 - col2) == 1){
        if(col1 < col2){
            for(int i = col1; i <= col2; i++){
                grid[row1][i].isOpen = 1;
            }
        } else {
            for(int i = col2; i <= col1; i++){
                grid[row1][i].isOpen = 1;
            }
        }
    }
    
    if(col1 == col2 && abs(row1 - row2) == 1){
        if(row1 < row2){
            for(int i = row1; i <= row2; i++){
                grid[i][col1].isOpen = 1;
            }
        } else {
            for(int i = row2; i <= row1; i++){
                grid[i][col1].isOpen = 1;
            }
        }
    }
}

int main(){
    // Initialize the grid
    Site grid[GRID_WIDTH][GRID_HEIGHT];
    initializeGrid(grid);
    
    // Seed the random number generator
    srand(time(NULL));
    
    int openSites = 0;
    
    // Open sites until the grid percolates
    while(!isConnected(grid, 0, GRID_WIDTH * GRID_HEIGHT - 1)){
        int row = rand() % GRID_WIDTH;
        int col = rand() % GRID_HEIGHT;
        if(!grid[row][col].isOpen){
            grid[row][col].isOpen = 1;
            openSites++;
            // Connect the new site to adjacent open sites
            if(row > 0 && grid[row - 1][col].isOpen){
                connect(grid, grid[row][col].id, grid[row - 1][col].id);
            }
            if(row < GRID_WIDTH - 1 && grid[row + 1][col].isOpen){
                connect(grid, grid[row][col].id, grid[row + 1][col].id);
            }
            if(col > 0 && grid[row][col - 1].isOpen){
                connect(grid, grid[row][col].id, grid[row][col - 1].id);
            }
            if(col < GRID_HEIGHT - 1 && grid[row][col + 1].isOpen){
                connect(grid, grid[row][col].id, grid[row][col + 1].id);
            }
        }
    }
    
    // Print the percolation system
    printGrid(grid);
    
    // Print the number of open sites required for percolation
    printf("Percolation threshold: %d / %d\n", openSites, GRID_WIDTH * GRID_HEIGHT);
    
    return 0;
}