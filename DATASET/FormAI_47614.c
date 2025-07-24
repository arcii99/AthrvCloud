//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the maze
#define WALL 0 // Wall in the maze
#define PATH 1 // Path in the maze
#define START 2 // Starting point in the maze
#define END 3 // Ending point in the maze

int maze[SIZE][SIZE]; // Maze array

// Function to check if a given coordinate is valid
int isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
        return 0;
    }
    return 1;
}

// Function to check if a given cell is a wall
int isWall(int row, int col) {
    if (maze[row][col] == WALL) {
        return 1;
    }
    return 0;
}

// Function to get a random direction
int getRandomDirection() {
    return rand() % 4;
}

// Function to generate the maze
void generateMaze(int row, int col) {
    int i, direction, newRow, newCol;

    // Set the current cell as a path
    maze[row][col] = PATH;

    // Check all directions
    for (i = 0; i < 4; i++) {
        direction = getRandomDirection();
        switch (direction) {
            case 0: // Up
                newRow = row - 1;
                newCol = col;
                break;
            case 1: // Right
                newRow = row;
                newCol = col + 1;
                break;
            case 2: // Down
                newRow = row + 1;
                newCol = col;
                break;
            case 3: // Left
                newRow = row;
                newCol = col - 1;
                break;
        }

        // Check if the new cell is valid and a wall
        if (isValid(newRow, newCol) && isWall(newRow, newCol)) {
            // Break down the wall between the current cell and the new cell
            if (direction == 0) { // Up
                maze[row][col] |= 1<<0;
                maze[newRow][newCol] |= 1<<2;
            }
            else if (direction == 1) { // Right
                maze[row][col] |= 1<<1;
                maze[newRow][newCol] |= 1<<3;
            }
            else if (direction == 2) { // Down
                maze[row][col] |= 1<<2;
                maze[newRow][newCol] |= 1<<0;
            }
            else if (direction == 3) { // Left
                maze[row][col] |= 1<<3;
                maze[newRow][newCol] |= 1<<1;
            }
            generateMaze(newRow, newCol);
        }
    }
}

// Function to print the maze
void printMaze() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (maze[i][j] == WALL) {
                printf("X");
            }
            else if (maze[i][j] == PATH) {
                printf(".");
            }
            else if (maze[i][j] == START) {
                printf("S");
            }
            else if (maze[i][j] == END) {
                printf("E");
            }
        }
        printf("\n");
    }
}

// Function to set the start and end points
void setStartEnd() {
    maze[0][0] = START;
    maze[SIZE - 1][SIZE - 1] = END;
}

// Main function
int main() {
    srand(time(NULL));

    // Fill the maze with walls
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            maze[i][j] = WALL;
        }
    }

    // Generate the maze
    generateMaze(0, 0);

    // Set the start and end points
    setStartEnd();

    // Print the maze
    printMaze();

    return 0;
}