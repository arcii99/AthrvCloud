//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int graph[ROWS][COLS] = {
        {0,1,0,0,0,0,0,0,0,0},
        {1,0,1,0,0,1,0,0,0,0},
        {0,1,0,1,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0},
        {0,0,0,1,0,1,0,0,0,0},
        {0,1,0,0,1,0,1,0,0,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0,0,1,0}
};

int visited[COLS] = {0};

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    for(int i=0; i<ROWS; i++) {
        if(graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int node) {
    int queue[ROWS];
    int front = 0, back = 0;

    visited[node] = 1;
    queue[back++] = node;

    while (front != back) {
        node = queue[front++];
        printf("%d ", node);
        for(int i=0; i<ROWS; i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[back++] = i;
            }
        }
    }
}

int main() {
    printf("Depth First Search: ");
    dfs(0);

    printf("\nBreadth First Search: ");
    for(int i=0; i<COLS; i++) {
        visited[i] = 0;
    }
    bfs(0);
    
    return 0;
}