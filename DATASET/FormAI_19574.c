//FormAI DATASET v1.0 Category: Graph representation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20
#define MAX_EDGES MAX_VERTICES * (MAX_VERTICES - 1)

typedef struct {
  int x;
  int y;
} Edge;

typedef struct {
  int edges[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initialize_graph(Graph *g) {
  int i, j;
  for (i = 0; i < MAX_VERTICES; i++) {
    for (j = 0; j < MAX_VERTICES; j++) {
      g->edges[i][j] = 0;
    }
  }
}

void add_edge(Graph *g, int x, int y) {
  g->edges[x][y] = 1;
}

void remove_edge(Graph *g, int x, int y) {
  g->edges[x][y] = 0;
}

void print_graph(Graph *g) {
  int i, j;
  for (i = 0; i < MAX_VERTICES; i++) {
    for (j = 0; j < MAX_VERTICES; j++) {
      printf("%d ", g->edges[i][j]);
    }
    printf("\n");
  }
}

void generate_circle_graph(Graph *g, int n) {
  int i;
  for (i = 0; i < n; i++) {
    add_edge(g, i, (i+1)%n);
    add_edge(g, (i+1)%n, i);
  }
}

int main() {
  Graph g;
  initialize_graph(&g);
  generate_circle_graph(&g, 10);
  print_graph(&g);
  return 0;
}