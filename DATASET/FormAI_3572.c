//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50
#define MAX_EDGES 100

typedef struct Node {
   char name[20];
   int neighbors[MAX_NODES];
} Node;

typedef struct Edge {
   int src;
   int dest;
   int weight;
} Edge;

typedef struct Graph {
   Node nodes[MAX_NODES];
   Edge edges[MAX_EDGES];
   int numNodes;
   int numEdges;
} Graph;

void addNode(Graph* graph, char* name) {
   Node node;
   strcpy(node.name, name);
   node.neighbors[0] = -1;
   graph->nodes[graph->numNodes] = node;
   graph->numNodes++;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
   Edge edge;
   edge.src = src;
   edge.dest = dest;
   edge.weight = weight;
   graph->edges[graph->numEdges] = edge;
   graph->nodes[src].neighbors[graph->numEdges] = dest;
   graph->numEdges++;
}

void printGraph(Graph* graph) {
   printf("Node\tNeighbors\n");
   for (int i = 0; i < graph->numNodes; i++) {
      printf("%s\t", graph->nodes[i].name);
      int j = 0;
      while (graph->nodes[i].neighbors[j] != -1) {
         printf("%s ", graph->nodes[graph->nodes[i].neighbors[j]].name);
         j++;
      }
      printf("\n");
   }
}

int main() {
   Graph graph;
   graph.numNodes = 0;
   graph.numEdges = 0;

   addNode(&graph, "Router 1");
   addNode(&graph, "Router 2");
   addNode(&graph, "Router 3");
   addNode(&graph, "Server 1");
   addNode(&graph, "Server 2");

   addEdge(&graph, 0, 1, 2);
   addEdge(&graph, 0, 2, 3);
   addEdge(&graph, 1, 2, 1);
   addEdge(&graph, 1, 3, 4);
   addEdge(&graph, 2, 3, 2);
   addEdge(&graph, 3, 4, 3);

   printGraph(&graph);

   return 0;
}