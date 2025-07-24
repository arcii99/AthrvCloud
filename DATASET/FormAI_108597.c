//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

char maze[ROW][COL] =   { {'+', '-', '-', '-', '+'},
                          {'|', ' ', ' ', ' ', '|'},
                          {'|', ' ', '+', '+', '|'},
                          {'|', ' ', '|', ' ', '|'},
                          {'+', '-', '-', '-', '+'} };

bool visited[ROW][COL];
char path[ROW][COL];
int path_index = 0;

bool is_valid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && maze[row][col] == ' ' && !visited[row][col];
}

void print_path() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (path[i][j] != ' ') {
                printf("%c ", path[i][j]);
            }
            else {
                printf("%c ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

bool dfs(int row, int col, int end_row, int end_col) {
    visited[row][col] = true;
    if (row == end_row && col == end_col) {
        path[row][col] = '*';
        print_path();
        path[row][col] = ' ';
        visited[row][col] = false;
        return true;
    }
    path[row][col] = '-';
    path_index++;
    if (is_valid(row + 1, col)) {
        if (dfs(row + 1, col, end_row, end_col)) {
            path_index--;
            path[row][col] = ' ';
            visited[row][col] = false;
            return true;
        }
    }
    if (is_valid(row - 1, col)) {
        if (dfs(row - 1, col, end_row, end_col)) {
            path_index--;
            path[row][col] = ' ';
            visited[row][col] = false;
            return true;
        }
    }
    if (is_valid(row, col + 1)) {
        if (dfs(row, col + 1, end_row, end_col)) {
            path_index--;
            path[row][col] = ' ';
            visited[row][col] = false;
            return true;
        }
    }
    if (is_valid(row, col - 1)) {
        if (dfs(row, col - 1, end_row, end_col)) {
            path_index--;
            path[row][col] = ' ';
            visited[row][col] = false;
            return true;
        }
    }
    path_index--;
    path[row][col] = ' ';
    visited[row][col] = false;
    return false;
}

int main() {
    int start_row = 1, start_col = 1, end_row = 3, end_col = 3;
    dfs(start_row, start_col, end_row, end_col);
    return 0;
}