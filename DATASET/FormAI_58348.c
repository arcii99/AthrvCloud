//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

bool is_valid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool is_not_obstacle(int grid[ROW][COL], int row, int col) {
    return (grid[row][col] != 0);
}

bool is_destination(int row, int col, int dest_row, int dest_col) {
    return (row == dest_row) && (col == dest_col);
}

void print_path(int path[ROW][COL], int dest_row, int dest_col) {
    printf("\nPath:\n");
    int row = dest_row;
    int col = dest_col;
    while (path[row][col] != -1) {
        printf("(%d,%d) -> ", row, col);
        int temp_row = row;
        row = path[row][col] / 10;
        col = path[temp_row][col] % 10;
    }
    printf("(%d,%d)\n", row, col);
}

void dfs(int grid[ROW][COL], int row, int col, int dest_row, int dest_col, int path[ROW][COL], bool* found, int visited[ROW][COL]) {
    if (*found) return;
    visited[row][col] = 1;
    if (is_destination(row, col, dest_row, dest_col)) {
        *found = true;
        print_path(path, dest_row, dest_col);
        return;
    }
    int row_move[] = {-1, 0, 0, 1};
    int col_move[] = {0, -1, 1, 0};
    for (int i = 0; i < 4; i++) {
        int next_row = row + row_move[i];
        int next_col = col + col_move[i];
        if (is_valid(next_row, next_col) && is_not_obstacle(grid, next_row, next_col) && !visited[next_row][next_col]) {
            path[next_row][next_col] = row*10 + col; // Store previous cell coordinates
            dfs(grid, next_row, next_col, dest_row, dest_col, path, found, visited);
        }
    }
}

void find_path(int grid[ROW][COL], int src_row, int src_col, int dest_row, int dest_col) {
    int path[ROW][COL];
    int visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1; // Initialize path
            visited[i][j] = 0; // Initialize visited
        }
    }
    bool found = false;
    dfs(grid, src_row, src_col, dest_row, dest_col, path, &found, visited); // Call DFS Algorithm
    if (!found) {
        printf("\nPath does not exist!");
    }
}

int main() {
    int grid[ROW][COL] = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 1, 1}
    }; // 0 means obstacle and 1 means path
    int src_row = 0, src_col = 0;
    int dest_row = 4, dest_col = 4;
    printf("Source: (%d,%d)\n", src_row, src_col);
    printf("Destination: (%d,%d)\n", dest_row, dest_col);
    find_path(grid, src_row, src_col, dest_row, dest_col);
    return 0;
}