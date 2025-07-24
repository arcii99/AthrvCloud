//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

// Function to print the maze
void printMaze(char maze[][COLS], int startRow, int startCol, int endRow, int endCol) {
    // Set the start and end points
    maze[startRow][startCol] = 'S';
    maze[endRow][endCol] = 'E';

    // Print the maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a point is valid
int isValid(char maze[][COLS], int row, int col, int visited[][COLS]) {
    // Check if the point is within the maze and not already visited or blocked
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '#' && visited[row][col] == 0);
}

// Function to find the route using BFS
void findRoute(char maze[][COLS], int startRow, int startCol, int endRow, int endCol) {
    int i, row, col, found = 0, front = 0, rear = 0;
    int visited[ROWS][COLS] = {0}, parent[ROWS][COLS][2], queue[ROWS * COLS][2];

    // Initialize the queue with start point
    queue[rear][0] = startRow;
    queue[rear++][1] = startCol;
    visited[startRow][startCol] = 1;

    while (front < rear) {
        // Dequeue the current point
        row = queue[front][0];
        col = queue[front++][1];

        // Check if the end point is reached
        if (row == endRow && col == endCol) {
            found = 1;
            break;
        }

        // Check the adjacent points
        if (isValid(maze, row - 1, col, visited)) {
            visited[row - 1][col] = 1;
            parent[row - 1][col][0] = row;
            parent[row - 1][col][1] = col;
            queue[rear][0] = row - 1;
            queue[rear++][1] = col;
        }
        if (isValid(maze, row + 1, col, visited)) {
            visited[row + 1][col] = 1;
            parent[row + 1][col][0] = row;
            parent[row + 1][col][1] = col;
            queue[rear][0] = row + 1;
            queue[rear++][1] = col;
        }
        if (isValid(maze, row, col - 1, visited)) {
            visited[row][col - 1] = 1;
            parent[row][col - 1][0] = row;
            parent[row][col - 1][1] = col;
            queue[rear][0] = row;
            queue[rear++][1] = col - 1;
        }
        if (isValid(maze, row, col + 1, visited)) {
            visited[row][col + 1] = 1;
            parent[row][col + 1][0] = row;
            parent[row][col + 1][1] = col;
            queue[rear][0] = row;
            queue[rear++][1] = col + 1;
        }
    }

    if (found) {
        // Trace the path back from the end point to start point
        int path[ROWS * COLS][2], pathLength = 0;
        row = endRow;
        col = endCol;
        while (row != startRow || col != startCol) {
            path[pathLength][0] = row;
            path[pathLength++][1] = col;
            int tempRow = parent[row][col][0];
            col = parent[row][col][1];
            row = tempRow;
        }
        path[pathLength][0] = row;
        path[pathLength++][1] = col;

        // Print the path on the maze
        for (i = pathLength - 1; i >= 0; i--) {
            char symbol = (i == pathLength - 1) ? 'E' : 'X';
            maze[path[i][0]][path[i][1]] = symbol;
        }
        printMaze(maze, startRow, startCol, endRow, endCol);
    } else {
        printf("No path found!\n");
    }
}

int main() {
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#'}
    };
    int startRow = 1, startCol = 1, endRow = 3, endCol = 3;

    printMaze(maze, startRow, startCol, endRow, endCol);
    printf("\n");

    findRoute(maze, startRow, startCol, endRow, endCol);

    return 0;
}