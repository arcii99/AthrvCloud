//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include <stdio.h>   
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initializeGrid(int grid[SIZE][SIZE]);
void printGrid(int grid[SIZE][SIZE]);
int findPath(int grid[SIZE][SIZE], int row, int col);

int main() {

    int grid[SIZE][SIZE];  
    
    srand(time(NULL));
    
    initializeGrid(grid);  
    
    printf("Starting maze:\n");
    printGrid(grid);
    
    int pathFound = findPath(grid, 0, 0);
    
    if(!pathFound) {
        printf("No path found.\n");
    } else {
        printf("Path found!\n");
        printGrid(grid);
    }
    
    return 0;
}

void initializeGrid(int grid[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(rand()%3 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    grid[0][0] = 0;
    grid[SIZE-1][SIZE-1] = 0;
}

void printGrid(int grid[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int findPath(int grid[SIZE][SIZE], int row, int col) {

    if(row == SIZE-1 && col == SIZE-1) {
        return 1;
    }
    
    if(row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    }
    
    if(grid[row][col] == 1) {
        return 0;
    }
    
    grid[row][col] = 1; // mark as visited
    
    if(findPath(grid, row+1, col) || findPath(grid, row-1, col) || findPath(grid, row, col+1) || findPath(grid, row, col-1)) {
        return 1;
    }
    
    return 0;
}