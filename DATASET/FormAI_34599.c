//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '#', '#'}
};

int rowStart = 1, colStart = 1;      // starting position of maze
int rowEnd = 8, colEnd = 8;          // ending position of maze

bool findPath(int row, int col) {
    if (row == rowEnd && col == colEnd) {         // destination is reached
        maze[row][col] = '*';
        return true;
    }
    if (maze[row][col] == '.' || maze[row][col] == 'S') {
        maze[row][col] = 'V';       // mark as visited
        if (row > 0 && findPath(row - 1, col)) {             // north
            maze[row][col] = '*';
            return true;
        }
        if (col < COLS - 1 && findPath(row, col + 1)) {      // east
            maze[row][col] = '*';
            return true;
        }
        if (row < ROWS - 1 && findPath(row + 1, col)) {      // south
            maze[row][col] = '*';
            return true;
        }
        if (col > 0 && findPath(row, col - 1)) {             // west
            maze[row][col] = '*';
            return true;
        }
        maze[row][col] = '.';       // backtrack
    }
    return false;
}

int main() {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    findPath(rowStart, colStart);       // call the function to find the path
    
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}