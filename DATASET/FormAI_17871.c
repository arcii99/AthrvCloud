//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#define ROWS 10
#define COLS 10

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int findPath(char maze[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    if (maze[row][col] == '#') {
        return 0;
    }

    if (maze[row][col] == 'G') {
        return 1;
    }

    maze[row][col] = '#';

    if (findPath(maze, row, col+1)) {
        maze[row][col] = '>';
        return 1;
    }

    if (findPath(maze, row, col-1)) {
        maze[row][col] = '<';
        return 1;
    }

    if (findPath(maze, row+1, col)) {
        maze[row][col] = 'v';
        return 1;
    }

    if (findPath(maze, row-1, col)) {
        maze[row][col] = '^';
        return 1;
    }

    return 0;
}

int main() {
    char maze[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#',' ','#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#','#','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ',' ',' ','#',' ','#','#'},
        {'#',' ',' ',' ','#','#','#',' ','#','#'},
        {'#',' ','#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
        {'#','#','#','#','#','#','#','#','#','#'}
    };

    printf("Original Maze:\n");
    printMaze(maze);

    int pathExists = findPath(maze, 1, 1);

    if (pathExists) {
        printf("Path Found:\n");
        printMaze(maze);
    } else {
        printf("Path Not Found\n");
    }

    return 0;
}