//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '0', '0', '1', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '1', '0', '0', '0', '1', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

int visited[ROWS][COLS] = {0};
int path[ROWS * COLS] = {0};

int start_row, start_col, end_row, end_col, path_len = 0;

void print_maze()
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col)
{
    if (row >= 0 && col >= 0 && row < ROWS && col < COLS) {
        if (maze[row][col] == '0' && visited[row][col] == 0) {
            return 1;
        }
    }
    return 0;
}

int find_path(int row, int col)
{
    int i;

    visited[row][col] = 1;
    path[path_len++] = row * COLS + col;

    if (row == end_row && col == end_col) {
        return 1;
    }

    if (is_valid(row - 1, col)) {
        if (find_path(row - 1, col)) {
            return 1;
        }
    }

    if (is_valid(row, col + 1)) {
        if (find_path(row, col + 1)) {
            return 1;
        }
    }

    if (is_valid(row + 1, col)) {
        if (find_path(row + 1, col)) {
            return 1;
        }
    }

    if (is_valid(row, col - 1)) {
        if (find_path(row, col - 1)) {
            return 1;
        }
    }

    path_len--;
    visited[row][col] = 0;

    return 0;
}

int main()
{
    print_maze();
    printf("\nEnter coordinates of start point(x,y) and end point(x,y)\n");
    scanf("%d %d %d %d", &start_row, &start_col, &end_row, &end_col);

    int res = find_path(start_row, start_col);

    if (res) {
        printf("\nPath found:\n");
        int i;
        for (i = 0; i < path_len; i++) {
            printf("(%d, %d) -> ", path[i] / COLS, path[i] % COLS);
        }
        printf("End of path\n");
    }
    else {
        printf("\nPath not found.\n");
    }

    return 0;
}