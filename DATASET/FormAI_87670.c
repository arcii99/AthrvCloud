//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>

// Define maze dimensions.
#define ROWS 10
#define COLS 10

// Define the maze.
char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#','#','#'},
    {'#',' ','#',' ','#',' ',' ',' ',' ','#'},
    {'#',' ','#',' ','#','#','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ',' ',' ',' ','#'},
    {'#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#','#','#',' ','#','#',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

// Define row and column offsets for each direction.
int rowOffset[] = {-1, 0, 1, 0};
int colOffset[] = {0, 1, 0, -1};

// Define function to check if a cell is valid.
int isValid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#';
}

// Define function to print the maze.
void printMaze(void) {
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            printf("%c ", maze[row][col]);
        }
        printf("\n");
    }
}

// Define function to find a path through the maze.
int findPath(int row, int col) {
    if(!isValid(row, col)) {
        return 0;
    }
    if(maze[row][col] == 'G') {
        return 1;
    }
    maze[row][col] = '#';
    for(int direction = 0; direction < 4; direction++) {
        int newRow = row + rowOffset[direction];
        int newCol = col + colOffset[direction];
        if(findPath(newRow, newCol)) {
            return 1;
        }
    }
    maze[row][col] = ' ';
    return 0;
}

// Define main function.
int main(void) {
    // Print the original maze.
    printf("Original maze:\n");
    printMaze();
    printf("\n");
    
    // Find a path through the maze.
    printf("Finding path...\n");
    if(findPath(1, 1)) {
        printf("Path found!\n\n");
    } else {
        printf("No path found.\n\n");
    }
    
    // Print the updated maze.
    printf("Updated maze:\n");
    printMaze();
    
    return 0;
}