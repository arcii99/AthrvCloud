//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>

int main() {
  printf("Welcome to my peace pathfinding algorithm!\n");

  // initialize array for each node's distance
  int distances[6] = {0, 999, 999, 999, 999, 999};
  // set starting node distance to 0
  distances[0] = 0;

  // initialize adjacency matrix
  int graph[6][6] = {
    {0, 4, 0, 0, 2, 0},
    {0, 0, 2, 0, 0, 0},
    {0, 0, 0, 4, 0, 1},
    {0, 0, 0, 0, 0, 3},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
  };

  // initialize visited array
  int visited[6] = {0};

  // loop through each node
  for (int i = 0; i < 6; i++) {
    // find node with smallest distance that hasn't been visited
    int min_distance = 999;
    int current_node;
    for (int j = 0; j < 6; j++) {
      if (visited[j] == 0 && distances[j] < min_distance) {
        min_distance = distances[j];
        current_node = j;
      }
    }

    // mark current node as visited
    visited[current_node] = 1;

    // update distances array for all adjacent nodes
    for (int k = 0; k < 6; k++) {
      if (graph[current_node][k] != 0) {
        int new_distance = distances[current_node] + graph[current_node][k];
        if (new_distance < distances[k]) {
          distances[k] = new_distance;
        }
      }
    }
  }

  // print out shortest distances from starting node to each node
  printf("Shortest distances from starting node to each node:\n");
  for (int l = 0; l < 6; l++) {
    printf("Node %d: %d\n", l, distances[l]);
  }

  return 0;
}