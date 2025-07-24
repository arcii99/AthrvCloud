//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 5
#define MAX 25

int graph[ROWS][COLS], visited[MAX], queue[MAX];
int front = -1, rear = -1;

void BFS(int start) {
    visited[start] = 1;
    queue[++rear] = start;

    while (front != rear) {
        int current = queue[++front];
        printf("%d -> ", current);

        for (int i = 0; i < ROWS; i++) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    // initialize graph
    int edges = 7;
    int vertices[7][2] = { {0,1}, {0,3}, {1,2}, {1,4}, {2,0}, {3,4}, {4,2} };
    for (int i = 0; i < edges; i++) {
        int row = vertices[i][0];
        int col = vertices[i][1];
        graph[row][col] = 1;
    }

    // perform BFS
    printf("BFS: ");
    BFS(0);
    printf("\n");

    return 0;
}