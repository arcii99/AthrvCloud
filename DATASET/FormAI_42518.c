//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>

#define MAX_NODES 5
#define MAX_EDGES 7

int main() {
  int graph[MAX_NODES][MAX_NODES] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}
  };

  int colors[MAX_NODES] = {-1, -1, -1, -1, -1};

  int num_colors = 0;

  for (int node = 0; node < MAX_NODES; node++) {
    int available_colors[MAX_NODES] = {0};

    for (int neighbor = 0; neighbor < MAX_NODES; neighbor++) {
      if (graph[node][neighbor] && colors[neighbor] != -1) {
        available_colors[colors[neighbor]] = 1;
      }
    }

    int color = 0;
    for (color = 0; color < MAX_NODES; color++) {
      if (!available_colors[color]) {
        break;
      }
    }

    colors[node] = color;

    if (color + 1 > num_colors) {
      num_colors = color + 1;
    }
  }

  printf("The minimum number of colors required to color the graph is: %d\n", num_colors);
  printf("The colors assigned to each node are:\n");

  for (int node = 0; node < MAX_NODES; node++) {
    printf("Node %d: Color %d\n", node, colors[node]);
  }

  return 0;
}