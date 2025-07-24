//FormAI DATASET v1.0 Category: Graph representation ; Style: satisfied
#include<stdio.h>

// Function to display the graph
void displayGraph(int matrix[][10], int vertices) {
   printf("The Adjacency Matrix:\n\n");
   for(int i=0; i<vertices; i++) {
      for(int j=0; j<vertices; j++) {
         printf("%d\t", matrix[i][j]);
      }
      printf("\n");
   } 
}

int main() {
   int vertices, matrix[10][10];
   printf("Enter the number of vertices in the Graph: ");
   scanf("%d", &vertices);

   // Taking matrix input
   printf("Enter the Adjacency matrix of the Graph:\n");
   for(int i=0; i<vertices; i++) {
      for(int j=0; j<vertices; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   displayGraph(matrix, vertices);

   return 0;
}