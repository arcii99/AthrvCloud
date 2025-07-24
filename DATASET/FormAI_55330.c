//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

void printMaze(char maze[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int solve(char maze[ROWS][COLUMNS], int x, int y) {
    if (x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
        return 0;
    }
    
    if (maze[x][y] == 'x') {
        return 0;
    }
    
    if (maze[x][y] == 'f') {
        return 1;
    }
    
    maze[x][y] = 'x';
    
    if (solve(maze, x + 1, y)) {
        return 1;
    }
    
    if (solve(maze, x - 1, y)) {
        return 1;
    }
    
    if (solve(maze, x, y + 1)) {
        return 1;
    }
    
    if (solve(maze, x, y - 1)) {
        return 1;
    }
    
    maze[x][y] = '.';
    
    return 0;
}

int main() {
    char maze[ROWS][COLUMNS] = {
        { '.', '.', '.', '.', 'x', '.', '.', '.', '.', '.' },
        { '.', 'x', '.', '.', 'x', '.', '.', 'x', '.', '.' },
        { '.', 'x', '.', 'x', '.', '.', '.', 'x', '.', '.' },
        { '.', 'x', '.', '.', 'x', '.', '.', '.', '.', '.' },
        { '.', '.', 'x', 'x', '.', 'x', '.', 'x', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', 'x', '.', '.' },
        { '.', '.', 'x', 'x', '.', 'x', '.', '.', '.', '.' },
        { '.', '.', '.', 'x', '.', '.', '.', '.', '.', '.' },
        { '.', 'x', '.', '.', 'x', '.', 'x', '.', '.', '.' },
        { '.', '.', '.', '.', 'f', '.', '.', '.', '.', '.' }
    };
    
    printMaze(maze);
    
    printf("\n");
    
    if (solve(maze, 0, 0)) {
        printf("The maze has a solution:\n");
        printMaze(maze);
    } else {
        printf("The maze does not have a solution.");
    }
    
    return 0;
}