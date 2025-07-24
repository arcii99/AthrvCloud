//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_EDGES 20

typedef struct Node {
   int node_id;
   int visited;
}Node;

typedef struct Edge {
   Node* from_node;
   Node* to_node;
   int cost;
}Edge;

typedef struct Graph {
   Node* nodes[MAX_NODES];
   Edge* edges[MAX_EDGES];
   int num_nodes;
   int num_edges;
}Graph;

void add_node(Graph* graph, Node* node);
void add_edge(Graph* graph, Edge* edge);
void print_graph(Graph* graph);
void map_topology(Graph* graph);

int main(){
   Graph graph;
   graph.num_nodes = 0;
   graph.num_edges = 0;

   Node nodeA = { 1, 0 };
   Node nodeB = { 2, 0 };
   Node nodeC = { 3, 0 };
   Node nodeD = { 4, 0 };
   Node nodeE = { 5, 0 };

   Edge edgeAB = { &nodeA, &nodeB, 10 };
   Edge edgeAC = { &nodeA, &nodeC, 20 };
   Edge edgeBC = { &nodeB, &nodeC, 30 };
   Edge edgeBD = { &nodeB, &nodeD, 25 };
   Edge edgeDE = { &nodeD, &nodeE, 15 };

   add_node(&graph, &nodeA);
   add_node(&graph, &nodeB);
   add_node(&graph, &nodeC);
   add_node(&graph, &nodeD);
   add_node(&graph, &nodeE);

   add_edge(&graph, &edgeAB);
   add_edge(&graph, &edgeAC);
   add_edge(&graph, &edgeBC);
   add_edge(&graph, &edgeBD);
   add_edge(&graph, &edgeDE);

   printf("Initial topology:\n");
   print_graph(&graph);

   // Map topology using Breadth First Search
   map_topology(&graph);

   printf("Mapped topology:\n");
   print_graph(&graph);

   return 0;
}

// Add node to graph
void add_node(Graph* graph, Node* node){
   if(graph->num_nodes < MAX_NODES){
      graph->nodes[graph->num_nodes++] = node;
   }
}

// Add edge to graph
void add_edge(Graph* graph, Edge* edge){
   if(graph->num_edges < MAX_EDGES){
      graph->edges[graph->num_edges++] = edge;
   }
}

// Print Graph
void print_graph(Graph* graph){
   for(int i=0; i < graph->num_nodes; i++){
      printf("Node %d\n", graph->nodes[i]->node_id);
      for(int j=0; j < graph->num_edges; j++){
         if(graph->edges[j]->from_node == graph->nodes[i]){
            printf("\t Edge to Node %d with cost %d\n",
                   graph->edges[j]->to_node->node_id, graph->edges[j]->cost);
         }
      }
   }
}

// Map topology using Breadth First Search
void map_topology(Graph* graph){
   Node* start_node = graph->nodes[0];
   start_node->visited = 1;

   for(int i=0; i < graph->num_edges; i++){
      if(graph->edges[i]->from_node == start_node){
         graph->edges[i]->to_node->visited = 1;
      }
   }

   for(int i=1; i < graph->num_nodes; i++){
      Node* current_node = graph->nodes[i];

      if(current_node->visited == 0){
         printf("New topology added with starting node %d\n", current_node->node_id);
         current_node->visited = 1;

         for(int j=0; j < graph->num_edges; j++){
            if(graph->edges[j]->from_node == current_node && graph->edges[j]->to_node->visited == 0){
               printf("\t New edge from node %d with cost %d to node %d\n", 
                      current_node->node_id, graph->edges[j]->cost, graph->edges[j]->to_node->node_id);
               graph->edges[j]->to_node->visited = 1;
            }
         }
      }
   }
}