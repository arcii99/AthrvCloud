//FormAI DATASET v1.0 Category: Graph representation ; Style: content
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES], num_vertices, num_edges, i, j, from, to;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (i = 0; i < num_edges; i++) {
        printf("Enter the from and to vertices of edge %d: ", i + 1);
        scanf("%d %d", &from, &to);

        graph[from][to] = 1;
    }

    printf("The adjacency matrix representation of the graph is:\n");

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}