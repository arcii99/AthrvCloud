//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

char maze[MAX_ROWS][MAX_COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool visited[MAX_ROWS][MAX_COLS];

void printMaze() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= MAX_ROWS || col >= MAX_COLS) {
        return false;
    }
    if (maze[row][col] == '#' || visited[row][col]) {
        return false;
    }
    return true;
}

bool findRoute(int row, int col) {
    if (!isValid(row, col)) {
        return false;
    }
    if (maze[row][col] == 'G') {
        return true;
    }
    visited[row][col] = true;
    if (findRoute(row + 1, col) || findRoute(row - 1, col) || findRoute(row, col + 1) || findRoute(row, col - 1)) {
        return true;
    }
    return false;
}

int main() {
    printf("Starting Maze:\n");
    printMaze();
    printf("---------------------\n");

    int startRow = 1;
    int startCol = 1;
    int goalRow = 4;
    int goalCol = 6;

    if (findRoute(startRow, startCol)) {
        printf("Route found!\n");
        printf("---------------------\n");
        printMaze();
    }
    else {
        printf("Route not found.\n");
    }

    return 0;
}