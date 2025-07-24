//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = 
{
    {'S', '.', '.', '.', '.', '.', '.', '.', '.', 'X'},
    {'.', 'X', '.', 'X', '.', 'X', '.', 'X', 'X', '.'},
    {'.', 'X', '.', '.', '.', 'X', '.', 'X', 'X', '.'},
    {'.', '.', '.', 'X', '.', '.', '.', '.', '.', '.'},
    {'.', 'X', '.', 'X', '.', 'X', '.', 'X', '.', '.'},
    {'.', '.', '.', '.', '.', 'X', '.', 'X', '.', '.'},
    {'.', 'X', 'X', 'X', '.', 'X', '.', 'X', '.', 'X'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', 'X', 'X', 'X', '.', 'X', 'X', 'X', '.', 'X'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'G'}
};

enum Cell {
    EMPTY,
    BLOCKED,
    PATH
};

struct Point {
    int row;
    int col;
};

int is_valid_location(int row, int col) {
    if (row < 0 || row > ROWS - 1 || col < 0 || col > COLS - 1) {
        return 0;
    }

    if (maze[row][col] == 'X') {
        return 0;
    }

    return 1;
}

int is_valid_move(struct Point current, struct Point next) {
    int row_diff = next.row - current.row;
    int col_diff = next.col - current.col;

    if ((row_diff == 0 && col_diff == -1) ||
        (row_diff == 0 && col_diff == 1) ||
        (row_diff == -1 && col_diff == 0) ||
        (row_diff == 1 && col_diff == 0)) {
        return 1;
    }

    return 0;
}

int find_path(int row, int col) {
    if (!is_valid_location(row, col)) {
        return 0;
    }

    if (maze[row][col] == 'G') {
        maze[row][col] = 'P';
        return 1;
    }

    if (maze[row][col] != 'S' && maze[row][col] != 'G') {
        maze[row][col] = 'P';
    }

    int found = find_path(row, col - 1) ||
                find_path(row, col + 1) ||
                find_path(row - 1, col) ||
                find_path(row + 1, col);

    if (found) {
        return 1;
    }

    if (maze[row][col] != 'S') {
        maze[row][col] = '.';
    }

    return 0;
}

int main() {
    int start_row, start_col;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 'S') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    if (find_path(start_row, start_col)) {
        printf("Path found!\n");
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }

        printf("\n");
    }

    return 0;
}