//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

// Function to initialize the maze with walls
void initializeMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

// Function to print the maze
void printMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a cell is within the bounds of the maze
int isCellValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Function to check if a cell has any unvisited neighbors
int hasUnvisitedNeighbor(int maze[][COLS], int row, int col) {
    int unvisitedNeighbors = 0;
    if (isCellValid(row - 1, col) && maze[row - 1][col] == 1) {
        unvisitedNeighbors++;
    }
    if (isCellValid(row + 1, col) && maze[row + 1][col] == 1) {
        unvisitedNeighbors++;
    }
    if (isCellValid(row, col - 1) && maze[row][col - 1] == 1) {
        unvisitedNeighbors++;
    }
    if (isCellValid(row, col + 1) && maze[row][col + 1] == 1) {
        unvisitedNeighbors++;
    }
    return unvisitedNeighbors;
}

// Function to remove the wall between two adjacent cells
void removeWall(int maze[][COLS], int row1, int col1, int row2, int col2) {
    if (row1 == row2 && col1 < col2) {
        maze[row1][col1 + 1] = 0;
    } else if (row1 == row2 && col1 > col2) {
        maze[row1][col1 - 1] = 0;
    } else if (row1 < row2 && col1 == col2) {
        maze[row1 + 1][col1] = 0;
    } else if (row1 > row2 && col1 == col2) {
        maze[row1 - 1][col1] = 0;
    }
}

// Function to generate the maze
void generateMaze(int maze[][COLS], int row, int col) {
    maze[row][col] = 0; // mark the current cell as visited
    while (hasUnvisitedNeighbor(maze, row, col) != 0) {
        int direction = generateRandomNumber(1, 4);
        if (direction == 1 && isCellValid(row - 1, col) && maze[row - 1][col] == 1) { // up
            removeWall(maze, row, col, row - 1, col);
            generateMaze(maze, row - 1, col);
        } else if (direction == 2 && isCellValid(row + 1, col) && maze[row + 1][col] == 1) { // down
            removeWall(maze, row, col, row + 1, col);
            generateMaze(maze, row + 1, col);
        } else if (direction == 3 && isCellValid(row, col - 1) && maze[row][col - 1] == 1) { // left
            removeWall(maze, row, col, row, col - 1);
            generateMaze(maze, row, col - 1);
        } else if (direction == 4 && isCellValid(row, col + 1) && maze[row][col + 1] == 1) { // right
            removeWall(maze, row, col, row, col + 1);
            generateMaze(maze, row, col + 1);
        }
    }
}

// Main function
int main() {
    int maze[ROWS][COLS];
    srand(time(NULL)); // seed the random number generator
    initializeMaze(maze); // initialize the maze with walls
    generateMaze(maze, 0, 0); // generate the maze
    printMaze(maze); // print the maze
    return 0;
}