//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5
#define START_ROW 0
#define START_COL 0
#define END_ROW 4
#define END_COL 4

typedef struct {
    int row, col;
} Point;

bool is_valid_move(int row, int col, int visited[ROW][COL]) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return false;
    if (visited[row][col])
        return false;
    return true;
}

bool dfs(int maze[ROW][COL], int visited[ROW][COL], Point curr_pos) {
    if (curr_pos.row == END_ROW && curr_pos.col == END_COL)
        return true;
    visited[curr_pos.row][curr_pos.col] = 1;
    int row_moves[] = {-1, 0, 1, 0};
    int col_moves[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int next_row = curr_pos.row + row_moves[i];
        int next_col = curr_pos.col + col_moves[i];
        if (is_valid_move(next_row, next_col, visited) && maze[next_row][next_col]) {
            Point next_pos = {next_row, next_col};
            if (dfs(maze, visited, next_pos))
                return true;
        }
    }
    return false;
}

int main() {
    int maze[ROW][COL] = {
        {1, 0, 0, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 0, 1}
    };
    int visited[ROW][COL] = {0};
    Point start_pos = {START_ROW, START_COL};
    if (dfs(maze, visited, start_pos))
        printf("Found Path!");
    else
        printf("Path not found.");
    return 0;
}