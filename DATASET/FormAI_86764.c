//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100   // Maximum number of vertices in the graph.

// Graph representation using Adjacency Matrix.

typedef struct GraphMatrix {
   int num_vertices;      // Number of vertices in the graph Matrix.
   int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} GraphMatrix;

// Helper function to create a new GraphMatrix.

GraphMatrix* createGraphMatrix(int num_vertices) {
   GraphMatrix* graph = (GraphMatrix*)malloc(sizeof(GraphMatrix));
   graph->num_vertices = num_vertices;

   // Initialize adjacency matrix to 0
   int i, j;
   for(i = 0; i < num_vertices; i++) {
      for(j = 0; j < num_vertices; j++) {
         graph->adj_matrix[i][j] = 0;
      }
   }

   return graph;
}

// Helper function to add an edge between two vertices.

void addEdge(GraphMatrix* graph, int start_vertex, int end_vertex) {
   graph->adj_matrix[start_vertex][end_vertex] = 1;
   graph->adj_matrix[end_vertex][start_vertex] = 1;
}

// Helper function to print the Graph Matrix.

void printGraphMatrix(GraphMatrix* graph) {
   int i, j;
   for(i = 0; i < graph->num_vertices; i++) {
      for(j = 0; j < graph->num_vertices; j++) {
         printf("%d", graph->adj_matrix[i][j]);
      }
      printf("\n");
   }
}

// Main function

int main() {
   GraphMatrix* graph = createGraphMatrix(5);

   addEdge(graph, 0, 1);
   addEdge(graph, 0, 4);
   addEdge(graph, 1, 2);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 4);
   addEdge(graph, 2, 3);
   addEdge(graph, 3, 4);

   printGraphMatrix(graph);

   free(graph);

   return 0;
}