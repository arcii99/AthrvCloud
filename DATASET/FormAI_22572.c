//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

// Generating Random Maze
void generateMaze(int maze[][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    maze[0][0] = maze[ROWS - 1][COLS - 1] = 0; // Start and End point of the Maze
}

// Printing Maze
void printMaze(int maze[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Finding Path in the Maze using Depth First Search
void findPath(int maze[][COLS], int row, int col, int visited[][COLS]) {
    if ((row < 0 || col < 0 || row >= ROWS || col >= COLS) || maze[row][col] == 1 || visited[row][col] == 1) {
        return;
    }
    visited[row][col] = 1;
    printf("(%d, %d) -> ", row, col);
    sleep(1); // Adding Delay of 1 Second
    if (row == ROWS - 1 && col == COLS - 1) {
        printf("Done!\n");
        exit(0);
    }
    findPath(maze, row, col + 1, visited); // Right
    findPath(maze, row + 1, col, visited); // Down
    findPath(maze, row, col - 1, visited); // Left
    findPath(maze, row - 1, col, visited); // Up
}

int main() {

    int maze[ROWS][COLS], visited[ROWS][COLS];
    generateMaze(maze);

    printf("\nMaze: \n");
    printMaze(maze);

    // Initializing visited matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            visited[i][j] = 0;
        }
    }

    printf("\nFinding Path...\n");
    findPath(maze, 0, 0, visited);

    printf("\nPath not found!\n");
    return 0;
}