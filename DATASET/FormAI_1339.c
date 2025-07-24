//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int nodes[MAX_NODES];
int adj_matrix[MAX_NODES][MAX_NODES];
int num_nodes;

void init() {
  int i, j;
  num_nodes = 0;
  for (i = 0; i < MAX_NODES; i++) {
    nodes[i] = 0;
    for (j = 0; j < MAX_NODES; j++) {
      adj_matrix[i][j] = 0;
    }
  }
}

void add_node(int id) {
  if (num_nodes >= MAX_NODES) {
    printf("Max number of nodes reached.\n");
    return;
  }
  nodes[num_nodes++] = id;
}

void add_edge(int from, int to) {
  adj_matrix[from][to] = 1;
}

void print_topology() {
  int i, j;
  printf("Nodes:\n");
  for (i = 0; i < num_nodes; i++) {
    printf("%d ", nodes[i]);
  }
  printf("\n\nAdjacency matrix:\n");
  for (i = 0; i < num_nodes; i++) {
    printf("\t%d", nodes[i]);
  }
  printf("\n");
  for (i = 0; i < num_nodes; i++) {
    printf("%d\t", nodes[i]);
    for (j = 0; j < num_nodes; j++) {
      printf("%d\t", adj_matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  init();
  add_node(1);
  add_node(2);
  add_node(3);
  add_edge(0, 1);
  add_edge(0, 2);
  add_edge(1, 2);
  add_edge(2, 0);
  add_edge(2, 1);
  add_edge(2, 2);
  print_topology();
  return 0;
}