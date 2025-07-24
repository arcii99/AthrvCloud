//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>

int main(){

  //creating a 2D array as graph nodes, with 7 vertices and 7 connections
  int graph[7][7] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 0, 0, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0}
  };
  
  //printing out the graph
  printf("      1 2 3 4 5 6 7\n");
  printf("     _______________\n");
  
  for(int i=0; i<7; i++){
    printf("%c | ", i+65);
    for(int j=0; j<7; j++){
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}