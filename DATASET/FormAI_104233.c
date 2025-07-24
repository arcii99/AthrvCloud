//FormAI DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 20

int n, adjacency_matrix[MAX_VERTEX][MAX_VERTEX];

void dfs(int vertex, int visited[]) {
  int i, j;
  printf("\nVisited: %d", vertex);
  visited[vertex] = 1;

  for(i = 0; i < n; i++) {
    if(adjacency_matrix[vertex][i] == 1 && !visited[i]) {
      dfs(i, visited);
    }
  }
}

void main() {
  int i, j, visited[MAX_VERTEX];

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix: ");
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      scanf("%d", &adjacency_matrix[i][j]);
    }
  }

  printf("The adjacency matrix is: \n");
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      printf("%d ", adjacency_matrix[i][j]);
    }
    printf("\n");
  }

  for(i = 0; i < n; i++) {
    visited[i] = 0;
  }

  dfs(0, visited);
}