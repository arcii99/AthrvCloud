//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Global maze array
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 1, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Global visited array
bool visited[ROWS][COLS] = {false};

// Function to check if the current position is valid
bool isValid(int row, int col){
    // Check if it's within the bounds of the maze
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS)
        return false;
    // Check if the current position is a wall or has already been visited
    if(maze[row][col] == 0 || visited[row][col])
        return false;

    // If it's a valid position and hasn't been visited, return true
    return true;
}

// Function to find and print a path from start to finish
bool findPath(int row, int col, int endRow, int endCol){
    // Base case: if we've reached the end, return true
    if(row == endRow && col == endCol){
        printf("(%d, %d) ", row, col);
        return true;
    }

    // Mark the current position as visited
    visited[row][col] = true;

    // Check if we can move up
    if(isValid(row-1, col)){
        printf("(%d, %d) ", row, col);
        if(findPath(row-1, col, endRow, endCol))
            return true;
    }

    // Check if we can move right
    if(isValid(row, col+1)){
        printf("(%d, %d) ", row, col);
        if(findPath(row, col+1, endRow, endCol))
            return true;
    }

    // Check if we can move down
    if(isValid(row+1, col)){
        printf("(%d, %d) ", row, col);
        if(findPath(row+1, col, endRow, endCol))
            return true;
    }

    // Check if we can move left
    if(isValid(row, col-1)){
        printf("(%d, %d) ", row, col);
        if(findPath(row, col-1, endRow, endCol))
            return true;
    }

    // If none of the above conditions are true, backtrack
    return false;
}

// Main function
int main(){
    // Start and end coordinates
    int startX = 0;
    int startY = 0;
    int endX = 9;
    int endY = 9;

    // Print the maze
    printf("Maze:\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    // Print the start and end coordinates
    printf("\nStart: (%d, %d)\n", startX, startY);
    printf("End: (%d, %d)\n\n", endX, endY);

    // Call the findPath function and print the path if it exists
    printf("Path: ");
    if(findPath(startX, startY, endX, endY))
        printf("\n");
    else
        printf("No path exists.\n");

    return 0;
}