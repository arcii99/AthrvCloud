//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES];
int colors[MAX_NODES];
int num_nodes;

bool is_valid_color(int node, int color) {
  for (int i = 0; i < num_nodes; i++) {
    if (graph[node][i] && colors[i] == color) {
      return false;
    }
  }
  return true;
}

bool color_nodes(int node) {
  if (node == num_nodes) {
    // All nodes have been colored, problem solved!
    return true;
  }

  for (int i = 1; i <= MAX_COLORS; i++) {
    if (is_valid_color(node, i)) {
      colors[node] = i;
      if (color_nodes(node + 1)) {
        // This color works, return true
        return true;
      }
      colors[node] = 0;
    }
  }

  // No valid colors found
  return false;
}

int main() {
  // Set up the graph
  num_nodes = 5;
  graph[0][1] = 1;
  graph[1][0] = 1;
  graph[1][2] = 1;
  graph[2][1] = 1;
  graph[2][3] = 1;
  graph[3][2] = 1;
  graph[3][4] = 1;
  graph[4][3] = 1;
  graph[4][0] = 1;
  graph[0][4] = 1;

  // Color the nodes
  if (color_nodes(0)) {
    printf("Colors:");
    for (int i = 0; i < num_nodes; i++) {
      printf(" %d", colors[i]);
    }
  } else {
    printf("No valid colorings found.");
  }

  return 0;
}