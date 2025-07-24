//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int m = ROW;
int n = COL;

struct Point {
    int x;
    int y;
};

bool is_valid(bool visited[ROW][COL], int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && !visited[row][col];
}

bool is_destination(struct Point point, struct Point dest) {
    return (point.x == dest.x && point.y == dest.y);
}

void print_shortest_path(int parent[ROW][COL], struct Point dest) {
    int row = dest.x;
    int col = dest.y;

    while (parent[row][col] != -1) {
        printf("(%d, %d) <= ", row, col);
        int tempRow = parent[row][col] / n;
        int tempCol = parent[row][col] % n;
        row = tempRow;
        col = tempCol;
    }
    printf("(%d, %d)\n", row, col);
}

void BFS(int mat[ROW][COL], struct Point src, struct Point dest) {
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    visited[src.x][src.y] = true;

    int dist[ROW][COL];

    memset(dist, 0, sizeof dist);

    int parent[ROW][COL];

    memset(parent, -1, sizeof parent);

    struct Point queue[ROW * COL];
    int front = -1;
    int rear = -1;

    queue[++rear] = src;

    while (front != rear) {
        struct Point point = queue[++front];

        if (is_destination(point, dest)) {
            print_shortest_path(parent, dest);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int row = point.x + rowNum[i];
            int col = point.y + colNum[i];

            if (is_valid(visited, row, col) && mat[row][col]) {
                visited[row][col] = true;
                dist[row][col] = dist[point.x][point.y] + 1;
                parent[row][col] = point.x * n + point.y;
                queue[++rear] = (struct Point) {row, col};
            }
        }
    }
    printf("No path found\n");
}


int main() {
    int graph[ROW][COL] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };
    struct Point source = {0, 0};
    struct Point dest = {4, 4};

    BFS(graph, source, dest);

    return 0;
}