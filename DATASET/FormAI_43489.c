//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>

#define ROW 10
#define COL 10

int is_safe(int matrix[ROW][COL], int visited[ROW][COL], int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (matrix[row][col] && !visited[row][col]);
}

int find_path(int matrix[ROW][COL], int visited[ROW][COL], int row, int col, int dest_row, int dest_col) {
    if (row == dest_row && col == dest_col) {
        visited[row][col] = 1;
        printf("(%d, %d) ", row, col);
        return 1;
    }

    if (is_safe(matrix, visited, row, col)) {
        visited[row][col] = 1;
        printf("(%d, %d) ", row, col);

        if (find_path(matrix, visited, row - 1, col, dest_row, dest_col))
            return 1;
        if (find_path(matrix, visited, row + 1, col, dest_row, dest_col))
            return 1;
        if (find_path(matrix, visited, row, col - 1, dest_row, dest_col))
            return 1;
        if (find_path(matrix, visited, row, col + 1, dest_row, dest_col))
            return 1;

        visited[row][col] = 0;
    }

    return 0;
}

int main() {
    int matrix[ROW][COL] = { {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
                             {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                             {1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
                             {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                             {1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
                             {1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
                             {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                             {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                             {1, 1, 0, 1, 1, 1, 0, 0, 0, 1} };

    int visited[ROW][COL], i, j;
    int src_row = 0, src_col = 0, dest_row = 7, dest_col = 5;

    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            visited[i][j] = 0;

    if (find_path(matrix, visited, src_row, src_col, dest_row, dest_col) == 0)
        printf("No path found.\n");

    return 0;
}