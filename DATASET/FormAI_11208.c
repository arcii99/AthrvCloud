//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROW 11
#define MAX_COL 11

bool is_valid(int maze[MAX_ROW][MAX_COL], int row, int col) {
    if(row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL || maze[row][col] == 0) {
        return false;
    }
    return true;
}

bool solve_maze_helper(int maze[MAX_ROW][MAX_COL], int sol[MAX_ROW][MAX_COL], int row, int col) {
    if(row == MAX_ROW-1 && col == MAX_COL-1) {
        sol[row][col] = 1;
        return true;
    }
    if(is_valid(maze, row, col)) {
        sol[row][col] = 1;
        if(solve_maze_helper(maze, sol, row+1, col)) {
            return true;
        }
        if(solve_maze_helper(maze, sol, row, col+1)) {
            return true;
        }
        sol[row][col] = 0;
        return false;
    }
    return false;
}

bool solve_maze(int maze[MAX_ROW][MAX_COL]) {
    int sol[MAX_ROW][MAX_COL] = {0};
    if(solve_maze_helper(maze, sol, 0, 0)) {
        for(int i = 0; i < MAX_ROW; i++) {
            for(int j = 0; j < MAX_COL; j++) {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
        return true;
    }
    printf("No Solution.\n");
    return false;
}

int main() {
    int maze[MAX_ROW][MAX_COL] = { 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
    };
    solve_maze(maze);
    return 0;
}