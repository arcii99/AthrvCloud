//FormAI DATASET v1.0 Category: Graph representation ; Style: bold
#include<stdio.h>

int main(){

  printf("\n\n\n\n\n\t\t\t Graph Representation \t\t\t\n\n\n");

  int v, e, i, j, x, y;
  
  printf("Enter the number of vertices: ");
  scanf("%d", &v);
  
  printf("Enter the number of edges: ");
  scanf("%d", &e);

  int graph[v][v];

  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
        graph[i][j]=0;
    }
  }

  printf("\nEnter the edges:\n");
  for(i=0;i<e;i++){
    printf("Edge %d: ",i+1);
    scanf("%d %d",&x,&y);
    graph[x-1][y-1]=1;
    graph[y-1][x-1]=1; 
  }

  printf("The adjacency matrix representation of the graph is:\n\n");
  for(i=0;i<v;i++){
    for(j=0;j<v;j++){
        printf("%d ",graph[i][j]);     
    }  
    printf("\n");
  } 

  return 0;
}