//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// Function to check if adjacent vertices have different colors
int isSafe(int v, int graph[MAX][MAX], int color[MAX], int c) {
  for (int i = 0; i < v; i++) {
    if (graph[v][i] && c == color[i]) {
      return 0;
    }
  }
  return 1;
}

// Function to recursively assign colors to each vertex
int graphColoringUtil(int graph[MAX][MAX], int v, int color[MAX], int m) {
  if (v == MAX) {
    return 1;
  }
  for (int c = 1; c <= m; c++) {
    if (isSafe(v, graph, color, c)) {
      color[v] = c;
      if (graphColoringUtil(graph, v + 1, color, m)) {
        return 1;
      }
      color[v] = 0;
    }
  }
  return 0;
}

// Function to call the recursive graph coloring function
int graphColoring(int graph[MAX][MAX], int m) {
  int color[MAX] = {0};
  if (!graphColoringUtil(graph, 0, color, m)) {
    return 0;
  }
  return 1;
}

// Driver code
int main() {
  int graph[MAX][MAX] = {{0,1,1,1,0},
                         {1,0,1,0,1},
                         {1,1,0,1,0},
                         {1,0,1,0,1},
                         {0,1,0,1,0}};
  int m = 3;
  if (graphColoring(graph, m)) {
    printf("Graph can be colored with %d colors.\n", m);
  }
  else {
    printf("Graph cannot be colored with %d colors.\n", m);
  }
  return 0;
}