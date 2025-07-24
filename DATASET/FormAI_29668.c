//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int maze[ROW_SIZE][COL_SIZE] = {
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
};

bool is_valid_move(int row, int col) {
    if (row < 0 || row >= ROW_SIZE || col < 0 || col >= COL_SIZE || maze[row][col] == 0) {
        return false;
    }
    return true;
}

bool solve_maze_helper(int row, int col, int solution[ROW_SIZE][COL_SIZE]) {
    if (row == ROW_SIZE - 1 && col == COL_SIZE - 1) {
        solution[row][col] = 1;
        return true;
    }

    if (is_valid_move(row, col)) {
        solution[row][col] = 1;
        if (solve_maze_helper(row + 1, col, solution)) {
            return true;
        }
        if (solve_maze_helper(row, col + 1, solution)) {
            return true;
        }
        solution[row][col] = 0;
    }

    return false;
}

void solve_maze() {
    int solution[ROW_SIZE][COL_SIZE] = {{0}};
    if (solve_maze_helper(0, 0, solution)) {
        printf("Solution:\n");
        for (int i = 0; i < ROW_SIZE; i++) {
            for (int j = 0; j < COL_SIZE; j++) {
                printf("%d ", solution[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found.\n");
    }
}

int main() {
    printf("Maze:\n");
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    solve_maze();
    return 0;
}