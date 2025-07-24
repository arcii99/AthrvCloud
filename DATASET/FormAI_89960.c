//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0}
};

typedef struct point {
    int x, y;
} point;

point queue[ROW * COL];
int front = -1, rear = -1;

bool is_empty() {
    return front == -1 && rear == -1;
}

bool is_full() {
    return rear == ROW * COL - 1;
}

void push(point p) {
    if (is_full()) {
        printf("Queue is full!\n");
        return;
    }
    if (is_empty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = p;
}

point pop() {
    point p = {-1, -1};
    if (is_empty()) {
        printf("Queue is empty!\n");
        return p;
    }
    p = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return p;
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 0);
}

void print_path(int path[][COL], point dest) {
    if (path[dest.x][dest.y] == -1) {
        printf("No path found!\n");
        return;
    }
    point p = dest;
    while (path[p.x][p.y] != 0) {
        printf("(%d,%d) -> ", p.x, p.y);
        int tmp_x = p.x - 1, tmp_y = p.y;
        if (is_valid(tmp_x, tmp_y) && path[tmp_x][tmp_y] == path[p.x][p.y] - 1) {
            p.x = tmp_x;
        } else {
            tmp_x = p.x + 1, tmp_y = p.y;
            if (is_valid(tmp_x, tmp_y) && path[tmp_x][tmp_y] == path[p.x][p.y] - 1) {
                p.x = tmp_x;
            } else {
                tmp_x = p.x, tmp_y = p.y - 1;
                if (is_valid(tmp_x, tmp_y) && path[tmp_x][tmp_y] == path[p.x][p.y] - 1) {
                    p.y = tmp_y;
                } else {
                    tmp_x = p.x, tmp_y = p.y + 1;
                    if (is_valid(tmp_x, tmp_y) && path[tmp_x][tmp_y] == path[p.x][p.y] - 1) {
                        p.y = tmp_y;
                    }
                }
            }
        }
    }
    printf("(%d,%d)\n", p.x, p.y);
}

void shortest_path(point src, point dest) {
    int path[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1;
        }
    }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    path[src.x][src.y] = 0;
    push(src);
    while (!is_empty()) {
        point p = pop();
        if (p.x == dest.x && p.y == dest.y) {
            print_path(path, dest);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int x = p.x + dx[i], y = p.y + dy[i];
            if (is_valid(x, y)) {
                path[x][y] = path[p.x][p.y] + 1;
                push((point){x, y});
            }
        } 
    }
}

int main() {
    point src = {0, 0};
    point dest = {4, 4};
    shortest_path(src, dest);
    return 0;
}