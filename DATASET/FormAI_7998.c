//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for maze size
#define ROWS 10
#define COLS 10

// Define constants for maze cells
#define PATH 0
#define WALL 1
#define VISITED 2
#define PATH_CHAR ' '
#define WALL_CHAR '|'
#define VISITED_CHAR '.'
#define START_CHAR 'S'
#define END_CHAR 'E'

// Function to print the maze
void print_maze(int maze[ROWS][COLS], int start_row, int start_col, int end_row, int end_col) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == start_row && j == start_col) {
                printf("%c ", START_CHAR);
            } else if (i == end_row && j == end_col) {
                printf("%c ", END_CHAR);
            } else if (maze[i][j] == PATH) {
                printf("%c ", PATH_CHAR);
            } else if (maze[i][j] == WALL) {
                printf("%c ", WALL_CHAR);
            } else if (maze[i][j] == VISITED) {
                printf("%c ", VISITED_CHAR);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Recursive function to find the path through the maze
bool find_path(int maze[ROWS][COLS], int row, int col, int end_row, int end_col) {
    // Check if current cell is the end cell
    if (row == end_row && col == end_col) {
        maze[row][col] = VISITED;
        return true;
    }
    // Check if current cell is a wall or has already been visited
    if (maze[row][col] == WALL || maze[row][col] == VISITED) {
        return false;
    }
    // Mark current cell as visited
    maze[row][col] = VISITED;
    // Print current state of maze
    print_maze(maze, row, col, end_row, end_col);
    // Recursively check neighboring cells
    if (row > 0 && find_path(maze, row - 1, col, end_row, end_col)) { // Check cell above
        return true;
    }
    if (row < ROWS - 1 && find_path(maze, row + 1, col, end_row, end_col)) { // Check cell below
        return true;
    }
    if (col > 0 && find_path(maze, row, col - 1, end_row, end_col)) { // Check cell to the left
        return true;
    }
    if (col < COLS - 1 && find_path(maze, row, col + 1, end_row, end_col)) { // Check cell to the right
        return true;
    }
    // If no path found, mark current cell as dead-end
    maze[row][col] = PATH;
    return false;
}

int main() {
    // Define maze
    int maze[ROWS][COLS] = {
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
    };
    // Define starting and ending coordinates
    int start_row = 1;
    int start_col = 0;
    int end_row = 9;
    int end_col = 9;
    // Print initial maze
    print_maze(maze, start_row, start_col, end_row, end_col);
    // Find path through maze
    if (find_path(maze, start_row, start_col, end_row, end_col)) {
        printf("Congratulations! You made it to the end.\n\n");
    } else {
        printf("Sorry, there is no path to the end.\n\n");
    }
    // Print final maze
    print_maze(maze, start_row, start_col, end_row, end_col);
    return 0;
}