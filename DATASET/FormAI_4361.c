//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include <stdio.h>
#define MAX_VERTICES 100

typedef struct Graph {
   int numVertices; 
   int adjMatrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

Graph createGraph(int vertices) {
   Graph graph;
   int i, j;
   graph.numVertices = vertices;
   for (i = 0; i < graph.numVertices; i++) {
      for (j = 0; j < graph.numVertices; j++) {
         graph.adjMatrix[i][j] = 0;
      }
   }
   return graph;
}

void addEdge(Graph *graph, int src, int dest) {
   graph->adjMatrix[src][dest] = 1;
   graph->adjMatrix[dest][src] = 1;
}

void printGraph(Graph *graph) {
   int i, j;
   for (i = 0; i < graph->numVertices; i++) {
      for (j = 0; j < graph->numVertices; j++) {
         printf("%d ", graph->adjMatrix[i][j]);
      }
      printf("\n");
   }
}

int main() {
   Graph graph = createGraph(5);
   addEdge(&graph, 0, 1);
   addEdge(&graph, 0, 2);
   addEdge(&graph, 0, 3);
   addEdge(&graph, 1, 2);

   printf("Graph Representation\n");
   printGraph(&graph);
   return 0;
}