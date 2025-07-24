//FormAI DATASET v1.0 Category: Graph representation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};
typedef struct node Node;

void addEdge(Node *adjList[], int u, int v) {
  Node *vPtr = (Node *) malloc(sizeof(Node));
  vPtr->data = v;
  vPtr->next = adjList[u];
  adjList[u] = vPtr;
}

void printGraph(Node *adjList[], int v) {
  printf("Adjacency list:\n");
  for(int i = 0; i < v; i++) {
    printf("Vertex %d: ", i);
    Node *temp = adjList[i];
    while(temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  int v, e;
  printf("Enter the number of vertices in graph: ");
  scanf("%d", &v);
  Node *adjList[v];
  for(int i = 0; i < v; i++) {
    adjList[i] = NULL;
  }
  printf("Enter the number of edges in graph: ");
  scanf("%d", &e);
  for(int i = 0; i < e; i++) {
    int u, v;
    printf("Enter edge %d (u, v): ", i+1);
    scanf("%d %d", &u, &v);
    addEdge(adjList, u, v);
    addEdge(adjList, v, u);
  }
  printGraph(adjList, v);
  return 0;
}