//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: synchronous
#include <stdio.h>

#define MAX_NODES 5
#define MAX_COLORS 4

int graph[MAX_NODES][MAX_NODES] = {
  {0, 1, 1, 0, 0},
  {1, 0, 1, 1, 0},
  {1, 1, 0, 1, 1},
  {0, 1, 1, 0, 1},
  {0, 0, 1, 1, 0}
};

int colors[MAX_NODES];

// Check if a color can be assigned to a node
int can_color(int node, int color) {
  for (int i = 0; i < MAX_NODES; i++) {
    if (graph[node][i] && color == colors[i]) {
      return 0;
    }
  }

  return 1;
}

// Recursive function to assign colors to nodes
void color_nodes(int node) {
  // Base case: all nodes have been colored
  if (node >= MAX_NODES) {
    // Print out the colors assigned to each node
    for (int i = 0; i < MAX_NODES; i++) {
      printf("Node %d: Color %d\n", i, colors[i]);
    }

    return;
  }

  // Try to assign each color to the node
  for (int color = 1; color <= MAX_COLORS; color++) {
    if (can_color(node, color)) {
      colors[node] = color;
      color_nodes(node + 1);
      colors[node] = 0; // Backtrack
    }
  }
}

int main() {
  color_nodes(0);
  
  return 0;
}