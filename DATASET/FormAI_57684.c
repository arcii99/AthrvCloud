//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '#', '.', '.', '#', '.', '#'},
    {'#', '#', '.', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int start_row = 1, start_col = 1;
int end_row = 8, end_col = 8;

bool visited[ROWS][COLS] = {false};

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool find_route(int row, int col) {
    if (row == end_row && col == end_col) {
        return true;
    }
    
    if (maze[row][col] == '#' || visited[row][col]) {
        return false;
    }
    
    visited[row][col] = true;
    
    if (row > 0 && find_route(row - 1, col)) {
        return true;
    }
    
    if (row < ROWS - 1 && find_route(row + 1, col)) {
        return true;
    }
    
    if (col > 0 && find_route(row, col - 1)) {
        return true;
    }
    
    if (col < COLS - 1 && find_route(row, col + 1)) {
        return true;
    }
    
    return false;
}

int main() {
    printf("*** MAZE ***\n");
    print_maze();
    
    if (find_route(start_row, start_col)) {
        printf("Route found!\n");
        print_maze();
    } else {
        printf("No route found!\n");
    }
    
    return 0;
}