//FormAI DATASET v1.0 Category: Graph representation ; Style: rigorous
#include<stdio.h>

//function to create a graph
void createGraph(int graph[][10], int vertices) {
   int i,j;
   for(i = 0; i < vertices; i++) {
      for(j = 0; j < vertices; j++) {
         printf("Is there an edge between vertex %d and vertex %d? (1/0)\n", i+1, j+1);
         scanf("%d", &graph[i][j]);
      }
      printf("\n");
   }
}

//function to print the graph
void printGraph(int graph[][10], int vertices) {
   int i,j;
   for(i = 0; i < vertices; i++) {
      printf("\nVertices adjacent to vertex %d are: ", i+1);
      for(j = 0; j < vertices; j++) {
         if(graph[i][j] == 1) {
            printf("%d,", j+1);
         }
      }
   }
   printf("\n");
}

//main function
int main() {
   int vertices, graph[10][10];
   printf("Enter the number of vertices in the graph: ");
   scanf("%d", &vertices);
   createGraph(graph, vertices);
   printGraph(graph, vertices);
   return 0;
}