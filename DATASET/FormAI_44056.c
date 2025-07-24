//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#define ROWS 10
#define COLS 10

// Maze structure
struct Maze {
    int maze[ROWS][COLS];
};

// Stack data structure
struct Stack {
    int row;
    int col;
};

// Global variables
struct Maze maze;
int startRow, startCol, endRow, endCol;

// Function to push into stack
void push(struct Stack stack[], int *stackPtr, int row, int col) {
    stack[*stackPtr].row = row;
    stack[*stackPtr].col = col;
    (*stackPtr)++;
}

// Function to pop from stack
void pop(struct Stack stack[], int *stackPtr, int *row, int *col) {
    (*stackPtr)--;
    *row = stack[*stackPtr].row;
    *col = stack[*stackPtr].col;
}

// Function to check if cell is inside boundaries of the maze
int withinBounds(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

// Function to print the maze
void printMaze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", maze.maze[i][j]);
        }
        printf("\n");
    }
}

// Function to solve the maze using Depth-First Search algorithm
void dfs() {
    struct Stack stack[ROWS * COLS];
    int stackPtr = 0;
    int curRow, curCol;

    push(stack, &stackPtr, startRow, startCol);

    while (stackPtr > 0) {
        pop(stack, &stackPtr, &curRow, &curCol);
        if (curRow == endRow && curCol == endCol) {
            return;
        }
        if (withinBounds(curRow, curCol) && maze.maze[curRow][curCol] == 0) {
            maze.maze[curRow][curCol] = 1;
            push(stack, &stackPtr, curRow-1, curCol); // up
            push(stack, &stackPtr, curRow+1, curCol); // down
            push(stack, &stackPtr, curRow, curCol-1); // left
            push(stack, &stackPtr, curRow, curCol+1); // right
        }
    }
}

// Main function
int main() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze.maze[i][j] = 0;
        }
    }

    startRow = 0;
    startCol = 0;
    endRow = ROWS-1;
    endCol = COLS-1;

    maze.maze[startRow][startCol] = 1; // Start cell
    maze.maze[endRow][endCol] = 1; // End cell

    dfs();

    printMaze();

    return 0;
}