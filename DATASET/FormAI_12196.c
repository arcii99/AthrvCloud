//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 5

typedef struct {
    int x, y;
} point;

point stack[ROW * COL];
int top = -1;

void push(point p) {
    if (top < ROW * COL) {
        stack[++top] = p;
    }
}

point pop() {
    if (top != -1) {
        return stack[top--];
    }
}

int isEmpty() {
    return top == -1;
}

int isWall(int maze[][COL], point p) {
    return (maze[p.x][p.y] == 1);
}

int isVisited(int visited[][COL], point p) {
    return (visited[p.x][p.y] == 1);
}

int isSafe(int maze[][COL], int visited[][COL], point p) {
    return (!isWall(maze, p) && !isVisited(visited, p));
}

point getNeighbors(point p) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        point np = {p.x + dx[i], p.y + dy[i]};
        if (np.x >= 0 && np.x < ROW && np.y >= 0 && np.y < COL) {
            push(np);
        }
    }
}

point findPath(int maze[][COL], int sx, int sy, int ex, int ey) {
    // initialize the visited array
    int visited[ROW][COL] = {0};

    // push the starting position onto the stack
    point start = {sx, sy};
    push(start);

    while (!isEmpty()) {
        point p = pop();
        if (!isVisited(visited, p)) {
            visited[p.x][p.y] = 1;
            if (p.x == ex && p.y == ey) {
                return p; // return the end point
            }
            if (isSafe(maze, visited, p)) {
                getNeighbors(p);
            }
        }
    }
}

int main() {
    int maze[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    point start = {0, 0};
    point end = findPath(maze, start.x, start.y, ROW - 1, COL - 1);

    if (end.x == ROW - 1 && end.y == COL - 1) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}