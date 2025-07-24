//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 15

void generateMaze(int maze[ROWS][COLUMNS]);
void printMaze(int maze[ROWS][COLUMNS]);
void findRoute(int maze[ROWS][COLUMNS], int row, int col);

int main() {
    int maze[ROWS][COLUMNS];
    generateMaze(maze);
    printf("Generated Maze:\n");
    printMaze(maze);
    int startingRow, startingCol;
    printf("Enter the starting row and column (separated by a space) for the route finder: ");
    scanf("%d %d", &startingRow, &startingCol);
    findRoute(maze, startingRow, startingCol);
    return 0;
}

void generateMaze(int maze[ROWS][COLUMNS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int randomNum = rand() % 10 + 1; // Generate random number between 1 and 10
            if (randomNum < 7) { // 60% chance of creating a wall
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
    maze[0][0] = 0; // Starting point is always open
    maze[ROWS - 1][COLUMNS - 1] = 0; // End point is always open
}

void printMaze(int maze[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i][j] == 1) {
                printf("#"); // Wall
            } else {
                printf("."); // Path
            }
        }
        printf("\n"); // New line after each row
    }
}

void findRoute(int maze[ROWS][COLUMNS], int row, int col) {
    if (row == ROWS - 1 && col == COLUMNS - 1) { // Base case: reached the end
        printf("(%d, %d) -> ", row, col); // Print the end point
        return;
    }
    if (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS || maze[row][col] == 1) { // Invalid move or hit a wall
        return;
    }
    maze[row][col] = 1; // Mark current position as visited
    printf("(%d, %d) -> ", row, col); // Print current position
    // Recursively try to find a path through each of the four possible directions
    findRoute(maze, row, col + 1); // Try right
    findRoute(maze, row + 1, col); // Try down
    findRoute(maze, row, col - 1); // Try left
    findRoute(maze, row - 1, col); // Try up
}