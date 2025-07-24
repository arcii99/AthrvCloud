//FormAI DATASET v1.0 Category: Graph representation ; Style: lively
#include<stdio.h>

int main(){
  int vertices;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  //Creating the 2D array to store edge information
  int edges[vertices][vertices];

  //Initializing all values to 0
  for(int i=0; i<vertices; i++){
    for(int j=0; j<vertices; j++){
      edges[i][j] = 0;
    }
  }

  //Getting edge information from the user
  for(int i=0; i<vertices; i++){
    for(int j=i+1; j<vertices; j++){
      printf("Enter 1 if there is an edge between vertex %d and %d, else enter 0: ", i+1, j+1);
      scanf("%d", &edges[i][j]);
      edges[j][i] = edges[i][j]; //Making it symmetric
    }
  }

  //Printing the graph representation
  printf("\nThe graph representation is:\n");
  printf("    ");
  for(int i=0; i<vertices; i++){
    printf("%2d ", i+1);
  }
  printf("\n");
  for(int i=0; i<vertices; i++){
    printf("%2d  ", i+1);
    for(int j=0; j<vertices; j++){
      printf("%2d ", edges[i][j]);
    }
    printf("\n");
  }

  return 0;
}