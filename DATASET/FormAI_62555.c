//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>
#define ROWS 10
#define COLS 10

// The maze is represented by a 2D array of integers, where 0 stands for 'Unvisited'
// 1 stands for 'Visited', and -1 stands for 'Wall'. Note that maze can be of any size.
int maze[ROWS][COLS] = {
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 0, 0,-1, 0, 0, 0,-1, 0,-1},
    {-1, 0,-1, 0,-1,-1, 0,-1, 0,-1},
    {-1, 0,-1, 0, 0,-1, 0, 0, 0,-1},
    {-1, 0,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1, 0,-1, 0, 0, 0,-1, 0, 0,-1},
    {-1, 0, 0, 0,-1, 0,-1, 0,-1,-1},
    {-1,-1,-1, 0,-1, 0,-1, 0, 0,-1},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};

// This is our sample maze. '0' stands for unvisited, '-1' stands for walls.
// We will traverse this maze and try to find the shortest path from start to end.

// START: First element (1,1)
// STOP: Last element (8,8)


// Function to print the maze.
void printMaze(){
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if(maze[i][j] == -1){
                printf("%3s", "X"); 
            }
            else{
                printf("%3d", maze[i][j]); 
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function to find shortest path in the maze.
bool findPath(int row, int col, int steps){
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS){
        // Went out of boundaries, return false.
        return false;
    }
    if(maze[row][col] == -1 || maze[row][col] > 0){
        // Hit a wall or already visited this cell, return false.
        return false;
    }
    if(row == ROWS - 1 && col == COLS - 1){
        // Reached the destination, print the steps and return true.
        printf("Reached Destination in %d steps.\n", steps);
        return true;
    }
    // Set the number of steps taken so far.
    maze[row][col] = steps;
    // Find the shortest path from all possible directions (up, down, left, right)
    if(findPath(row+1,col,steps+1) || findPath(row-1,col,steps+1) || findPath(row,col+1,steps+1) || findPath(row,col-1,steps+1)){
        // Return true if found a path.
        return true;
    }
    // Reset the visited cell to '0' if no path found.
    maze[row][col] = 0;
    return false;
}

int main()
{
    // Starting point.
    int startX = 1, startY = 1;
    // Printing the maze before finding the path.
    printf("Original Maze:\n");
    printMaze();
    printf("Finding Path...\n");
    // Finding path from start to end.
    findPath(startX, startY, 1);
    // Printing the maze after finding the path.
    printf("Final Maze:\n");
    printMaze();
    return 0;
}