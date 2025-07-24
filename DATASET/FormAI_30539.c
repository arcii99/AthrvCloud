//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define ROW 10 
#define COL 10 
#define MAX_QUEUE_SIZE 100 

struct Point {
    int x, y;
};

bool isValid(int row, int col, int maze[][COL], bool visited[][COL], struct Point curr) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) 
        && maze[row][col] && !visited[row][col];
}

void printPath(struct Point path[MAX_QUEUE_SIZE], int pathLength) {
    printf("Path found: ");
    for (int i = 0; i < pathLength; i++) {
        printf("(%d,%d) -> ", path[i].x, path[i].y);
    }
    printf("END\n");
}

int BFS(int maze[][COL], struct Point start, struct Point dest, struct Point path[MAX_QUEUE_SIZE]) {
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);

    int rowMoves[] = {-1, 0, 0, 1};
    int colMoves[] = {0, -1, 1, 0};

    struct Queue {
        struct Point pt;
        int dist;
    } queue[MAX_QUEUE_SIZE];

    int front = 0, rear = 0;
    queue[rear++] = (struct Queue) {start, 0};
    visited[start.x][start.y] = true;

    while (front < rear) {
        struct Queue curr = queue[front++];

        if (curr.pt.x == dest.x && curr.pt.y == dest.y) {
            path[curr.dist] = curr.pt;
            printPath(path, curr.dist + 1);
            return curr.dist;
        }

        for (int i = 0; i < 4; i++) {
            int row = curr.pt.x + rowMoves[i];
            int col = curr.pt.y + colMoves[i];
            
            if (isValid(row, col, maze, visited, curr.pt)) {
                visited[row][col] = true;
                queue[rear++] = (struct Queue) {{row, col}, curr.dist + 1};
                path[curr.dist] = curr.pt;
            }
        }
    }

    printf("No path found!\n");
    return -1;
}

int main() {
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    struct Point start = {2, 0};
    struct Point dest = {8, 9};
    struct Point path[MAX_QUEUE_SIZE];

    int dist = BFS(maze, start, dest, path);
    if (dist != -1) {
        printf("Shortest path length: %d\n", dist);
    }

    return 0;
}