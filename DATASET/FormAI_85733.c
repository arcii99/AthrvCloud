//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'S', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '.', '#', '#', '.', '#'},
    {'#', '#', '.', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', 'E'},
};
int startRow = 0; /* Starting row of the maze */
int startCol = 0; /* Starting column of the maze */

/* Function prototype to find the path */
bool findPath(int row, int col);

/* Driver function */
int main(int argc, char *argv[]) {
    if (findPath(startRow, startCol)) {
        printf("Path found!\n");
    } else {
        printf("Failed to find the path.\n");
    }

    return 0;
}

/**
 * A recursive function to find the path from start point to the end point of the maze
 *
 * @param row The current row of the maze
 * @param col The current column of the maze
 * @return True if the path is found, otherwise False
 */
bool findPath(int row, int col) {
    /* Check for out of bounds */
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }

    /* Check if the current spot is wall or already visited */
    if (maze[row][col] == '#' || maze[row][col] == 'X') {
        return false;
    }

    /* Mark the current spot as visited */
    maze[row][col] = 'X';

    /* Check if we have found the end point */
    if (maze[row][col] == 'E') {
        return true;
    }

    /* Try to move right */
    if (findPath(row, col + 1)) {
        printf("(%d, %d) -> ", row, col);
        return true;
    }

    /* Try to move down */
    if (findPath(row + 1, col)) {
        printf("(%d, %d) -> ", row, col);
        return true;
    }

    /* Try to move up */
    if (findPath(row - 1, col)) {
        printf("(%d, %d) -> ", row, col);
        return true;
    }

    /* Try to move left */
    if (findPath(row, col - 1)) {
        printf("(%d, %d) -> ", row, col);
        return true;
    }

    /* None of the above worked, backtrack */
    return false;
}