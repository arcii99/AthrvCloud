//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int maze[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[N][N];

typedef struct point {
    int x;
    int y;
} point;

point queue[N*N];
int front = 0, rear = 0;

void enqueue(point p) {
    queue[rear++] = p;
}

point dequeue() {
    return queue[front++];
}

int is_empty() {
    return rear == front;
}

void print_path(point p) {
    if (maze[p.x][p.y] == 1) {
        printf("(%d,%d) ", p.x, p.y);
        return;
    }
    print_path((point){p.x-1, p.y});
    print_path((point){p.x, p.y-1});
    print_path((point){p.x+1, p.y});
    print_path((point){p.x, p.y+1});
}

void maze_route() {
    point start = {1, 1};
    point end = {8, 8};
    enqueue(start);
    visited[start.x][start.y] = 1;
    int found = 0;
    while (!is_empty()) {
        point p = dequeue();
        if (p.x == end.x && p.y == end.y) {
            found = 1;
            break;
        }
        if (maze[p.x-1][p.y] != 1 && !visited[p.x-1][p.y]) {
            enqueue((point){p.x-1, p.y});
            visited[p.x-1][p.y] = 1;
        }
        if (maze[p.x][p.y-1] != 1 && !visited[p.x][p.y-1]) {
            enqueue((point){p.x, p.y-1});
            visited[p.x][p.y-1] = 1;
        }
        if (maze[p.x+1][p.y] != 1 && !visited[p.x+1][p.y]) {
            enqueue((point){p.x+1, p.y});
            visited[p.x+1][p.y] = 1;
        }
        if (maze[p.x][p.y+1] != 1 && !visited[p.x][p.y+1]) {
            enqueue((point){p.x, p.y+1});
            visited[p.x][p.y+1] = 1;
        }
    }
    if (found) {
        printf("Path found: ");
        print_path(end);
        printf("\n");
    }
    else {
        printf("No path found\n");
    }
}

int main() {
    memset(visited, 0, sizeof(visited));
    maze_route();
    return 0;
}