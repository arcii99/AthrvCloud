//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main(){
  printf("Get ready to be surprised by this unique C Graph representation program!\n");

  int n;
  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &n);

  int** graph = (int**) malloc(n * sizeof(int*));
  for(int i=0; i<n; i++){
    graph[i] = (int*) malloc(n * sizeof(int));
  }
  
  printf("\nEnter the graph adjacency matrix:\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &graph[i][j]);
    }
  }

  printf("\nHere's the surprising graph representation: \n\n");
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(graph[i][j] == 1){
        printf("* ");
      } else{
        printf(". ");
      }
    }
    printf("\n");
  }

  printf("\nAnd there you have it, a unique and surprising way to represent graphs in C!\n\n");

  for(int i=0; i<n; i++){
    free(graph[i]);
  }
  free(graph);

  printf("Program ended. Hope you were surprised!\n");

  return 0;
}