//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
//Welcome to the Irregular Pathfinding Algorithm!
//This program will find a path through an irregular maze.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// A struct to hold a coordinate
typedef struct {
    int row;
    int col;
} Coordinate;

// Function to print the maze
void printMaze(int maze[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(". ");
            } else if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a coordinate is within the bounds of the maze
int inBounds(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// Function to find a path through the maze
int findPath(int maze[][COLS], Coordinate start, Coordinate end) {
    int visited[ROWS][COLS] = {{ 0 }};
    visited[start.row][start.col] = 1;

    Coordinate stack[ROWS * COLS];
    int top = 0;
    stack[top] = start;

    while (top >= 0) {
        Coordinate current = stack[top];
        top--;

        if (current.row == end.row && current.col == end.col) {
            return 1;
        }

        if (inBounds(current.row - 1, current.col) && 
        !visited[current.row - 1][current.col] && maze[current.row - 1][current.col] != 1) {
            visited[current.row - 1][current.col] = 1;
            stack[++top] = (Coordinate) {current.row - 1, current.col};
        }

        if (inBounds(current.row + 1, current.col) &&
        !visited[current.row + 1][current.col] && maze[current.row + 1][current.col] != 1) {
            visited[current.row + 1][current.col] = 1;
            stack[++top] = (Coordinate) {current.row + 1, current.col};
        }

        if (inBounds(current.row, current.col - 1) &&
        !visited[current.row][current.col - 1] && maze[current.row][current.col - 1] != 1) {
            visited[current.row][current.col - 1] = 1;
            stack[++top] = (Coordinate) {current.row, current.col - 1};
        }

        if (inBounds(current.row, current.col + 1) &&
        !visited[current.row][current.col + 1] && maze[current.row][current.col + 1] != 1) {
            visited[current.row][current.col + 1] = 1;
            stack[++top] = (Coordinate) {current.row, current.col + 1};
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    // Generate random maze
    int maze[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = rand() % 10;
            if (r == 0) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }

    // Place start and end points
    Coordinate start = (Coordinate) {0, 0};
    Coordinate end = (Coordinate) {ROWS - 1, COLS - 1};
    maze[start.row][start.col] = 2;
    maze[end.row][end.col] = 2;

    // Print initial maze
    printf("Initial Maze:\n");
    printMaze(maze);

    // Find path through maze
    if (findPath(maze, start, end)) {
        printf("Solution Found!\n");
    } else {
        printf("No Solution Found!\n");
    }

    // Print final maze
    printf("Final Maze:\n");
    printMaze(maze);

    return 0;
}