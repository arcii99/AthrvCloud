//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

void printMaze(int maze[][COL], int row, int col);
int solveMaze(int maze[][COL], int row, int col, int startRow, int startCol, int endRow, int endCol);

int main() {
    int maze[ROW][COL] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
                          {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
                          {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                          {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    int startRow = 1;
    int startCol = 1;
    int endRow = 8;
    int endCol = 8;

    printf("Maze before solving:\n");
    printMaze(maze, ROW, COL);

    if(solveMaze(maze, ROW, COL, startRow, startCol, endRow, endCol)) {
        printf("Maze after solving:\n");
        printMaze(maze, ROW, COL);
    } else {
        printf("No solution found!\n");
    }

    return 0;
}

void printMaze(int maze[][COL], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int maze[][COL], int row, int col, int startRow, int startCol, int endRow, int endCol) {
    if(startRow == endRow && startCol == endCol) {
        return 1;
    }

    if(startRow < 0 || startCol < 0 || startRow >= row || startCol >= col) {
        return 0;
    }

    if(maze[startRow][startCol] != 0) {
        return 0;
    }

    maze[startRow][startCol] = 5;

    if(solveMaze(maze, row, col, startRow - 1, startCol, endRow, endCol)) {
        return 1;
    }

    if(solveMaze(maze, row, col, startRow + 1, startCol, endRow, endCol)) {
        return 1;
    }

    if(solveMaze(maze, row, col, startRow, startCol - 1, endRow, endCol)) {
        return 1;
    }

    if(solveMaze(maze, row, col, startRow, startCol + 1, endRow, endCol)) {
        return 1;
    }

    maze[startRow][startCol] = 0;

    return 0;
}