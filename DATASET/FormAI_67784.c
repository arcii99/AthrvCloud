//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>

int main() {
  
  int n, i, j;
  
  //Prompt user for number of nodes in the graph
  printf("Enter the number of nodes in the graph: ");
  scanf("%d", &n);
  
  //Create adjacency matrix
  int adj_matrix[n][n];
  
  //Initialize adjacency matrix with zeros
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      adj_matrix[i][j] = 0;
    }
  }
  
  //Prompt user for edges in the graph
  printf("Enter the edges in the graph in the format 'node1 node2':\n");
  printf("Enter '-1 -1' to terminate input.\n");
  
  int node1, node2;
  scanf("%d %d", &node1, &node2);
  
  while(node1 != -1 && node2 != -1) {
    
    //Check for invalid input
    if(node1 < 0 || node1 >= n || node2 < 0 || node2 >= n) {
      printf("Invalid input\n");
    }
    else {
      //Add edge to adjacency matrix
      adj_matrix[node1][node2] = 1;
      adj_matrix[node2][node1] = 1;
    }
    
    //Prompt user for next input
    scanf("%d %d", &node1, &node2);
  }
  
  //Print adjacency matrix
  printf("Adjacency Matrix:\n");
  for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
      printf("%d ", adj_matrix[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}