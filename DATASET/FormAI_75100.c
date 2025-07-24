//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX_VERTEX 10

int dijkstra(int graph[MAX_VERTEX][MAX_VERTEX], int start, int end);

int main() {
    int graph[MAX_VERTEX][MAX_VERTEX], i, j, start, end, distance;

    // Initialize graph with random values
    for (i = 0; i < MAX_VERTEX; i++) {
        for (j = 0; j < MAX_VERTEX; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = rand() % 10;
            }
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("Enter ending vertex: ");
    scanf("%d", &end);

    distance = dijkstra(graph, start, end);

    printf("\nShortest distance between vertices %d and %d is %d\n", start, end, distance);

    return 0;
}

int dijkstra(int graph[MAX_VERTEX][MAX_VERTEX], int start, int end) {
    int dist[MAX_VERTEX], visited[MAX_VERTEX] = {0}, i, j, min, next;

    for (i = 0; i < MAX_VERTEX; i++) {
        dist[i] = graph[start][i];
    }

    visited[start] = 1;

    for (i = 1; i < MAX_VERTEX; i++) {
        min = INFINITY;

        for (j = 0; j < MAX_VERTEX; j++) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                next = j;
            }
        }

        visited[next] = 1;

        for (j = 0; j < MAX_VERTEX; j++) {
            if (visited[j] == 0 && min + graph[next][j] < dist[j]) {
                dist[j] = min + graph[next][j];
            }
        }
    }

    return dist[end];
}