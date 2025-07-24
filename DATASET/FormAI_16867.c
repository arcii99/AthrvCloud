//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define maximum number of vertices in the graph
#define MAX_VERTICES 10

// Define maximum number of colors that can be used to color the graph
#define MAX_COLORS 5

// Define a 2D matrix to represent the graph and initialize it with random values from 0 to 1
int graph[MAX_VERTICES][MAX_VERTICES];

void initializeGraph() {
  srand(time(NULL));
  for (int i = 0; i < MAX_VERTICES; i++) {
    for (int j = 0; j < MAX_VERTICES; j++) {
      if (i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = rand() % 2;
      }
    }
  }
}

// Define a function to check whether two adjacent vertices have same color or not
int checkAdjacentVertices(int position[], int color) {
  for (int i = 0; i < MAX_VERTICES; i++) {
    if ((graph[position[0]][i] == 1 || graph[position[1]][i] == 1) && position[2] == color) {
      return 0;
    }
  }
  return 1;
}

// Define a function to color the graph using minimum number of colors
void colorGraph() {
  int colors[MAX_VERTICES] = {-1};
  for (int i = 0; i < MAX_VERTICES; i++) { // loop through all the vertices in the graph
    int availableColors[MAX_COLORS] = {0};
    for (int j = 0; j < MAX_COLORS; j++) { // loop through all the available colors
      availableColors[j] = 1; // assume the color is available initially
    }
    for (int j = 0; j < i; j++) { // loop through all the colored vertices
      if (graph[i][j] == 1 && colors[j] != -1) { // check for adjacent vertices and their already assigned colors
        availableColors[colors[j]] = 0; // set the color not available if the adjacent vertex has that color
      }
    }
    for (int j = 0; j < MAX_COLORS; j++) { // loop through all the available colors again
      if (availableColors[j]) { // check whether the color is available or not
        colors[i] = j; // assign the available color to this vertex
        break;
      }
    }
  }
  printf("\nColors assigned to vertices:\n");
  for (int i = 0; i < MAX_VERTICES; i++) { // loop through all the vertices and print their assigned colors
    printf("Vertex %d: %d\n", i+1, colors[i]+1);
  }
}

int main() {
  initializeGraph();
  printf("Graph:\n");
  for (int i = 0; i < MAX_VERTICES; i++) { // loop through the graph matrix and print its contents
    for (int j = 0; j < MAX_VERTICES; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  colorGraph();
  return 0;
}