//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '.', '#', '#'},
    {'#', '.', '.', '#', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '#', '#', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', '.', '.', '#'},
    {'.', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

bool is_valid_move(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        // Out of bounds.
        return false;
    }
    if (maze[row][col] == '#') {
        // Wall.
        return false;
    }
    return true;
}

bool find_exit(int row, int col) {
    if (!is_valid_move(row, col)) {
        return false;
    }
    if (maze[row][col] == '.') {
        // Exit found!
        return true;    
    }
    maze[row][col] = '#'; // Mark visited cell.
    if (find_exit(row, col + 1) || find_exit(row + 1, col) || find_exit(row, col - 1) || find_exit(row - 1, col)) {
        // Move right, down, left, up recursively in search for the exit.
        return true;
    }
    return false;
}

int main() {
    int start_row = 2;
    int start_col = 2;
    if (find_exit(start_row, start_col)) {
        printf("Exit found!\n");
    } else {
        printf("No exit found.\n");
    }
    return 0;
}