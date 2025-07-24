//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: immersive
#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES]; // adjacency matrix representation of graph
int colors[MAX_VERTICES]; // array to store color assigned to each vertex
int num_vertices; // number of vertices in graph

bool is_safe(int vertex, int color) {
  for (int i = 0; i < num_vertices; i++) {
    if (graph[vertex][i] && color == colors[i]) {
      return false;
    }
  }
  return true;
}

bool graph_coloring(int vertex) {
  if (vertex == num_vertices) { // all vertices have been colored
    return true;
  }

  for (int color = 1; color <= num_vertices; color++) {
    if (is_safe(vertex, color)) {
      colors[vertex] = color; // assign color to vertex
      if (graph_coloring(vertex + 1)) { // recursively color next vertex
        return true;
      }
      colors[vertex] = 0; // backtrack
    }
  }

  return false; // no solution found
}

int main() {
  printf("Enter number of vertices: ");
  scanf("%d", &num_vertices);

  printf("Enter adjacency matrix of graph:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  if (graph_coloring(0)) {
    printf("Graph can be colored using %d colors as follows:\n", num_vertices);
    for (int i = 0; i < num_vertices; i++) {
      printf("Vertex %d: Color %d\n", i, colors[i]);
    }
  } else {
    printf("Graph cannot be colored using %d colors.\n", num_vertices);
  }

  return 0;
}