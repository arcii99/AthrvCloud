//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int matrix[ROW_SIZE][COL_SIZE] = {
    {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1}
};

int start_row = 0;
int start_col = 0;
int end_row = 7;
int end_col = 9;

void check_route(int row, int col, bool visited[ROW_SIZE][COL_SIZE], int path[], int path_index) {
    if (row == end_row && col == end_col) {
        printf("Path found: ");
        for (int i = 0; i < path_index; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    
    if (row < 0 || row >= ROW_SIZE || col < 0 || col >= COL_SIZE || visited[row][col] || matrix[row][col] == 0) {
        return;
    }
    
    visited[row][col] = true;
    path[path_index] = matrix[row][col];
    path_index++;

    check_route(row, col+1, visited, path, path_index);
    check_route(row+1, col, visited, path, path_index);
    check_route(row, col-1, visited, path, path_index);
    check_route(row-1, col, visited, path, path_index);

    visited[row][col] = false;
    path_index--;
}

int main() {
    bool visited[ROW_SIZE][COL_SIZE];
    int path[ROW_SIZE * COL_SIZE];
    int path_index = 0;
    
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            visited[i][j] = false;
        }
    }

    check_route(start_row, start_col, visited, path, path_index);

    return 0;
}