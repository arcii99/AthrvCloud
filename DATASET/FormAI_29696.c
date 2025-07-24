//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct edge {
  int node1, node2, weight;
} edge_t;

typedef struct graph {
  int num_nodes;
  int num_edges;
  char node_names[MAX_NODES][20];
  edge_t edges[MAX_EDGES];
} graph_t;

// function prototypes
bool is_valid_name(char name[]);
int get_node_index(graph_t* graph, char name[]);
void add_node(graph_t* graph, char name[]);
void add_edge(graph_t* graph, char node1[], char node2[], int weight);
void print_graph(graph_t* graph);

int main() {
  graph_t graph = {0, 0};
  char input[200];
  char node1[20], node2[20];
  int weight;

  while(true) {
    printf("Enter an edge (format: node1 node2 weight): ");
    fgets(input, 200, stdin);
    if (strlen(input) <= 1)
      break;
    sscanf(input, "%s %s %d", node1, node2, &weight);
    if (!is_valid_name(node1) || !is_valid_name(node2)) {
      printf("Invalid node name. Please use only letters, numbers, or underscores.\n");
      continue;
    }
    if (weight <= 0 || weight > 1000) {
      printf("Invalid edge weight. Please use a number between 1 and 1000.\n");
      continue;
    }
    add_edge(&graph, node1, node2, weight);
    print_graph(&graph);
  }

  return 0;
}

bool is_valid_name(char name[]) {
  for (int i = 0; i < strlen(name); i++) {
    if (!isalnum(name[i]) && name[i] != '_')
      return false;
  }
  return true;
}

int get_node_index(graph_t* graph, char name[]) {
  for (int i = 0; i < graph->num_nodes; i++) {
    if (strcmp(graph->node_names[i], name) == 0)
      return i;
  }
  return -1;
}

void add_node(graph_t* graph, char name[]) {
  if (get_node_index(graph, name) == -1) {
    strcpy(graph->node_names[graph->num_nodes], name);
    graph->num_nodes++;
  }
}

void add_edge(graph_t* graph, char node1[], char node2[], int weight) {
  int node_index1 = get_node_index(graph, node1);
  int node_index2 = get_node_index(graph, node2);
  if (node_index1 == -1) {
    add_node(graph, node1);
    node_index1 = graph->num_nodes - 1;
  }
  if (node_index2 == -1) {
    add_node(graph, node2);
    node_index2 = graph->num_nodes - 1;
  }
  graph->edges[graph->num_edges].node1 = node_index1;
  graph->edges[graph->num_edges].node2 = node_index2;
  graph->edges[graph->num_edges].weight = weight;
  graph->num_edges++;
}

void print_graph(graph_t* graph) {
  printf("Graph with %d nodes and %d edges:\n", graph->num_nodes, graph->num_edges);
  printf("Nodes:\n");
  for (int i = 0; i < graph->num_nodes; i++) {
    printf("%d: %s\n", i, graph->node_names[i]);
  }
  printf("Edges:\n");
  for (int i = 0; i < graph->num_edges; i++) {
    printf("%d-%d (%d)\n", graph->edges[i].node1, graph->edges[i].node2, graph->edges[i].weight);
  }
}