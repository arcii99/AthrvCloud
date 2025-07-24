//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int num_nodes;

bool is_safe(int node, int c) {
  for (int i = 0; i < num_nodes; i++) {
    if (graph[node][i] && colors[i] == c) {
      return false;
    }
  }
  return true;
}

bool graph_coloring(int node) {
  if (node == num_nodes) {
    return true;
  }

  for (int i = 1; i <= num_nodes; i++) {
    if (is_safe(node, i)) {
      colors[node] = i;
      if (graph_coloring(node+1)) {
        return true;
      }
      colors[node] = 0;
    }
  }

  return false;
}

int main() {
  // Get the number of nodes
  printf("Enter the number of nodes: ");
  scanf("%d", &num_nodes);

  // Get the adjacency matrix
  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < num_nodes; i++) {
    for (int j = 0; j < num_nodes; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  // Color the graph
  if (graph_coloring(0)) {
    printf("The graph can be colored with at most %d colors:\n", colors[num_nodes-1]);
    for (int i = 0; i < num_nodes; i++) {
      printf("%d ", colors[i]);
    }
  } else {
    printf("The graph cannot be colored\n");
  }

  return 0;
}