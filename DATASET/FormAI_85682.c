//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS]; // Maze Grid
int visited[ROWS][COLS]; // Visited Grid

void fillMaze() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(rand() % 5 == 0) // 20% probability to block the cell
                maze[i][j] = 1; // 1 represents a blocked cell (a wall)
            else
                maze[i][j] = 0; // 0 represents an empty cell (a path)
            visited[i][j] = 0; // Mark all cells unvisited
        }
    }
}

void printMaze() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) // Wall
                printf("\u2588"); // Full Block Character
            else if(maze[i][j] == 2) // Visited Cell
                printf("."); // Dot Character
            else
                printf(" "); // Empty Cell
        }
        printf("\n");
    }
}

int solveMaze(int x, int y) {
    if(x < 0 || x >= ROWS || y < 0 || y >= COLS || visited[x][y] || maze[x][y])
        return 0; // Out of Bounds or Blocked Cell or Already Visited

    visited[x][y] = 1; // Mark Current Cell as Visited

    if(x == ROWS - 1 && y == COLS - 1) // Destination Reached!
        return 1;

    if(solveMaze(x + 1, y)) // Move Down
        return 1;

    if(solveMaze(x, y + 1)) // Move Right
        return 1;

    if(solveMaze(x - 1, y)) // Move Up
        return 1;

    if(solveMaze(x, y - 1)) // Move Left
        return 1;

    visited[x][y] = 0; // Unmark Current Cell (BACKTRACK)

    return 0; // Dead End
}

int main() {
    srand(time(NULL)); // Seed Random Number Generator
    fillMaze(); // Generate Random Maze
    printf("MAZE:\n");
    printMaze(); // Print Maze
    printf("\n");
    if(solveMaze(0, 0)) { // Start Solving Maze from Top-Left Cell
        maze[0][0] = 2; // Mark Starting Cell as Visited
        printf("MAZE SOLVED:\n");
        printMaze(); // Print Solved Maze
    }
    else
        printf("MAZE CANNOT BE SOLVED!\n");
    return 0; // Exit Program
}