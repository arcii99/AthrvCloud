//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: irregular
#include<stdio.h> 

int graph[10][10] = { {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
                      {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                      {1, 0, 0, 0, 1, 0, 1, 0, 0, 0},
                      {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                      {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                      {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                      {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
                      {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                      {0, 0, 0, 0, 0, 0, 1, 0, 1, 0} };

int color[10];

void printColor(int v) {
  printf("\n Color for the vertices: \n");
  printf(" Vertex  Color \n");
  for (int i = 0; i < v; i++)
    printf("  %d    ->  %d\n", i, color[i]);
}

void assignColor(int vertex, int v) {
  if (vertex == v) {
    printColor(v);
    return;
  }

  for (int i = 0; i < v; i++) {
    int j;
    for (j = 0; j < vertex; j++) {
      if (graph[vertex][j] && color[j] == i)
        break;
    }
    if (j == vertex) {
      color[vertex] = i;
      assignColor(vertex+1, v);
      color[vertex] = 0;
    }
  }
}

int main() {
  int v = 10;
  for (int i = 0; i < v; i++)
    color[i] = 0;

  assignColor(0, v);
  return 0;
}