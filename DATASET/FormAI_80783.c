//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>

int main() {
  printf("Let's create a C graph representation!\n");

  // Create a 2D array to store our graph
  int graph[6][6] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 1, 1, 0, 0},
    {1, 1, 0, 1, 1, 1},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 1, 1, 0, 1},
    {0, 0, 1, 0, 1, 0}
  };

  // Print out the matrix
  printf("Here's the graph matrix:\n");
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  // Let's create some vertices
  struct Vertex {
    char label;
    int visited;
  };

  // Set up our vertices and add them to an array
  struct Vertex vertices[6];
  vertices[0].label = 'A';
  vertices[0].visited = 0;

  vertices[1].label = 'B';
  vertices[1].visited = 0;

  vertices[2].label = 'C';
  vertices[2].visited = 0;

  vertices[3].label = 'D';
  vertices[3].visited = 0;

  vertices[4].label = 'E';
  vertices[4].visited = 0;

  vertices[5].label = 'F';
  vertices[5].visited = 0;

  // Let's create some edges
  int numEdges = 0;
  struct Edge {
    int start_vertex;
    int end_vertex;
  };

  struct Edge edges[15];
  for (int i = 0; i < 6; i++) {
    for (int j = i+1; j < 6; j++) {
      if (graph[i][j] == 1) {
        edges[numEdges].start_vertex = i;
        edges[numEdges].end_vertex = j;
        numEdges++;
      }
    }
  }

  // Print out the edges
  printf("Here are the edges in the graph:\n");
  for (int i = 0; i < numEdges; i++) {
    printf("(%c, %c)\n", vertices[edges[i].start_vertex].label, vertices[edges[i].end_vertex].label);
  }

  printf("Graph created successfully!\n");
  return 0;
}