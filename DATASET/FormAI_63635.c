//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999

//Structure to hold the edge information
typedef struct Edge {
  int from;
  int to;
  int weight;
} Edge;

//Structure to hold the graph information
typedef struct Graph {
  int num_vertices;
  int num_edges;
  Edge edges[MAX_VERTICES];
} Graph;

//Greedy algorithm to find the minimum spanning tree for a given graph
void kruskal(Graph *graph) {
  int parent[MAX_VERTICES];
  int rank[MAX_VERTICES];

  for (int i = 0; i < graph->num_vertices; i++) {
    parent[i] = i;
    rank[i] = 0;
  }

  //Sort edges based on their weight
  for (int i = 0; i < graph->num_edges-1; i++) {
    for (int j = i+1; j < graph->num_edges; j++) {
      if (graph->edges[i].weight > graph->edges[j].weight) {
        Edge temp = graph->edges[i];
        graph->edges[i] = graph->edges[j];
        graph->edges[j] = temp;
      }
    }
  }

  Graph min_spanning_tree;
  min_spanning_tree.num_vertices = graph->num_vertices;
  min_spanning_tree.num_edges = 0;

  int i = 0;
  while (min_spanning_tree.num_edges < min_spanning_tree.num_vertices-1) {
    Edge edge = graph->edges[i];
    int parent_from = parent[edge.from];
    int parent_to = parent[edge.to];

    //If the vertices do not have the same root node, add the edge to the minimum spanning tree
    if (parent_from != parent_to) {
      min_spanning_tree.edges[min_spanning_tree.num_edges] = edge;
      min_spanning_tree.num_edges++;

      //Merge the two trees by making the parent of the root node of one equal to the root node of the other
      if (rank[parent_from] < rank[parent_to]) {
        parent[parent_from] = parent_to;
      } else {
        parent[parent_to] = parent_from;

        //If the ranks are the same, increment the rank of the new root node
        if (rank[parent_from] == rank[parent_to]) {
          rank[parent_from]++;
        }
      }
    }

    i++;
  }

  printf("Edges in the minimum spanning tree\n");
  for (int i = 0; i < min_spanning_tree.num_edges; i++) {
    printf("(%d, %d) with weight %d\n", min_spanning_tree.edges[i].from, min_spanning_tree.edges[i].to, min_spanning_tree.edges[i].weight);
  }
}

int main() {
  Graph graph;
  graph.num_vertices = 6;
  graph.num_edges = 9;
  graph.edges[0].from = 0;
  graph.edges[0].to = 1;
  graph.edges[0].weight = 3;
  graph.edges[1].from = 0;
  graph.edges[1].to = 2;
  graph.edges[1].weight = 1;
  graph.edges[2].from = 0;
  graph.edges[2].to = 3;
  graph.edges[2].weight = 4;
  graph.edges[3].from = 1;
  graph.edges[3].to = 2;
  graph.edges[3].weight = 5;
  graph.edges[4].from = 1;
  graph.edges[4].to = 4;
  graph.edges[4].weight = 2;
  graph.edges[5].from = 2;
  graph.edges[5].to = 3;
  graph.edges[5].weight = 6;
  graph.edges[6].from = 2;
  graph.edges[6].to = 4;
  graph.edges[6].weight = 7;
  graph.edges[7].from = 3;
  graph.edges[7].to = 4;
  graph.edges[7].weight = 8;
  graph.edges[8].from = 4;
  graph.edges[8].to = 5;
  graph.edges[8].weight = 9;

  kruskal(&graph);

  return 0;
}