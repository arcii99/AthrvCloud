//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10

typedef struct node {
  int id;
  int connected[MAX_NODES];
  int weights[MAX_NODES];
  int num_neighbors;
  int distance;
  int visited;
  int parent;
} node_t;

node_t nodes[MAX_NODES];
int num_nodes;

void initialize_graph() {
  for(int i=0; i<MAX_NODES; i++) {
    nodes[i].id = i;
    nodes[i].num_neighbors = 0;
    nodes[i].distance = -1;
    nodes[i].visited = 0;
  }
  num_nodes = 0;
}

void add_edge(int node_id1, int node_id2, int weight) {
  nodes[node_id1].connected[nodes[node_id1].num_neighbors] = node_id2;
  nodes[node_id1].weights[nodes[node_id1].num_neighbors] = weight;
  nodes[node_id1].num_neighbors++;
}

int get_min_distance_node_id() {
  int min_distance = -1;
  int min_node_id = -1;
  for(int i=0; i<num_nodes; i++) {
    if(!nodes[i].visited && (min_distance == -1 || nodes[i].distance < min_distance)) {
      min_distance = nodes[i].distance;
      min_node_id = i;
    }
  }
  return min_node_id;
}

void dijkstra(int start_node_id) {
  nodes[start_node_id].distance = 0;
  nodes[start_node_id].parent = -1;
  for(int i=0; i<num_nodes-1; i++) {
    int current_node_id = get_min_distance_node_id();
    nodes[current_node_id].visited = 1;
    for(int j=0; j<nodes[current_node_id].num_neighbors; j++) {
      int neighbor_id = nodes[current_node_id].connected[j];
      int neighbor_weight = nodes[current_node_id].weights[j];
      if(!nodes[neighbor_id].visited && (nodes[neighbor_id].distance == -1 || nodes[neighbor_id].distance > nodes[current_node_id].distance + neighbor_weight)) {
        nodes[neighbor_id].distance = nodes[current_node_id].distance + neighbor_weight;
        nodes[neighbor_id].parent = current_node_id;
      }
    }
  }
}

int main() {
  // Initialize the graph
  initialize_graph();

  // Add some nodes and edges
  add_edge(0, 1, 2);
  add_edge(0, 2, 4);
  add_edge(1, 2, 1);
  add_edge(1, 3, 5);
  add_edge(2, 3, 1);
  add_edge(3, 4, 3);

  // Set the number of nodes
  num_nodes = 5;

  // Run Dijkstra's algorithm
  dijkstra(0);

  // Print out the shortest path to each node
  for(int i=0; i<num_nodes; i++) {
    printf("Shortest path to node %d: %d\n", i, nodes[i].distance);
  }

  return 0;
}