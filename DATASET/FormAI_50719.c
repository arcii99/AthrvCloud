//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>

int main() {
  // Wow! I can't believe I'm going to create a C Graph representation example program!
  printf("Welcome to the amazing C Graph representation program!\n\n");
  printf("Enter the number of vertices in the graph: ");
  int num_vertices;
  scanf("%d", &num_vertices);
  
  // Let's create an adjacency matrix for our graph
  int graph[num_vertices][num_vertices];

  // Initialize all values in the adjacency matrix to 0
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      graph[i][j] = 0;
    }
  }

  // Let's add some edges to our graph
  printf("\nEnter the number of edges in the graph: ");
  int num_edges;
  scanf("%d", &num_edges);

  printf("\nEnter the vertices (from and to) for each edge in the format 'from to':\n");
  for (int i = 0; i < num_edges; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    graph[from][to] = 1;
    graph[to][from] = 1; // Assuming that the graph is undirected for now
  }

  // Let's print out the adjacency matrix to show the graph and its edges
  printf("\nHere is the adjacency matrix for the graph:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  // Woohoo! We did it!
  printf("\nThanks for using the awesome C Graph representation program!");
  return 0;
}