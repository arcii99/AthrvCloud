//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scientific
/**
 * C Maze Route Finder Program
 * Uses Depth First Search algorithm to find the solution path in the given maze
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for maze size and path character
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10
#define PATH_CHAR '*'

// Maze structure
typedef struct {
    char grid[MAZE_HEIGHT][MAZE_WIDTH];
    int start_row, start_col, end_row, end_col;
} maze_t;

// Create a new empty maze
maze_t new_maze() {
    maze_t m;
    int i, j;

    // initialize maze to empty cells
    for (i = 0; i < MAZE_HEIGHT; i++) {
        for (j = 0; j < MAZE_WIDTH; j++) {
            m.grid[i][j] = ' ';
        }
    }

    // set start and end positions
    m.start_row = 1;
    m.start_col = 1;
    m.end_row = MAZE_HEIGHT - 2;
    m.end_col = MAZE_WIDTH - 2;

    return m;
}

// Print the maze
void print_maze(maze_t m) {
    int i, j;

    printf("+");
    for (j = 0; j < MAZE_WIDTH; j++) {
        printf("-");
    }
    printf("+\n");

    for (i = 0; i < MAZE_HEIGHT; i++) {
        printf("|");
        for (j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", m.grid[i][j]);
        }
        printf("|\n");
    }

    printf("+");
    for (j = 0; j < MAZE_WIDTH; j++) {
        printf("-");
    }
    printf("+\n");
}

// Recursive Depth First Search function to find the path
bool dfs_find_path(maze_t m, int r, int c) {
    if (r < 0 || r >= MAZE_HEIGHT || c < 0 || c >= MAZE_WIDTH) {
        return false;
    }
    if (m.grid[r][c] != ' ') {
        return false;
    }
    if (r == m.end_row && c == m.end_col) {
        m.grid[r][c] = PATH_CHAR;
        return true;
    }

    m.grid[r][c] = PATH_CHAR;

    if (dfs_find_path(m, r - 1, c)) { // up
        return true;
    } else if (dfs_find_path(m, r, c + 1)) { // right
        return true;
    } else if (dfs_find_path(m, r + 1, c)) { // down
        return true;
    } else if (dfs_find_path(m, r, c - 1)) { // left
        return true;
    }

    m.grid[r][c] = ' ';

    return false;
}

// Generate the maze path and return true if found, false otherwise
bool find_path(maze_t m) {
    return dfs_find_path(m, m.start_row, m.start_col);
}

// Main function
int main() {
    maze_t maze = new_maze();
    bool has_path;

    has_path = find_path(maze);
    if (has_path) {
        printf("Solution Path:\n");
        print_maze(maze);
    } else {
        printf("No solution found!\n");
    }

    return 0;
}