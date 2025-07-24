//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 5 // change to adjust maze size
#define MAX_COLS 7

// Function prototypes
void printMaze(char maze[][MAX_COLS]);
int isValidMove(char maze[][MAX_COLS], int row, int col, int visited[][MAX_COLS]);
int findPath(char maze[][MAX_COLS], int row, int col, int visited[][MAX_COLS], int path[][2], int step);
void printPath(int path[][2], int length);

int main() {
    // Example maze. 1 represents obstacle, 0 represents free path
    char maze[MAX_ROWS][MAX_COLS] = {
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0}
    };
    
    // Initialize array to keep track of visited cells
    int visited[MAX_ROWS][MAX_COLS] = {0};
    
    // Starting position
    int start_row = 0;
    int start_col = 0;
    
    // Find path
    int path[MAX_ROWS*MAX_COLS][2] = {0}; // maximum number of steps is number of cells in the maze
    int path_length = findPath(maze, start_row, start_col, visited, path, 0);
    
    // Print path
    printf("Path found with %d steps:\n", path_length);
    printPath(path, path_length);

    return 0;
}

// Prints the maze
void printMaze(char maze[][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Checks if a cell is a valid move
int isValidMove(char maze[][MAX_COLS], int row, int col, int visited[][MAX_COLS]) {
    // Check if cell is inside the maze
    if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
        return 0;
    }
    
    // Check if cell is an obstacle or has already been visited
    if (maze[row][col] == 1 || visited[row][col] == 1) {
        return 0;
    }
    
    return 1;
}

// Finds a path through the maze using backtracking
int findPath(char maze[][MAX_COLS], int row, int col, int visited[][MAX_COLS], int path[][2], int step) {
    // Base case: reached the end of the maze
    if (row == MAX_ROWS-1 && col == MAX_COLS-1) {
        path[step][0] = row;
        path[step][1] = col;
        return step+1;
    }
    
    // Try each possible move
    int moves[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for (int i = 0; i < 4; i++) {
        int next_row = row + moves[i][0];
        int next_col = col + moves[i][1];
        
        if (isValidMove(maze, next_row, next_col, visited)) {
            visited[next_row][next_col] = 1;
            path[step][0] = row;
            path[step][1] = col;
            int result = findPath(maze, next_row, next_col, visited, path, step+1);
            if (result > 0) {
                return result;
            }
            visited[next_row][next_col] = 0; // unmark
        }
    }
    
    // No path found from this cell
    return 0;
}

// Prints the path in reverse order
void printPath(int path[][2], int length) {
    for (int i = length-1; i >= 0; i--) {
        printf("(%d,%d) ", path[i][0], path[i][1]);
    }
}