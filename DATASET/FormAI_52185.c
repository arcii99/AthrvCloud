//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 5

int adj_matrix[MAX_VERTEX][MAX_VERTEX];

struct Graph{
  int vertex_count;
};

// function to add edges into the adjacency matrix
void addEdge(struct Graph* graph, int src, int dest){
  adj_matrix[src][dest] = 1;
  adj_matrix[dest][src] = 1;
}

// function to print the adjacency matrix
void printAdjMatrix(struct Graph* graph){
  printf("Adjacency Matrix:\n");
  for(int i=0;i<graph->vertex_count;i++){
    for(int j=0;j<graph->vertex_count;j++){
      printf(" %d ",adj_matrix[i][j]);
    }
    printf("\n");
  }
}

int main(){

  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->vertex_count = MAX_VERTEX;

  // adding edges into the graph
  addEdge(graph,0,1);
  addEdge(graph,0,4);
  addEdge(graph,1,2);
  addEdge(graph,1,3);
  addEdge(graph,1,4);
  addEdge(graph,2,3);
  addEdge(graph,3,4);

  // printing the adjacency matrix
  printAdjMatrix(graph);

  return 0;
}