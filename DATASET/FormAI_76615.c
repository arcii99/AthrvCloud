//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void displayMaze(char maze[ROWS][COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int findRoute(char maze[ROWS][COLS], int rows, int cols, int startRow, int startCol, int endRow, int endCol) {
    if (startRow < 0 || startCol < 0 || startRow >= rows || startCol >= cols) {
        return 0;
    }
    if (endRow < 0 || endCol < 0 || endRow >= rows || endCol >= cols) {
        return 0;
    }
    if (maze[startRow][startCol] == '*' || maze[endRow][endCol] == '*') {
        return 0;
    }
    if (startRow == endRow && startCol == endCol) {
        return 1;
    }
    maze[startRow][startCol] = '*';
    if (findRoute(maze, rows, cols, startRow - 1, startCol, endRow, endCol) == 1) {
        return 1;
    }
    if (findRoute(maze, rows, cols, startRow, startCol + 1, endRow, endCol) == 1) {
        return 1;
    }
    if (findRoute(maze, rows, cols, startRow + 1, startCol, endRow, endCol) == 1) {
        return 1;
    }
    if (findRoute(maze, rows, cols, startRow, startCol - 1, endRow, endCol) == 1) {
        return 1;
    }
    maze[startRow][startCol] = ' ';
    return 0;
}

int main() {
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', ' ', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    };
    int startRow = 1, startCol = 1, endRow = 8, endCol = 8;
    printf("Maze:\n");
    displayMaze(maze, ROWS, COLS);
    if (findRoute(maze, ROWS, COLS, startRow, startCol, endRow, endCol) == 1) {
        printf("Found a route!\n");
        maze[startRow][startCol] = 'S';
        maze[endRow][endCol] = 'E';
        displayMaze(maze, ROWS, COLS);
    } else {
        printf("No route found.\n");
    }
    return 0;
}