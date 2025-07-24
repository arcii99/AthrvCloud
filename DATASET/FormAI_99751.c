//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>

int main() {

  printf("Welcome to the amazing world of C Graph Representation!\n\n");

  int vertices, edges;
  printf("How many vertices does your graph have? ");
  scanf("%d", &vertices);

  printf("How many edges does your graph have? ");
  scanf("%d", &edges);

  int graph[vertices][vertices];
  int i, j;

  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      graph[i][j] = 0;
    }
  }

  int vertex1, vertex2;
  for (i = 1; i <= edges; i++) {
    printf("\nEnter edge %d in the form [vertex1] [vertex2]: ", i);
    scanf("%d %d", &vertex1, &vertex2);
    graph[vertex1][vertex2] = 1;
    graph[vertex2][vertex1] = 1;
  }
  
  printf("\nYour graph is:\n");

  for (i = 0; i < vertices; i++) {
    for (j = 0; j < vertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }

  printf("\nThanks for using C Graph Representation!\n");

  return 0;
}