//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// Struct representing a position in the maze
typedef struct {
    int row;
    int col;
} Position;

// Array representing the maze
const char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Function to print the maze
void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a position is valid (i.e. not out of bounds or a wall)
bool isValidPosition(Position pos) {
    return pos.row >= 0 && pos.row < ROWS &&
           pos.col >= 0 && pos.col < COLS &&
           maze[pos.row][pos.col] != '#';
}

// Array to keep track of visited positions
bool visited[ROWS][COLS];

// Function to recursively find the route to the end of the maze 
bool findRoute(Position pos) {
    if (pos.row == ROWS-1 && pos.col == COLS-1) {
        // End of maze found!
        return true;
    }
    visited[pos.row][pos.col] = true;
    if (isValidPosition((Position){pos.row-1, pos.col}) && !visited[pos.row-1][pos.col]) {
        // Try going up
        if (findRoute((Position){pos.row-1, pos.col})) {
            return true;
        }
    }
    if (isValidPosition((Position){pos.row+1, pos.col}) && !visited[pos.row+1][pos.col]) {
        // Try going down
        if (findRoute((Position){pos.row+1, pos.col})) {
            return true;
        }
    }
    if (isValidPosition((Position){pos.row, pos.col-1}) && !visited[pos.row][pos.col-1]) {
        // Try going left
        if (findRoute((Position){pos.row, pos.col-1})) {
            return true;
        }
    }
    if (isValidPosition((Position){pos.row, pos.col+1}) && !visited[pos.row][pos.col+1]) {
        // Try going right
        if (findRoute((Position){pos.row, pos.col+1})) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("Welcome to the Maze Route Finder!\n");
    printf("Here's the maze:\n");
    printMaze();

    Position start = {0, 0};
    memset(visited, false, sizeof visited);
    bool foundRoute = findRoute(start);

    if (foundRoute) {
        printf("Route to end of maze found!\n");
    } else {
        printf("Sorry, could not find a route to end of maze :(\n");
    }

    return 0;
}