//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 10

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ','#',' ',' ',' ',' ',' ','#'},
    {' ',' ',' ','#',' ','#','#','#','#','#'},
    {'#','#',' ','#',' ',' ',' ',' ',' ','#'},
    {'#',' ',' ',' ','#','#',' ','#',' ',' '},
    {'#','#','#','#','#','#','#','#','#','#'}
};

bool findPath(int row, int col) {
    // Check if current cell is outside of the maze boundaries
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    
    // Check if current cell is a wall or has already been visited
    if (maze[row][col] == '#' || maze[row][col] == '@') {
        return false;
    }
    
    // Check if current cell is the finish point
    if (row == ROWS-1 && col == COLS-1) {
        maze[row][col] = '@';
        return true;
    }
    
    maze[row][col] = '@'; // mark current cell as visited
    
    // Recursively search for a path in all four directions
    if (findPath(row, col+1) || findPath(row+1, col) || findPath(row, col-1) || findPath(row-1, col)) {
        return true;
    }
    
    maze[row][col] = ' '; // mark current cell as unvisited (backtracking)
    return false;
}

void printMaze(void) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    printf("Maze:\n");
    printMaze();
    printf("\n");
    
    if (findPath(0, 0)) {
        printf("Solution:\n");
        printMaze();
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}