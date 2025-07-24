//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 6

char maze[ROW][COL] = {
    {'S', '#', '.', '.', '.', '.'},
    {'.', '#', '.', '.', '#', '.'},
    {'.', '#', '#', '.', '.', '.'},
    {'.', '.', '.', '#', '.', '.'},
    {'.', '.', '#', '.', '.', '.'},
    {'.', '#', '.', '#', '.', 'E'}
};

bool visited[ROW][COL];

bool isSafe(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL
            && maze[row][col] != '#' && !visited[row][col]);
}

void printPath(int path[ROW][COL]) {
    int i, j;
    printf("\nThe Path to the End:\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (path[i][j] == 0) {
                printf("%c ", maze[i][j]);
            } else {
                printf("%d ", path[i][j]);
            }
        }
        printf("\n");
    }
}

bool findEnd(int row, int col, int path[ROW][COL], int step) {
    if (maze[row][col] == 'E') {
        path[row][col] = step;
        printPath(path);
        return true;
    }
    
    visited[row][col] = true;
    path[row][col] = step;
    
    if (row > 0 && isSafe(row-1, col) && findEnd(row-1, col, path, step+1)) return true;
    if (row < ROW-1 && isSafe(row+1, col) && findEnd(row+1, col, path, step+1)) return true;
    if (col > 0 && isSafe(row, col-1) && findEnd(row, col-1, path, step+1)) return true;
    if (col < COL-1 && isSafe(row, col+1) && findEnd(row, col+1, path, step+1)) return true;
    
    path[row][col] = 0;
    return false;
}

int main() {
    int start[2], i, j;
    int path[ROW][COL];
    bool foundStart = false;
    
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            visited[i][j] = false;
            path[i][j] = 0;
            if (maze[i][j] == 'S') {
                start[0] = i;
                start[1] = j;
                foundStart = true;
            }
        }
    }
    
    if (!foundStart) {
        printf("No starting point found!\n");
        return 0;
    }
    
    if (!findEnd(start[0], start[1], path, 1)) {
        printf("No path found to the end!\n");
    }
    
    return 0;
}