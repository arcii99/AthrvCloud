//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// function prototypes
void printMaze(char maze[ROW][COL]);
bool isSafe(char maze[ROW][COL], int row, int col);
bool findPath(char maze[ROW][COL], int row, int col, int destRow, int destCol);

// function to print the maze
void printMaze(char maze[ROW][COL]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if current cell is safe to move in
bool isSafe(char maze[ROW][COL], int row, int col) {
    // check if current cell is out of bounds
    if(row < 0 || col < 0 || row >= ROW || col >= COL) {
        return false;
    }
    
    // check if current cell is a wall
    if(maze[row][col] == '#') {
        return false;
    }
    
    // cell is safe to move in
    return true;
}

// function to find path from source to destination
bool findPath(char maze[ROW][COL], int row, int col, int destRow, int destCol) {
    // check if current cell is the destination cell
    if(row == destRow && col == destCol) {
        return true;
    }
    
    // check if current cell is safe to move in
    if(isSafe(maze, row, col)) {
        // mark current cell as visited
        maze[row][col] = '.';
        
        // move right
        if(findPath(maze, row, col + 1, destRow, destCol)) {
            return true;
        }
        
        // move down
        if(findPath(maze, row + 1, col, destRow, destCol)) {
            return true;
        }
        
        // move left
        if(findPath(maze, row, col - 1, destRow, destCol)) {
            return true;
        }
        
        // move up
        if(findPath(maze, row - 1, col, destRow, destCol)) {
            return true;
        }
        
        // mark current cell as unvisited
        maze[row][col] = ' ';
    }
    
    // path not found
    return false;
}

int main() {
    char maze[ROW][COL] = {
        {' ', ' ', '#', ' ', ' '},
        {'#', ' ', '#', '#', ' '},
        {' ', ' ', ' ', '#', ' '},
        {'#', '#', ' ', ' ', ' '},
        {'#', ' ', ' ', '#', ' '}
    };
    
    printf("Maze:\n");
    printMaze(maze);
    
    if(findPath(maze, 0, 0, 4, 4)) {
        printf("\nPath Found!\n");
    } else {
        printf("\nPath not found.\n");
    }
    
    printf("Solution:\n");
    printMaze(maze);
    
    return 0;
}