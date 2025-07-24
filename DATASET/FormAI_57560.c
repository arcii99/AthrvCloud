//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 50
#define MAX_EDGES 100

int vertices[MAX_VERTICES][MAX_VERTICES];
int num_colors = 0;
int colors[MAX_VERTICES];

int main()
{
    int num_vertices, num_edges;
    int i, j;

    srand(time(NULL));

    num_vertices = rand() % MAX_VERTICES + 1;
    num_edges = rand() % MAX_EDGES + 1;

    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            vertices[i][j] = 0;
        }
        colors[i] = -1;
    }

    for (i = 0; i < num_edges; i++) {
        int a = rand() % num_vertices;
        int b = rand() % num_vertices;
        vertices[a][b] = 1;
        vertices[b][a] = 1;
    }

    for (i = 0; i < num_vertices; i++) {
        int available_colors[num_vertices];

        for (j = 0; j < num_vertices; j++) {
            available_colors[j] = 1;
        }

        for (j = 0; j < num_vertices; j++) {
            if (vertices[i][j] == 1 && colors[j] != -1) {
                available_colors[colors[j]] = 0;
            }
        }

        for (j = 0; j < num_vertices; j++) {
            if (available_colors[j] == 1) {
                colors[i] = j;
                if (j > num_colors) {
                    num_colors = j;
                }
                break;
            }
        }
    }

    printf("Graph with %d vertices and %d edges:\n", num_vertices, num_edges);
    for (i = 0; i < num_vertices; i++) {
        printf("Vertex %d: color %d\n", i, colors[i]);
    }
    printf("Chromatic number: %d\n", num_colors + 1);

    return 0;
}