//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#define V 4

int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};

    int colors[V];
    int available[V];
    int i, j;

    for (i = 0; i < V; i++) {
        colors[i] = 0;
    }

    colors[0] = 1;

    for (i = 1; i < V; i++) {
        for (j = 0; j < V; j++) {
            available[j] = 1;
        }

        for (j = 0; j < V; j++) {
            if (graph[i][j] && colors[j]) {
                available[colors[j]] = 0;
            }
        }

        for (j = 1; j <= V; j++) {
            if (available[j]) {
                colors[i] = j;
                break;
            }
        }
    }

    printf("Colors assigned to vertices:\n");
    for (i = 0; i < V; i++) {
        printf("Vertex %d => Color %d\n", i+1, colors[i]);
    }

    return 0;
}