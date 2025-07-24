//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

int graph[ROWS][COLS] = { { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                          { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                          { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                          { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int path[ROWS], top = -1;

void push(int node) {
    path[++top] = node;
}

int pop() {
    if (top == -1) {
        return -1;
    } else {
        return path[top--];
    }
}

void dfs(int start, int end) {
    int visited[ROWS] = {0};
    push(start);
    visited[start] = 1;
    printf("DFS: ");
    while (top != -1) {
        int current = pop();
        printf("%d ", current);
        if (current == end) {
            printf("\n");
            return;
        }
        for (int i = 0; i < COLS; i++) {
            if (graph[current][i] && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("No path found\n");
}

void bfs(int start, int end) {
    int visited[ROWS] = {0};
    int queue[ROWS], head = 0, tail = 0;
    queue[tail++] = start;
    visited[start] = 1;
    printf("BFS: ");
    while (head != tail) {
        int current = queue[head++];
        printf("%d ", current);
        if (current == end) {
            printf("\n");
            return;
        }
        for (int i = 0; i < COLS; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[tail++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("No path found\n");
}

int main() {
    int start = 0;
    int end = 9;
    dfs(start, end);
    bfs(start, end);
    return 0;
}