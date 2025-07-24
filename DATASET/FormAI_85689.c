//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// A struct to represent the coordinates of a point in the maze
typedef struct {
    int row, col;
} Point;

// Check if the given point is a valid one inside the maze
bool isValid(Point pt) {
    return (pt.row >= 0 && pt.row < ROWS) && (pt.col >= 0 && pt.col < COLS);
}

// Check if the given point is a wall in the maze
bool isWall(char maze[ROWS][COLS], Point pt) {
    return maze[pt.row][pt.col] == '#';
}

// Check if the given point is the destination in the maze
bool isDestination(char maze[ROWS][COLS], Point pt, Point dest) {
    return (pt.row == dest.row && pt.col == dest.col);
}

// Print the given maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Find the path to the destination in the maze using depth-first search
bool findDestination(char maze[ROWS][COLS], Point pt, Point dest) {
    // If the current point is out of bounds, return false
    if (!isValid(pt)) {
        return false;
    }
    // If the current point is a wall, return false
    if (isWall(maze, pt)) {
        return false;
    }
    // If the current point is the destination, return true
    if (isDestination(maze, pt, dest)) {
        maze[pt.row][pt.col] = 'D';
        printMaze(maze);
        return true;
    }
    // Mark the current point as visited
    maze[pt.row][pt.col] = '-';
    // Find the destination recursively in all four directions
    bool result = findDestination(maze, (Point){pt.row - 1, pt.col}, dest) || // Up
                  findDestination(maze, (Point){pt.row, pt.col + 1}, dest) || // Right
                  findDestination(maze, (Point){pt.row + 1, pt.col}, dest) || // Down
                  findDestination(maze, (Point){pt.row, pt.col - 1}, dest);   // Left
    // If the destination is found, mark the current point as part of the path
    if (result) {
        maze[pt.row][pt.col] = 'P';
    }
    return result;
}

int main() {
    // Create a maze
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'}
    };
    // Set the source and destination points
    Point src = {1, 1};
    Point dest = {8, 8};
    // Print the initial maze
    printf("Initial Maze:\n");
    printMaze(maze);
    // Find the destination in the maze
    if (findDestination(maze, src, dest)) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }
    return 0;
}