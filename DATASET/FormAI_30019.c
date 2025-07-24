//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define WALL '#'
#define PATH ' '

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ','#',' ',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#','#',' ','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ','#',' ',' ','#'},
    {'#','#','#','#','#',' ','#','#','#','#'},
    {'#',' ',' ',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#','#','#',' ','#',' ','#','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

void printMaze()
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", maze[i][j]);
        }
        putchar('\n');
    }
}

int findPath(int x, int y)
{
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) { // out of boundary
        return 0;
    }
    if (maze[x][y] == PATH) { // already visited
        return 0;
    }
    if (maze[x][y] == WALL) { // wall
        return 0;
    }
    if (x == ROWS - 1 && y == COLS - 1) { // reached the destination
        return 1;
    }
    maze[x][y] = PATH; // mark the current cell as visited
    if (findPath(x + 1, y) || findPath(x - 1, y) || findPath(x, y + 1) || findPath(x, y - 1)) { // explore the neighbouring cells
        return 1; // found a path
    }
    maze[x][y] = '#'; // mark the current cell as not visited
    return 0; // unable to find a path
}

int main(void)
{
    printf("Original maze:\n");
    printMaze();
    putchar('\n');
    if (findPath(0, 0)) {
        printf("Path found!\n");
        printMaze();
    } else {
        printf("Path not found.\n");
    }
    return 0;
}