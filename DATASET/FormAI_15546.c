//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} Node;

// Define the graph structure
typedef struct graph {
  int num_vertices;
  Node **adj_list;
} Graph;

// Function to create a new node in the graph
Node *newNode(int data) {
  Node *new_node = (Node*) malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to create a new graph with a given number of vertices
Graph *createGraph(int num_vertices) {
  Graph *graph = (Graph*) malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->adj_list = (Node**) malloc(num_vertices * sizeof(Node*));
  int i;
  for (i = 0; i < num_vertices; i++) {
    graph->adj_list[i] = NULL;
  }
  return graph;
}

// Function to add an edge between two vertices in the graph
void addEdge(Graph *graph, int src, int dest) {
  // Add edge from source to destination
  Node *new_node = newNode(dest);
  new_node->next = graph->adj_list[src];
  graph->adj_list[src] = new_node;

  // Add edge from destination to source
  new_node = newNode(src);
  new_node->next = graph->adj_list[dest];
  graph->adj_list[dest] = new_node;
}

// Function to print the graph
void printGraph(Graph *graph) {
  int i;
  for (i = 0; i < graph->num_vertices; i++) {
    Node *tmp = graph->adj_list[i];
    printf("Adjacent vertices of node %d: ", i);
    while (tmp) {
      printf("%d -> ", tmp->data);
      tmp = tmp->next;
    }
    printf("NULL\n");
  }
}

// Sample main function
int main() {
  Graph *graph = createGraph(5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  printGraph(graph);
  return 0;
}