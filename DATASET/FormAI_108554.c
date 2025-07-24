//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Maze size
#define ROW 8
#define COL 8

// Structure to hold coordinates of a point
typedef struct {
    int x, y;
} Point;

// Function to print the maze matrix
void printMaze(char maze[ROW][COL]) {
    printf("+------------------------+\n");
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("|\n");
    }
    printf("+------------------------+\n");
}

// Function to check if a given point is valid
int isValid(char maze[ROW][COL], Point p) {
    if (p.x >= 0 && p.x < ROW && p.y >= 0 && p.y < COL && maze[p.x][p.y] == '.') {
        return 1;
    } else {
        return 0;
    }
}

// Recursive function to find the path from start to end
int findPath(char maze[ROW][COL], Point start, Point end) {
    // Mark the current point as visited
    maze[start.x][start.y] = 'o';
    
    // If we have reached the end point, return success
    if (start.x == end.x && start.y == end.y) {
        return 1;
    }
    
    // Check if we can move down
    Point down = {start.x + 1, start.y};
    if (isValid(maze, down) && findPath(maze, down, end)) {
        return 1;
    }
    
    // Check if we can move right
    Point right = {start.x, start.y + 1};
    if (isValid(maze, right) && findPath(maze, right, end)) {
        return 1;
    }
    
    // Check if we can move up
    Point up = {start.x - 1, start.y};
    if (isValid(maze, up) && findPath(maze, up, end)) {
        return 1;
    }
    
    // Check if we can move left
    Point left = {start.x, start.y - 1};
    if (isValid(maze, left) && findPath(maze, left, end)) {
        return 1;
    }
    
    // Mark the current point as dead end
    maze[start.x][start.y] = 'x';
    
    // Return failure
    return 0;
}

int main() {
    // Maze matrix
    char maze[ROW][COL] = {
        {'#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '#'},
        {'#', '#', '#', '.', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#'}
    };
    
    // Starting point and ending point
    Point start = {1, 1};
    Point end = {ROW-2, COL-2};
    
    // Print the initial maze
    printf("Initial maze:\n");
    printMaze(maze);
    
    // Find the path from start to end
    if (findPath(maze, start, end)) {
        printf("Path found!\n");
    } else {
        printf("Path not found!\n");
    }
    
    // Print the final maze
    printf("Final maze:\n");
    printMaze(maze);
    
    return 0;
}