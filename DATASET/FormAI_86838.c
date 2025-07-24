//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 20
#define MAX_EDGES 50
#define MAX_COLORS 5

int graph[MAX_VERTICES][MAX_VERTICES];
int vertex_colors[MAX_VERTICES];

int main()
{
    srand(time(NULL));
  
    int num_vertices = rand() % MAX_VERTICES + 1;
    int num_edges = rand() % MAX_EDGES + 1;
    int num_colors = rand() % MAX_COLORS + 1;
  
    // Initialize the graph to be all 0
    for(int i = 0; i < num_vertices; i++) {
        vertex_colors[i] = 0;
        for(int j = 0; j < num_vertices; j++) {
            graph[i][j] = 0;
        }
    }
    // Connect random vertices with random weights
    for(int i = 0; i < num_edges; i++) {
        int v1 = rand() % num_vertices;
        int v2 = rand() % num_vertices;
        if(graph[v1][v2] == 0 && v1 != v2) {
            int weight = rand() % MAX_COLORS + 1;
            graph[v1][v2] = weight;
            graph[v2][v1] = weight;
        }
        else {
            i--;
        }
    }
  
    // Color the vertices
    for(int i = 0; i < num_vertices; i++) {
        int valid_color[MAX_COLORS] = {0};
        // check colors of neighboring vertices
        for(int j = 0; j < num_vertices; j++) {
            if(graph[i][j] != 0) {
                valid_color[vertex_colors[j]] = 1;
            }
        }
        // assign first available color
        for(int j = 1; j <= num_colors; j++) {
            if(valid_color[j] == 0) {
                vertex_colors[i] = j;
                break;
            }
        }
    }
  
    // print the result
    printf("The graph:\n");
    for(int i = 0; i < num_vertices; i++) {
        for(int j = 0; j < num_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
  
    printf("\nThe vertex colors:\n");
    for(int i = 0; i < num_vertices; i++) {
        printf("%d ", vertex_colors[i]);
    }
    printf("\n");
  
    return 0;
}