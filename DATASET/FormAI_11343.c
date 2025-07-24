//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: light-weight
#include <stdio.h>
#define ROW 5
#define COL 5

// Function to find the correct path in the maze
int findPath(int maze[][COL], int x, int y, int sol[][COL]) {
    // Check if the current position is within the maze and is not a wall
    if (x >= 0 && x < ROW && y >=0 && y < COL && maze[x][y] == 1) {
        // Mark the current position as part of the solution path
        sol[x][y] = 1;

        // Check if we have reached the destination
        if (x == ROW-1 && y == COL-1) {
            return 1;
        }

        // Check for paths in the right, down, left, and up directions
        if (findPath(maze, x+1, y, sol) == 1) {
            return 1;
        }
        if (findPath(maze, x, y+1, sol) == 1) {
            return 1;
        }
        if (findPath(maze, x-1, y, sol) == 1) {
            return 1;
        }
        if (findPath(maze, x, y-1, sol) == 1) {
            return 1;
        }

        // If the above paths do not lead to the destination, backtrack and remove the current position from the solution path
        sol[x][y] = 0;
        return 0;
    }
    return 0;
}

// Function to print the solution path
void printSolution(int sol[][COL]) {
    printf("The solution path for the maze is: \n");
    for (int i=0; i < ROW; i++) {
        for (int j=0; j < COL; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Driver function
int main() {
    int maze[ROW][COL] = {{1, 0, 1, 1, 0},
                          {1, 1, 1, 0, 1},
                          {0, 1, 0, 1, 1},
                          {0, 0, 1, 1, 0},
                          {1, 1, 1, 1, 1}};
    int sol[ROW][COL] = {{0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};

    // Find the solution path for the maze
    if (findPath(maze, 0, 0, sol) == 1) {
        printSolution(sol);
    } else {
        printf("There is no solution path for the maze.\n");
    }
    return 0;
}