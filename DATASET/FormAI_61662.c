//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 4
#define COL_SIZE 5
#define INF 999999

typedef struct {
    int row, col;
} Point;

int maze[ROW_SIZE][COL_SIZE] = {
    {0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {1, 0, 0, 0, 0}
};

int distance[ROW_SIZE][COL_SIZE];
Point path[ROW_SIZE * COL_SIZE];
int path_index;

void print_path() {
    printf("Path: ");
    for (int i = 0; i < path_index; i++) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

void dijkstra(int start_row, int start_col, int end_row, int end_col) {
    // Initialize distance
    for (int i = 0; i < ROW_SIZE; i++) {
        for (int j = 0; j < COL_SIZE; j++) {
            distance[i][j] = INF;
        }
    }

    // Initialize queue
    int queue_size = ROW_SIZE * COL_SIZE;
    Point queue[queue_size];
    int front = 0, rear = 0;

    // Add start point to queue
    distance[start_row][start_col] = 0;
    queue[rear++] = (Point) {start_row, start_col};

    // Iterate through queue
    while (front < rear) {
        Point current = queue[front++];
        int row = current.row;
        int col = current.col;

        // Check if we've reached the end
        if (row == end_row && col == end_col) {
            // Reconstruct path
            path_index = 0;
            Point p = (Point) {end_row, end_col};
            while (p.row != start_row || p.col != start_col) {
                path[path_index++] = p;
                p = (Point) {p.row - 1, p.col};
            }
            path[path_index++] = (Point) {start_row, start_col};

            // Print path and return
            print_path();
            return;
        }

        // Check neighbors
        int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int n_row = row + neighbors[i][0];
            int n_col = col + neighbors[i][1];
            if (n_row < 0 || n_row >= ROW_SIZE || n_col < 0 || n_col >= COL_SIZE) {
                continue;
            }
            
            int d = maze[n_row][n_col] == 1 ? 2 : 1;
            int new_distance = distance[row][col] + d;

            if (new_distance < distance[n_row][n_col]) {
                distance[n_row][n_col] = new_distance;
                queue[rear++] = (Point) {n_row, n_col};
            }
        }
    }

    // No path found
    printf("No path found.\n");
}

int main() {
    dijkstra(0, 0, 3, 4);
    return 0;
}