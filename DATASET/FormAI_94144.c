//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>

#define ROW 5
#define COLUMN 6

int graph[ROW][COLUMN] = {
    {1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

int visited[ROW][COLUMN];
int pred[ROW][COLUMN];

int start_row = 0, start_column = 0;
int end_row = 4, end_column = 5;

void dfs(int row, int column) {
    visited[row][column] = 1;

    if (row == end_row && column == end_column) {
        return;
    }

    // right
    if (column + 1 < COLUMN && graph[row][column + 1] && !visited[row][column + 1]) {
        pred[row][column + 1] = column;
        dfs(row, column + 1);
    }

    // down
    if (row + 1 < ROW && graph[row + 1][column] && !visited[row + 1][column]) {
        pred[row + 1][column] = row;
        dfs(row + 1, column);
    }

    // left
    if (column - 1 >= 0 && graph[row][column - 1] && !visited[row][column - 1]) {
        pred[row][column - 1] = column;
        dfs(row, column - 1);
    }

    // up
    if (row - 1 >= 0 && graph[row - 1][column] && !visited[row - 1][column]) {
        pred[row - 1][column] = row;
        dfs(row - 1, column);
    }
}

void print_path() {
    int path[COLUMN * ROW], path_size = 0;

    int current_row = end_row, current_column = end_column;
    while (current_row != start_row || current_column != start_column) {
        int temp_row = current_row;
        current_row = pred[current_row][current_column];
        current_column = temp_row;

        path[path_size++] = current_column;
    }

    printf("\nPath found: ");
    for (int i = path_size - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
}

int main() {
    dfs(start_row, start_column);

    if (!visited[end_row][end_column]) {
        printf("No path found\n");
    } else {
        print_path();
    }
    return 0;
}