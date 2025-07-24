//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#define ROWS 10
#define COLS 10

// function to print the maze
void printMaze(char maze[][COLS], int rows) {
    printf("\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if the cell is within the maze
int isSafe(char maze[][COLS], int row, int col) {
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == '-') {
        return 1;
    }
    return 0;
}

// recursive function to find the path
int findPath(char maze[][COLS], int row, int col) {
    if(row == ROWS - 1 && col == COLS - 1) {
        maze[row][col] = '#'; // mark the end of the path
        return 1;
    }
    if(isSafe(maze, row, col) == 1) {
        maze[row][col] = '#'; // mark the current cell
        //check down
        if(findPath(maze, row+1, col) == 1) {
            return 1;
        }
        //check right
        if(findPath(maze, row, col+1) == 1) { 
            return 1;
        }
        //check up
        if(findPath(maze, row-1, col) == 1) { 
            return 1;
        }
        //check left
        if(findPath(maze, row, col-1) == 1) { 
            return 1;
        }
        maze[row][col] = '-'; // backtrack
        return 0;
    }
    return 0;
}

int main() {
    char maze[ROWS][COLS] = {
            {'-', '-', '-', '#', '-', '#', '-', '-', '-', '-'},
            {'-', '#', '-', '#', '-', '#', '-', '#', '#', '-'},
            {'-', '-', '-', '-', '-', '#', '-', '-', '-', '-'},
            {'#', '-', '#', '#', '-', '-', '-', '-', '#', '-'},
            {'-', '-', '-', '-', '#', '-', '-', '#', '-', '-'},
            {'-', '#', '-', '-', '-', '#', '-', '-', '#', '-'},
            {'-', '#', '#', '#', '-', '-', '#', '-', '#', '-'},
            {'-', '-', '-', '#', '-', '#', '#', '#', '-', '-'},
            {'#', '-', '#', '-', '-', '-', '-', '-', '-', '-'},
            {'#', '-', '-', '-', '-', '#', '#', '-', '-', '-'}
        };
        
    printf("\tThe Maze\n");
    // print the maze
    printMaze(maze, ROWS);
    
    printf("\n\tFinding the Path...\n");
    // find the path
    if(findPath(maze, 0, 0) == 1) {
        printf("\n\tThe Path\n");
        // print the path
        printMaze(maze, ROWS);
    } else {
        printf("\n\tNo path found!\n");
    }
    return 0;
}