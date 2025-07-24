//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define the maximum number of colors to assign to the vertices
#define MAX_COLORS 10

// Define the graph structure
struct Graph {
  int vertices[MAX_VERTICES][MAX_VERTICES];
  int num_vertices;
};

// Define the function to check if a given color can be assigned to a vertex
bool can_color_vertex(int vertex, int color, struct Graph *graph, int *coloring) {
  
  // Check if any adjacent vertices already have the same color
  for (int i = 0; i < graph->num_vertices; i++) {
    if (graph->vertices[vertex][i] && color == coloring[i]) {
      return false;
    }
  }
  
  // If no adjacent vertices have the same color, the color can be assigned to the vertex
  return true;
}

// Define the recursive function to color the vertices of the graph
bool color_vertices(int vertex, struct Graph *graph, int *coloring) {
  
  // Return true if all vertices have been successfully colored
  if (vertex == graph->num_vertices) {
    return true;
  }
  
  // Try all possible colors for the current vertex
  for (int color = 1; color <= MAX_COLORS; color++) {
    
    // Check if the current color is valid for the current vertex
    if (can_color_vertex(vertex, color, graph, coloring)) {
      
      // Assign the current color to the current vertex
      coloring[vertex] = color;
      
      // Recursively try to color the remaining vertices
      if (color_vertices(vertex+1, graph, coloring)) {
        return true;
      }
      
      // If the recursive call failed, backtrack and try a different color for the current vertex
      coloring[vertex] = 0;
    }
  }
  
  // If all colors have been tried and none were successful, return false
  return false;
}

// Define a helper function to print the color assigned to each vertex
void print_coloring(struct Graph *graph, int *coloring) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Color of vertex %d: %d\n", i+1, coloring[i]);
  }
}

// Define the main function
int main() {
  
  // Initialize a graph with 5 vertices
  struct Graph graph;
  graph.num_vertices = 5;
  graph.vertices[0][1] = 1;
  graph.vertices[0][3] = 1;
  graph.vertices[1][0] = 1;
  graph.vertices[1][2] = 1;
  graph.vertices[2][1] = 1;
  graph.vertices[3][0] = 1;
  graph.vertices[3][2] = 1;
  graph.vertices[4][2] = 1;
  
  // Initialize an array to store the color assigned to each vertex
  int coloring[MAX_VERTICES] = {0};
  
  // Attempt to color the vertices of the graph
  if (color_vertices(0, &graph, coloring)) {
    printf("Graph coloring successful!\n");
    print_coloring(&graph, coloring);
  }
  else {
    printf("Graph coloring failed.\n");
  }
  
  return 0;
}