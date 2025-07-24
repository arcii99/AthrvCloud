//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 5
#define COLS 5

// Create the maze as an array of integers
// 0 - Wall
// 1 - Passage
// 2 - Visited Passage
int maze[ROWS][COLS] ={ {0,0,0,0,0},                   // 0 denotes walls
                        {1,0,1,1,1},                   // 1 denotes passage
                        {1,0,0,0,1},
                        {1,1,1,0,1},
                        {0,0,1,0,1} };

// Print the maze
void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        printf("\n");
        for(int j = 0; j < COLS; j++) {
            printf("%d ",maze[i][j]);
        }
    }
    printf("\n\n");
}

// Recursive function to find the route
bool findPath(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        // Out of maze
        return false;
    }
    if(maze[row][col] == 0 || maze[row][col] == 2) {
        // Wall or visited passage
        return false;
    }
    if(row == ROWS - 1 && col == COLS - 1) {
        printf("Found a path!\n");
        return true;
    }
    maze[row][col] = 2; // Mark as visited passage
    
    // Try moving up, down, left and right
    if(findPath(row-1, col) || findPath(row+1, col) || findPath(row, col-1) || findPath(row, col+1)) {
        return true;
    }

    return false;
}

int main() {

    printf("Maze before solving:");
    printMaze();

    // Start from the top left corner
    if(findPath(0, 0)) {
        printf("Maze after solving:");
        printMaze();
    } else {
        printf("No Path found.");
    }

    return 0;
}