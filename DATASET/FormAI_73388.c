//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
/*
 * Pathfinding Algorithm Demo
 * Author: Linus Torvalds
 */

#include <stdio.h>
#define ROW 7
#define COL 7

/**
 * Function to print the grid after each iteration
 */
void print_grid(int grid[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Function to check if the given cell is valid
 */
int is_valid(int grid[ROW][COL], int row, int col, int visited[ROW][COL]) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (grid[row][col] == 1 && !visited[row][col]);
}

/**
 * A recursive function to find the path from start to end
 */
int find_path(int grid[ROW][COL], int row, int col, int visited[ROW][COL], int end_row, int end_col) {
    if (row == end_row && col == end_col) {
        return 1;
    }
    visited[row][col] = 1;
    int row_offset[] = {1, -1, 0, 0};
    int col_offset[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int next_row = row + row_offset[i];
        int next_col = col + col_offset[i];
        if (is_valid(grid, next_row, next_col, visited)) {
            if (find_path(grid, next_row, next_col, visited, end_row, end_col)) {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Main function that runs the demo
 */
int main() {
    int grid[ROW][COL] = {
            {1, 0, 1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1, 1, 0},
            {1, 1, 1, 0, 1, 1, 0},
            {0, 0, 0, 1, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 1}
    };
    int visited[ROW][COL] = {0};
    int start_row = 0, start_col = 0;
    int end_row = 6, end_col = 6;
    printf("Grid before pathfinding:\n");
    print_grid(grid);
    if (find_path(grid, start_row, start_col, visited, end_row, end_col)) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }
    printf("Grid after pathfinding:\n");
    print_grid(visited);
    return 0;
}