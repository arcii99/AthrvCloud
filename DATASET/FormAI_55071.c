//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 15

bool maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
};

#define WALL 1
#define PATH 0

#define START_ROW 1
#define START_COL 1

#define END_ROW 8
#define END_COL 13

bool solved[ROWS][COLS] = { false };

bool solve(int row, int col) {
    if (row == END_ROW && col == END_COL) {
        solved[row][col] = true;
        return true;
    }

    if (maze[row][col] == WALL) {
        return false;
    }

    if (solved[row][col]) {
        return true;
    }

    solved[row][col] = true;

    if (row < ROWS - 1 && solve(row + 1, col)) {
        return true;
    }

    if (col < COLS - 1 && solve(row, col + 1)) {
        return true;
    }

    if (row > 0 && solve(row - 1, col)) {
        return true;
    }

    if (col > 0 && solve(row, col - 1)) {
        return true;
    }

    return false;
}

int main() {
    if (solve(START_ROW, START_COL)) {
        printf("Maze Solved\n");
    } else {
        printf("Cannot solve maze\n");
    }

    // Print the solved maze
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (maze[row][col] == WALL) {
                printf("#");
            } else if (solved[row][col]) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}