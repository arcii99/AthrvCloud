//FormAI DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10

void createGraph(int[][MAX_VERTICES], int);
void addEdge(int[][MAX_VERTICES], int, int, int);
void printGraph(int[][MAX_VERTICES], int);

int main() {
  int vertices, adjMatrix[MAX_VERTICES][MAX_VERTICES];  
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);
  createGraph(adjMatrix, vertices);
  addEdge(adjMatrix, 1, 2, 1);
  addEdge(adjMatrix, 1, 3, 1);
  addEdge(adjMatrix, 2, 3, 1);
  addEdge(adjMatrix, 3, 4, 1);
  addEdge(adjMatrix, 4, 2, 1);
  printGraph(adjMatrix, vertices);
  return 0;
}

// This function is used to create a graph with the given number of vertices
void createGraph(int adjMatrix[][MAX_VERTICES], int vertices) {
  int i, j;
  for(i=1; i<=vertices; i++) {
    for(j=1; j<=vertices; j++) {
      adjMatrix[i][j] = 0;
    }
  }
}

// This function adds an edge between two vertices with the given weight
void addEdge(int adjMatrix[][MAX_VERTICES], int start, int end, int weight) {
  adjMatrix[start][end] = weight;
}

// This function prints the graph in matrix form
void printGraph(int adjMatrix[][MAX_VERTICES], int vertices) {
  int i, j;
  printf("\nThe adjacency matrix representation of the graph is:\n");
  for(i=1; i<=vertices; i++) {
    for(j=1; j<=vertices; j++) {
      printf("%d ", adjMatrix[i][j]);
    }
    printf("\n");
  }
}