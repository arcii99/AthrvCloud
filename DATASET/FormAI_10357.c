//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 15

char maze[ROWS][COLS+1] = {
    "***************",
    "*             *",
    "* *** *********",
    "*   ***       *",
    "*** * *** *****",
    "*     *   *   *",
    "***** ***** * *",
    "*     *       *",
    "* *** ***** ***",
    "*   *     *   *",
    "***************"
};

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", maze[i]);
    }
}

int isValidMove(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '*';
}

int isExit(int row, int col) {
    return row == 0 || row == ROWS-1 || col == 0 || col == COLS-1;
}

void findRoute(int row, int col) {
    if (isExit(row, col)) {
        printf("Exit found at (%d, %d)!\n", row, col);
        exit(0);
    }

    maze[row][col] = '*';

    if (isValidMove(row-1, col)) findRoute(row-1, col); // up
    if (isValidMove(row+1, col)) findRoute(row+1, col); // down
    if (isValidMove(row, col-1)) findRoute(row, col-1); // left
    if (isValidMove(row, col+1)) findRoute(row, col+1); // right

    maze[row][col] = ' ';
}

int main() {
    printf("Starting maze:\n");
    printMaze();

    printf("Finding a route to the exit...\n");
    findRoute(ROWS-2, 1);

    printf("No route found!\n");

    return 0;
}