//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10     // Number of rows in the maze
#define COLS 10     // Number of columns in the maze

int maze[ROWS][COLS];  // 2D array to hold the maze

// Function to initialize the maze with all walls intact
void initializeMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = -1;    // -1 represents a wall
        }
    }
}

// Function to print the maze
void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == -1) {
                printf("#");    // # represents a wall
            } else if (maze[i][j] == 0) {
                printf(" ");    // empty space
            } else {
                printf(".");    // . represents a path
            }
        }
        printf("\n");
    }
}

// Function to check if a cell is within the maze bounds
int isWithinBounds(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a cell has any unvisited neighbors
int hasUnvisitedNeighbors(int maze[ROWS][COLS], int row, int col) {
    if (isWithinBounds(row-1, col) && maze[row-1][col] == -1) {
        return 1;
    } else if (isWithinBounds(row+1, col) && maze[row+1][col] == -1) {
        return 1;
    } else if (isWithinBounds(row, col-1) && maze[row][col-1] == -1) {
        return 1;
    } else if (isWithinBounds(row, col+1) && maze[row][col+1] == -1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to randomly select an unvisited neighbor of a cell
int* selectRandomUnvisitedNeighbor(int maze[ROWS][COLS], int row, int col) {
    int options[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   // Possible directions to move in
    while (1) {
        int randomIndex = rand() % 4;   // Select a random direction
        int* neighbor = malloc(sizeof(int)*2);
        neighbor[0] = row + options[randomIndex][0];
        neighbor[1] = col + options[randomIndex][1];
        if (isWithinBounds(neighbor[0], neighbor[1]) && maze[neighbor[0]][neighbor[1]] == -1) {
            return neighbor;   // Return the coordinates of the unvisited neighbor
        }
    }
}

// Recursive function to generate the maze
void generateMaze(int maze[ROWS][COLS], int row, int col) {
    maze[row][col] = 0;     // Mark current cell as a path
    while (hasUnvisitedNeighbors(maze, row, col)) {
        int* neighbor = selectRandomUnvisitedNeighbor(maze, row, col);   // Select a random unvisited neighbor
        int neighborRow = neighbor[0];
        int neighborCol = neighbor[1];
        if (row - neighborRow == 1) {
            maze[row-1][col] = 0;   // Remove wall to the north
        } else if (neighborRow - row == 1) {
            maze[row+1][col] = 0;   // Remove wall to the south
        } else if (col - neighborCol == 1) {
            maze[row][col-1] = 0;   // Remove wall to the west
        } else {
            maze[row][col+1] = 0;   // Remove wall to the east
        }
        generateMaze(maze, neighborRow, neighborCol);   // Recursively generate the maze starting at the neighbor
        free(neighbor);
    }
}

int main() {
    srand(time(NULL));     // Seed random number generator
    initializeMaze(maze);  // Initialize maze with all walls intact
    generateMaze(maze, 0, 0);   // Generate the maze starting at the top left corner
    printMaze(maze);       // Print the maze
    return 0;
}