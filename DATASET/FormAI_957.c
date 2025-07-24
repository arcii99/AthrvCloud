//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#define ROW 10
#define COL 10

// Function prototypes
void printMaze(int maze[][COL]);
int findPath(int maze[][COL], int x, int y);

int main() {
    int maze[ROW][COL] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        { 0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
        { 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // Find path through maze starting at (1, 0)
    findPath(maze, 1, 0);

    // Print final maze
    printMaze(maze);

    return 0;
}

/**
 * Function to find a path through a maze.
 * Returns 1 if a path is found; 0 otherwise.
 */
int findPath(int maze[][COL], int x, int y) {
    // Check if we've reached the end of the maze
    if (x == ROW-2 && y == COL-1) {
        maze[x][y] = 2;
        return 1;
    }
    // Check if current position is valid
    if (maze[x][y] == 1 || maze[x][y] == 2) {
        return 0;
    }
    // Mark current position as visited
    maze[x][y] = 2;

    // Recursively search for path in all directions
    if (findPath(maze, x-1, y) == 1) {
        return 1;
    }
    if (findPath(maze, x+1, y) == 1) {
        return 1;
    }
    if (findPath(maze, x, y-1) == 1) {
        return 1;
    }
    if (findPath(maze, x, y+1) == 1) {
        return 1;
    }

    // No path found from this position, backtrack
    maze[x][y] = 0;
    return 0;
}

/**
 * Function to print the maze.
 * 0 = path, 1 = wall, 2 = visited
 */
void printMaze(int maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}