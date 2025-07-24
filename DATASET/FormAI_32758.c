//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#define MAX_NODES 10
#define MAX_COLORS 4

int adjacency_matrix[MAX_NODES][MAX_NODES];
int node_colors[MAX_NODES];
int num_nodes;

void color_node(int node_id);

int main() {
  // Initiaize the adjacency matrix
  for(int i = 0; i < MAX_NODES; i++) {
    for(int j = 0; j < MAX_NODES; j++) {
      adjacency_matrix[i][j] = 0;
    }
    node_colors[i] = -1; // Set all node colors to -1 (unassigned)
  }

  // Add edges to the graph
  adjacency_matrix[0][1] = 1;
  adjacency_matrix[1][2] = 1;
  adjacency_matrix[2][0] = 1;
  adjacency_matrix[2][3] = 1;
  adjacency_matrix[3][4] = 1;
  adjacency_matrix[4][5] = 1;
  adjacency_matrix[5][3] = 1;
  adjacency_matrix[6][7] = 1;
  adjacency_matrix[7][8] = 1;
  adjacency_matrix[8][6] = 1;

  num_nodes = 9; // Set number of nodes in the graph

  // Color each node
  for(int i = 0; i < num_nodes; i++) {
    color_node(i);
  }

  // Print the color of each node
  printf("Node colors:\n");
  for(int i = 0; i < num_nodes; i++) {
    printf("Node %d: %d\n", i, node_colors[i]);
  }

  return 0;
}

void color_node(int node_id) {
  // Check if the node has already been assigned a color
  if(node_colors[node_id] != -1) {
    return;
  }

  int color_assigned = 0;

  // Try to assign each color to the node
  for(int i = 0; i < MAX_COLORS; i++) {
    int color_conflict = 0;

    // Check if any neighbor already has the color
    for(int j = 0; j < num_nodes; j++) {
      if(adjacency_matrix[node_id][j] == 1 && node_colors[j] == i) {
        color_conflict = 1;
        break;
      }
    }

    // If there is no conflict, assign the color
    if(!color_conflict) {
      node_colors[node_id] = i;
      color_assigned = 1;
      break;
    }
  }

  // If no color was assigned, panic and exit
  if(!color_assigned) {
    printf("Error: Unable to assign color to node %d\n", node_id);
    exit(1);
  }

  // Recursively color the neighbors of this node
  for(int i = 0; i < num_nodes; i++) {
    if(adjacency_matrix[node_id][i] == 1) {
      color_node(i);
    }
  }
}