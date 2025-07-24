//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>

#define ROWS 5
#define COLS 5

struct node {
    int row;
    int col;
};

int moves[4][2] = {{-1,0}, {0,-1}, {0,1}, {1,0}};

int is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

int is_obstacle(int grid[ROWS][COLS], int row, int col) {
    return grid[row][col] == 1;
}

int is_destination(int row, int col, struct node dest) {
    return row == dest.row && col == dest.col;
}

void print_path(int path[ROWS][COLS]) {
    printf("Path:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (path[i][j] == 1) {
                printf("[%d,%d] ", i, j);
            }
        }
    }
}

void bfs(int grid[ROWS][COLS], struct node src, struct node dest) {
    int visited[ROWS][COLS] = {{0}};
    int queue_row[ROWS*COLS];
    int queue_col[ROWS*COLS];
    int path[ROWS][COLS] = {{0}};

    int front = 0, rear = 0;
    queue_row[rear] = src.row;
    queue_col[rear] = src.col;
    rear++;

    visited[src.row][src.col] = 1;

    while (front < rear) {
        int curr_row = queue_row[front];
        int curr_col = queue_col[front];
        front++;

        if (is_destination(curr_row, curr_col, dest)) {
            int row = curr_row;
            int col = curr_col;
            while (!is_destination(row, col, src)) {
                path[row][col] = 1;
                int temp_row = row;
                row = visited[row][col] / COLS;
                col = visited[temp_row][col] % COLS;
            }
            path[src.row][src.col] = 1;
            print_path(path);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int new_row = curr_row + moves[i][0];
            int new_col = curr_col + moves[i][1];
            if (is_valid(new_row, new_col) && !visited[new_row][new_col] && !is_obstacle(grid, new_row, new_col)) {
                visited[new_row][new_col] = curr_row*COLS + curr_col;
                queue_row[rear] = new_row;
                queue_col[rear] = new_col;
                rear++;
            }
        }
    }

    printf("Destination not reachable.");
}

int main() {
    int grid[ROWS][COLS] = {{0,0,0,1,0},
                            {0,1,0,1,0},
                            {0,1,0,0,0},
                            {1,1,0,1,0},
                            {0,0,0,1,0}};
    struct node src = {0, 0};
    struct node dest = {4, 4};

    bfs(grid, src, dest);

    return 0;
}