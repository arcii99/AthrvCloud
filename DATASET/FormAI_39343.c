//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLUMNS 5

// Data Structure to Store a Maze Coordinate
typedef struct {
    int row;
    int column;
} Coordinate;

// Global Variable to track the end coordinate of the maze
Coordinate endCoordinate = { 4, 4 };

// Global Variable to track the maze
int maze[ROWS][COLUMNS] = {
    { 1, 0, 1, 1, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 1, 1, 0, 1 }
};

// Function to check if a Coordinate is Valid (i.e not outside the bounds of the maze and not an obstacle)
bool isValidCoordinate(Coordinate coordinate) {
    return coordinate.row >= 0 && coordinate.row < ROWS && coordinate.column >= 0 && coordinate.column < COLUMNS && maze[coordinate.row][coordinate.column] != 0;
}

// Function to check if a Coordinate is the End Coordinate of the Maze
bool isEndCoordinate(Coordinate coordinate) {
    return coordinate.row == endCoordinate.row && coordinate.column == endCoordinate.column;
}

// Function to print the Maze
void printMaze() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (i == 0 && j == 0) {
                printf("S ");
            } else if (i == endCoordinate.row && j == endCoordinate.column) {
                printf("E ");
            } else if (maze[i][j] == 0) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

// Function to find the Solution to the Maze using a Depth-First-Search Algorithm
bool solveMazeDFS(Coordinate currentCoordinate) {
    // Check if Current Coordinate is the End Coordinate of the Maze
    if (isEndCoordinate(currentCoordinate)) {
        printf("Found Path to End of Maze.\n");
        return true;
    }

    // Check if Current Coordinate is a Valid Coordinate
    if (!isValidCoordinate(currentCoordinate)) {
        return false;
    }

    // Mark Current Coordinate as Visited
    maze[currentCoordinate.row][currentCoordinate.column] = 0;

    // Check Neighboring Coordinates Recursively
    Coordinate northCoordinate = { currentCoordinate.row - 1, currentCoordinate.column };
    Coordinate eastCoordinate = { currentCoordinate.row, currentCoordinate.column + 1 };
    Coordinate southCoordinate = { currentCoordinate.row + 1, currentCoordinate.column };
    Coordinate westCoordinate = { currentCoordinate.row, currentCoordinate.column - 1 };

    if (solveMazeDFS(northCoordinate)) {
        printf("Moved North.\n");
        return true;
    }

    if (solveMazeDFS(eastCoordinate)) {
        printf("Moved East.\n");
        return true;
    }

    if (solveMazeDFS(southCoordinate)) {
        printf("Moved South.\n");
        return true;
    }

    if (solveMazeDFS(westCoordinate)) {
        printf("Moved West.\n");
        return true;
    }

    // Unmark Current Coordinate as Visited
    maze[currentCoordinate.row][currentCoordinate.column] = 1;

    return false;
}

int main() {
    printf("Starting Point (S): 0\nEnd Point (E): 4\nObstacle (X): 1\n");

    // Print Initial Maze
    printMaze();

    // Find Solution to Maze
    printf("\nFinding Path to End of Maze...\n");
    if (!solveMazeDFS((Coordinate) { 0, 0 })) {
        printf("\nUnable to Find Path to End of Maze.\n");
    }

    // Print Final Maze
    printf("\nFinal Maze:\n");
    printMaze();

    return 0;
}