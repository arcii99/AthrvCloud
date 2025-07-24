//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#define ROWS 6
#define COLS 9

// Maze with obstacles represented with 0's and free spaces with 1's
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" # ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

// Recursive function to find the route in the maze
int findPath(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        // Out of bounds
        return 0;
    }
    if (maze[row][col] == 0) {
        // Obstacle
        return 0;
    }
    if (maze[row][col] == 2) {
        // Already visited
        return 0;
    }
    if (row == ROWS - 1 && col == COLS - 1) {
        // Destination found
        maze[row][col] = 2;
        return 1;
    }
    // Mark current node as visited
    maze[row][col] = 2;
    if (findPath(row-1, col) == 1) {
        // Move up
        return 1;
    }
    if (findPath(row, col+1) == 1) {
        // Move right
        return 1;
    }
    if (findPath(row+1, col) == 1) {
        // Move down
        return 1;
    }
    if (findPath(row, col-1) == 1) {
        // Move left
        return 1;
    }
    // No path found from this node
    maze[row][col] = 0;
    return 0;
}

int main() {
    printf("Welcome to the Maze Route Finder program!\n");
    printf("The maze is represented with '#' symbols for obstacles and blank spaces for free spaces.\n\n");
    printMaze();
    if (findPath(0, 0) == 1) {
        printf("\n\nPath found!\n\n");
    } else {
        printf("\n\nNo path found.\n\n");
    }
    printMaze();
    return 0;
}