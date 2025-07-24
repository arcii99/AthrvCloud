//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 10
#define COLS 20

// Function declarations
void generateMaze(char maze[][COLS]);
void displayMaze(char maze[][COLS]);
void findRoute(char maze[][COLS], int row, int col, int* isRouteFound);

int main() {
    char maze[ROWS][COLS];
    int startRow, startCol, isRouteFound = 0;

    // Generate maze
    generateMaze(maze);

    // Start and end points
    startRow = rand() % ROWS;
    startCol = 0;

    // Set starting point to 'S'
    maze[startRow][startCol] = 'S';

    // Find the route
    findRoute(maze, startRow, startCol, &isRouteFound);

    // Set ending point to 'E'
    maze[startRow][COLS - 1] = 'E';

    // Display maze with route (if found)
    printf("\nMaze with route:\n");
    if (isRouteFound) {
        displayMaze(maze);
    } else {
        printf("No route found :(\n");
    }

    return 0;
}

// Generate the maze
void generateMaze(char maze[][COLS]) {
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Fill maze with walls and spaces
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1) {
                maze[i][j] = '#';
            } else {
                if (rand() % 2 == 0) {
                    maze[i][j] = '#';
                } else {
                    maze[i][j] = ' ';
                }
            }
        }
    }
}

// Display the maze
void displayMaze(char maze[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Find the route through the maze
void findRoute(char maze[][COLS], int row, int col, int* isRouteFound) {
    // Check if out of bounds or already visited
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || maze[row][col] != ' ') {
        return;
    }

    // If end is found, set flag and return
    if (col == COLS - 1) {
        *isRouteFound = 1;
        return;
    }

    // Visit current cell
    maze[row][col] = '+';

    // Try all possible directions
    findRoute(maze, row - 1, col, isRouteFound);  // Up
    findRoute(maze, row + 1, col, isRouteFound);  // Down
    findRoute(maze, row, col - 1, isRouteFound);  // Left
    findRoute(maze, row, col + 1, isRouteFound);  // Right

    // If no route found from current cell, backtrack
    if (*isRouteFound == 0) {
        maze[row][col] = ' ';
    }
}