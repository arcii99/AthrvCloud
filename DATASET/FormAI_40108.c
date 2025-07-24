//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int vertex;
  struct Node* next;
};

struct Graph {
  int total_vertices;
  struct Node** adj_list;
};

struct Node* createNode(int v) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->total_vertices = vertices;

  graph->adj_list = malloc(vertices * sizeof(struct Node*));

  for (int i = 0; i < vertices; i++)
    graph->adj_list[i] = NULL;

  return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
  struct Node* newNode = createNode(dest);
  newNode->next = graph->adj_list[src];
  graph->adj_list[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adj_list[dest];
  graph->adj_list[dest] = newNode;
}


void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->total_vertices; i++) {
    struct Node* temp = graph->adj_list[i];
    printf("Vertex %d: ", i);

    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }

    printf("NULL\n");
  }
}

int main() {
  struct Graph* graph = createGraph(6);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);
  addEdge(graph, 4, 5);

  printGraph(graph);

  return 0;
}