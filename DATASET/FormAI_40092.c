//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 1, 1, 1, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
};

void print_maze() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int can_move(int r, int c) {
    if (r >= 0 && r < ROWS && c >= 0 && c < COLS && maze[r][c] == 1) {
        return 1;
    } else {
        return 0;
    }
}

int solve_maze(int r, int c) {
    if (r == ROWS - 1 && c == COLS - 1) {
        maze[r][c] = 2;
        return 1;
    }

    if (can_move(r, c)) {
        maze[r][c] = 2;

        if (solve_maze(r + 1, c) || solve_maze(r, c + 1) || solve_maze(r - 1, c) || solve_maze(r, c - 1)) {
            return 1;
        }

        maze[r][c] = 1;
    }

    return 0;
}

int main() {
    printf("Original Maze\n");
    print_maze();

    if (solve_maze(0, 0)) {
        printf("\n\nSolved Maze\n");
        print_maze();
    } else {
        printf("\n\nThis maze is unsolvable.\n");
    }

    return 0;
}