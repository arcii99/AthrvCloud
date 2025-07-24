//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>

//define the size of the grid
#define ROWS 10
#define COLS 10

//function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//check if current point is inside the grid
int isValid(int x, int y) {
    if(x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return 0;
    }
    return 1;
}

//recursive function to find a path from start to end
int findPath(int grid[ROWS][COLS], int x, int y, int endX, int endY) {
    //check if current point is outside the grid or is obstacle
    if(!isValid(x, y) || grid[x][y] == 1) {
        return 0;
    }
    //check if current point is the end point
    if(x == endX && y == endY) {
        return 1;
    }
    //mark current point as visited
    grid[x][y] = 1;
    //check for all neighboring points
    int result = 0;
    if(isValid(x+1, y)) {
        result = result || findPath(grid, x+1, y, endX, endY);
    }
    if(isValid(x-1, y)) {
        result = result || findPath(grid, x-1, y, endX, endY);
    }
    if(isValid(x, y+1)) {
        result = result || findPath(grid, x, y+1, endX, endY);
    }
    if(isValid(x, y-1)) {
        result = result || findPath(grid, x, y-1, endX, endY);
    }
    //if no path found, unmark current point
    if(!result) {
        grid[x][y] = 0;
    }
    return result;
}

int main() {
    //initialize the grid with 0s for empty and 1s for obstacles
    int grid[ROWS][COLS] = {
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    //print the grid before finding the path
    printf("Grid:\n");
    printGrid(grid);
    int startX = 0, startY = 0;
    int endX = 9, endY = 9;
    //find path from start to end
    int result = findPath(grid, startX, startY, endX, endY);
    //if path found, print the updated grid
    if(result) {
        printf("\nPath Found!\n");
        printGrid(grid);
    }
    //if no path found, print error message
    else {
        printf("\nNo Path Found :(\n");
    }
    return 0;
}