//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'.', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '.'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int startRow = 1;
int startCol = 1;
int endRow = 8;
int endCol = 8;

bool visited[ROW][COL];

void findRoute(int row, int col) {
    if(row == endRow && col == endCol) {
        return;
    }
    visited[row][col] = true;
    if(maze[row][col+1] != '#' && !visited[row][col+1]) {
        printf("(%d,%d) -> ", row, col+1);
        findRoute(row, col+1);
        if(row == endRow && col+1 == endCol) {
            return;
        }
    }
    if(maze[row+1][col] != '#' && !visited[row+1][col]) {
        printf("(%d,%d) -> ", row+1, col);
        findRoute(row+1, col);
        if(row+1 == endRow && col == endCol) {
            return;
        }
    }
    if(maze[row][col-1] != '#' && !visited[row][col-1]) {
        printf("(%d,%d) -> ", row, col-1);
        findRoute(row, col-1);
        if(row == endRow && col-1 == endCol) {
            return;
        }
    }
    if(maze[row-1][col] != '#' && !visited[row-1][col]) {
        printf("(%d,%d) -> ", row-1, col);
        findRoute(row-1, col);
        if(row-1 == endRow && col == endCol) {
            return;
        }
    }
}

int main() {
    printf("Starting at (%d,%d)\n", startRow, startCol);
    findRoute(startRow, startCol);
    printf("(%d,%d)\n", endRow, endCol);
    return 0;
}