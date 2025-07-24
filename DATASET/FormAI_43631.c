//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define ROWS 8
#define COLS 8

// Define maze as a 2D array of integers
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
};

// Define a structure to hold coordinates
struct coordinate {
    int x;
    int y;
};

// Define a function to print the maze
void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Define a recursive function to find the route through the maze
int findRoute(int x, int y, struct coordinate route[], int index) {
    // If we have reached the end of the maze, return success
    if(x == ROWS-2 && y == COLS-2) {
        route[index].x = x;
        route[index].y = y;
        return 1;
    }
    // If we are at a dead end, return failure
    if(maze[x][y] == 1) {
        return 0;
    }
    // Mark the current cell as visited
    maze[x][y] = 1;
    // Try moving in all four directions
    if(findRoute(x+1, y, route, index+1)) {
        route[index].x = x;
        route[index].y = y;
        return 1;
    }
    if(findRoute(x-1, y, route, index+1)) {
        route[index].x = x;
        route[index].y = y;
        return 1;
    }
    if(findRoute(x, y+1, route, index+1)) {
        route[index].x = x;
        route[index].y = y;
        return 1;
    }
    if(findRoute(x, y-1, route, index+1)) {
        route[index].x = x;
        route[index].y = y;
        return 1;
    }
    // If we get here, we have reached a dead end, so mark the current cell as unvisited and return failure
    maze[x][y] = 0;
    return 0;
}

int main() {
    // Define the starting point and an array to hold the route
    struct coordinate start = {1, 1};
    struct coordinate route[ROWS*COLS];
    int result;
    // Print the original maze
    printf("Original maze:\n");
    printMaze();
    // Find the route through the maze
    result = findRoute(start.x, start.y, route, 0);
    // If the result is success, print the route
    if(result) {
        printf("Route through maze:\n");
        for(int i=ROWS*COLS-1; i>=0; i--) {
            if(route[i].x != 0 || route[i].y != 0) {
                printf("(%d,%d) ", route[i].x, route[i].y);
            }
        }
        printf("\n");
    }
    // If the result is failure, print an error message
    else {
        printf("Error: no route through maze.\n");
    }
    return 0;
}