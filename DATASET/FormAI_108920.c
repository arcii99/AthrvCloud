//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%c ", maze[i][j]);
        printf("\n");
    }
}

int findPath(char maze[ROWS][COLS], int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
        return 0; // out of bounds

    if (maze[x][y] == '#' || maze[x][y] == '*')
        return 0; // obstacle or already visited

    if (maze[x][y] == 'G')
        return 1; // found the goal

    maze[x][y] = '*'; // mark as visited

    if (findPath(maze, x-1, y))
        return 1;
    if (findPath(maze, x+1, y))
        return 1;
    if (findPath(maze, x, y-1))
        return 1;
    if (findPath(maze, x, y+1))
        return 1;

    return 0; // no path found
}

int main() {
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', 'G', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    printf("Original maze:\n");
    printMaze(maze);

    if (findPath(maze, 1, 1)) {
        printf("\nPath found!\n");
        printMaze(maze);
    } else {
        printf("\nNo path found.\n");
    }

    return 0;
}