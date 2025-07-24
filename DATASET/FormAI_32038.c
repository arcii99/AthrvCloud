//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

// Struct for storing each cell in the maze
typedef struct {
    int x;
    int y;
} Cell;

// Function to print the maze
void printMaze(char maze[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if we can move to a given cell
int canMoveTo(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Cell cell) {
    if (cell.x < 0 || cell.x >= rows || cell.y < 0 || cell.y >= cols) {
        return 0;   // Out of bounds
    }

    if (maze[cell.x][cell.y] == '#') {
        return 0;   // Wall
    }

    if (maze[cell.x][cell.y] == 'X') {
        return 0;   // Already visited
    }

    return 1;   // Valid move
}

// Function to find the route through the maze
int findRoute(char maze[MAX_ROWS][MAX_COLS], int rows, int cols, Cell start, Cell end) {
    if (!canMoveTo(maze, rows, cols, start) || !canMoveTo(maze, rows, cols, end)) {
        return 0;   // Invalid start or end
    }

    maze[start.x][start.y] = 'S';   // Mark start cell
    maze[end.x][end.y] = 'E';       // Mark end cell

    Cell stack[MAX_ROWS * MAX_COLS]; // Array acting as a stack
    int top = 0;
    stack[top++] = start;   // Push start cell onto the stack

    while (top > 0) {   // While there are still cells on the stack
        Cell current = stack[--top];   // Pop a cell from the stack

        if (current.x == end.x && current.y == end.y) {
            return 1;   // Found a route
        }

        // Try moving to adjacent cells
        Cell next;
        next.x = current.x - 1;   // Up
        next.y = current.y;
        if (canMoveTo(maze, rows, cols, next)) {
            maze[next.x][next.y] = 'X';   // Mark as visited
            stack[top++] = next;           // Push onto the stack
        }

        next.x = current.x + 1;   // Down
        next.y = current.y;
        if (canMoveTo(maze, rows, cols, next)) {
            maze[next.x][next.y] = 'X';   // Mark as visited
            stack[top++] = next;           // Push onto the stack
        }

        next.x = current.x;   // Left
        next.y = current.y - 1;
        if (canMoveTo(maze, rows, cols, next)) {
            maze[next.x][next.y] = 'X';   // Mark as visited
            stack[top++] = next;           // Push onto the stack
        }

        next.x = current.x;   // Right
        next.y = current.y + 1;
        if (canMoveTo(maze, rows, cols, next)) {
            maze[next.x][next.y] = 'X';   // Mark as visited
            stack[top++] = next;           // Push onto the stack
        }
    }

    return 0;   // Could not find a route
}

int main() {
    char maze[MAX_ROWS][MAX_COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '.', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int rows = 10;
    int cols = 10;
    Cell start = {1, 1};   // Starting cell
    Cell end = {8, 8};     // Ending cell

    printf("Original maze:\n");
    printMaze(maze, rows, cols);

    if (findRoute(maze, rows, cols, start, end)) {
        printf("Found a route:\n");
        printMaze(maze, rows, cols);
    } else {
        printf("Could not find a route.\n");
    }

    return 0;
}