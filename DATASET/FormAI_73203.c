//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int main(){
  int vertex, edge;
  printf("Enter the number of vertices: ");
  scanf("%d", &vertex);
  printf("Enter the number of edges: ");
  scanf("%d", &edge);
  
  int graph[vertex][vertex];
  printf("\nEnter the adjacency matrix:\n");
  for(int i=0;i<vertex;i++)
    for(int j=0;j<vertex;j++)
      scanf("%d", &graph[i][j]);
      
  int color[vertex];
  printf("\nPossible colors: 1, 2, 3, 4, 5, 6");
  for(int i=0;i<vertex;i++)
    color[i]=0;
      
  for(int i=0;i<vertex;i++){
    int available_colors[6]={1,1,1,1,1,1};
    for(int j=0;j<vertex;j++){
      if(graph[i][j]==1)
        available_colors[color[j]-1]=0;
    }
    for(int k=0;k<6;k++){
      if(available_colors[k]==1){
        color[i]=k+1;
        break;
      }
    }
  }
  
  printf("\nColoring of vertices:\n");
  for(int i=0;i<vertex;i++)
    printf("Vertex %d ---> Color %d\n", i+1, color[i]);

  return 0;
}