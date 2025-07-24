//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Maze dimensions
#define ROWS 15
#define COLS 20

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            // Print 'X' for blocked position and ' ' otherwise
            if(maze[i][j]==1) printf("X");
            else printf(" ");
        }
        printf("\n");
    }
}

// Function to check if a position is valid or not
int isValid(int row, int col) {
    return row>=0 && row<ROWS && col>=0 && col<COLS;
}

// Function to check if a move is allowed or not
int isAllowed(int maze[ROWS][COLS], int row, int col) {
    // Check if the position is valid and is not blocked
    return isValid(row, col) && maze[row][col]==0;
}

// Function to randomly generate the maze
void generateMaze(int maze[ROWS][COLS]) {
    int i, j;
    for(i=0;i<ROWS;i++) {
        for(j=0;j<COLS;j++) {
            // Randomly mark cells as blocked
            maze[i][j] = (rand()%2==0);
        }
    }
}

// Function to solve the maze
int solveMaze(int maze[ROWS][COLS], int row, int col) {
    // If the current position is the destination, return true
    if(row==ROWS-1 && col==COLS-1) {
        maze[row][col]=2; // Mark the destination with '2'
        return 1;
    }
    // If the current position is valid and not blocked
    if(isAllowed(maze, row, col)) {
        // Mark the current position as visited
        maze[row][col] = 2;
        // Check for all possible moves from the current position
        if(solveMaze(maze, row, col+1)||solveMaze(maze, row+1, col)||solveMaze(maze, row-1, col)||solveMaze(maze, row, col-1)) {
            // If any of the moves leads to the destination, return true
            return 1;
        }
        // If none of the moves lead to the destination, backtrack
        maze[row][col] = 0;
    }
    return 0;
}

int main() {
    int maze[ROWS][COLS], i, j;
    srand(time(NULL)); // Seed the random generator
    generateMaze(maze); // Generate the maze
    printf("The randomly generated maze is:\n");
    printMaze(maze); // Print the initial maze
    printf("\n");
    if(solveMaze(maze, 0, 0)) {
        printf("The path to the destination is: \n");
        printMaze(maze); // Print the solved maze
    }
    else {
        printf("No path to destination found!\n");
    }
    return 0;
}