//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>

#define HEIGHT 10
#define WIDTH 10

// Function to print the maze
void printMaze(char maze[HEIGHT][WIDTH]) {
    printf("Maze:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find the route in the maze
int findRoute(char maze[HEIGHT][WIDTH], int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        // Out of bounds
        return 0;
    }

    if (maze[y][x] == 'X') {
        // Wall
        return 0;
    }

    if (maze[y][x] == 'G') {
        // Goal
        return 1;
    }

    if (maze[y][x] == '.') {
        // Already visited
        return 0;
    }

    // Mark as visited
    maze[y][x] = '.';

    // Move in all directions
    if (findRoute(maze, x-1, y)) {
        // Left
        return 1;
    }
    if (findRoute(maze, x+1, y)) {
        // Right
        return 1;
    }
    if (findRoute(maze, x, y-1)) {
        // Up
        return 1;
    }
    if (findRoute(maze, x, y+1)) {
        // Down
        return 1;
    }

    // No route found
    return 0;
}

int main() {
    char maze[HEIGHT][WIDTH] = {
        {'S', '.', 'X', '.', '.', '.', 'X', '.', 'X', '.'},
        {'X', '.', 'X', 'X', 'X', 'X', 'X', '.', 'X', '.'},
        {'.', '.', 'X', '.', '.', '.', 'X', '.', 'X', '.'},
        {'.', 'X', 'X', 'X', 'X', 'X', 'X', '.', 'X', '.'},
        {'.', '.', '.', '.', '.', '.', 'X', '.', 'X', '.'},
        {'.', 'X', 'X', 'X', '.', 'X', 'X', '.', 'X', '.'},
        {'.', '.', '.', 'X', '.', '.', '.', '.', 'X', '.'},
        {'.', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'X'},
        {'.', 'X', 'X', 'X', 'X', 'X', 'X', 'X', '.', 'G'}
    };

    printMaze(maze);

    if (findRoute(maze, 0, 0)) {
        printf("Route found!\n");
        printMaze(maze);
    } else {
        printf("No route found :(\n");
    }

    return 0;
}