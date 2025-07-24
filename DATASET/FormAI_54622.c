//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5

int graph[V][V] = {
  {0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1},
  {0, 1, 0, 1, 0},
  {1, 0, 1, 0, 1},
  {1, 1, 0, 1, 0}
};

void printSolution(int color[]){
  printf("Vertex \tColor\n");
  for(int i = 0; i < V; i++){
    printf("%d\t%d\n", i, color[i]);
  }
}

bool isSafe(int v, int color[], int c){
  for(int i = 0; i < V; i++){
    if(graph[v][i] && c == color[i]){
      return false;
    }
  }
  return true;
}

bool graphColoringUtil(int color[], int v){
  if(v == V){
    return true;
  }

  for(int c = 1; c <= V; c++){
    if(isSafe(v, color, c)){
      color[v] = c;
      if(graphColoringUtil(color, v + 1) == true){
        return true;
      }
      color[v] = 0;
    }
  }
  return false;
}

bool graphColoring(){
  int color[V];
  for(int i = 0; i < V; i++){
    color[i] = 0;
  }

  if(graphColoringUtil(color, 0) == false){
    printf("Solution does not exist.\n");
    return false;
  }

  printSolution(color);
  return true;
}

int main(){
  graphColoring();

  return 0; 
}