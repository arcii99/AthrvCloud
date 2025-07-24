//FormAI DATASET v1.0 Category: Graph representation ; Style: careful
#include<stdio.h>

int main(){
  int n;
  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &n);
  
  int adjacency_matrix[n][n];
  printf("Enter the adjacency matrix for the graph (provide 0 for no edge and 1 for an edge): \n");
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &adjacency_matrix[i][j]);
    }
  }
  
  printf("\nThe graph representation using adjacency matrix is:\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ", adjacency_matrix[i][j]);
    }
    printf("\n");
  }
  
  printf("\nThe graph representation using edge list is:\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(adjacency_matrix[i][j]==1){
        printf("(%d, %d)\n", i, j);
      }
    }
  }
  
  printf("\nThe graph representation using adjacency list is:\n");
  for(int i=0; i<n; i++){
    printf("%d -> ", i);
    for(int j=0; j<n; j++){
      if(adjacency_matrix[i][j]==1){
        printf("%d ", j);
      }
    }
    printf("\n");
  }
  
  return 0;
}