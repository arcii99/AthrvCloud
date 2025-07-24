//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdbool.h>

// Number of rows and columns for maze
#define ROWS 8 
#define COLS 10 

// Function to print the maze
void printMaze(char maze[][COLS])
{
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a particular cell is a valid move
bool isValidMove(char maze[][COLS], int x, int y)
{
    if(x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == '*') {
        return false;
    }
    return true;
}

// Function to find a path through the maze
bool findPath(char maze[][COLS], int x, int y)
{
    // base case: if we have reached the end of the maze
    if(x == ROWS-1 && y == COLS-1) {
        maze[x][y] = '$'; // mark the end of the path with a '$'
        return true;
    }
    
    // check if current position is valid
    if(isValidMove(maze, x, y)) {
        // mark the current position as part of the path
        maze[x][y] = '-';
        
        // try moving right
        if(findPath(maze, x, y+1)) {
            return true;
        }
        
        // try moving down
        if(findPath(maze, x+1, y)) {
            return true;
        }
        
        // try moving left
        if(findPath(maze, x, y-1)) {
            return true;
        }
        
        // try moving up
        if(findPath(maze, x-1, y)) {
            return true;
        }
        
        // none of the directions worked, so mark the current position as dead end
        maze[x][y] = '*';
        return false;
    }
    
    return false;
}

int main()
{
    // initialize the maze
    char maze[ROWS][COLS] = {
        {'-', '-', '-', '-', '-', '*', '*', '*', '*', '*'},
        {'*', '*', '*', '*', '-', '*', '*', '*', '*', '*'},
        {'-', '-', '-', '*', '-', '*', '*', '*', '*', '*'},
        {'*', '*', '-', '*', '-', '*', '*', '*', '*', '*'},
        {'*', '*', '-', '*', '-', '-', '-', '-', '-', '-'},
        {'*', '*', '-', '*', '-', '*', '*', '*', '*', '-'},
        {'*', '*', '-', '*', '-', '*', '*', '*', '*', '-'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '-', '-'}
    };
    
    // print the initial maze
    printf("Initial maze:\n");
    printMaze(maze);
    
    // call findPath function to get the path through the maze
    findPath(maze, 0, 0);
    
    // print the final maze with path marked
    printf("\nFinal maze:\n");
    printMaze(maze);

    return 0;
}