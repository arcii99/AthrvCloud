//FormAI DATASET v1.0 Category: Graph representation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int nodes, edges, i, j, count = 0, index = 0;
   printf("Enter the number of nodes: "); // asking the user to enter number of nodes
   scanf("%d", &nodes);
   printf("Enter the number of edges: "); // asking the user to enter number of edges
   scanf("%d", &edges);
   
   int adj_matrix[nodes][nodes];
   
   for (i = 0; i < nodes; i++)
   {
       for (j = 0; j < nodes; j++)
       {
           adj_matrix[i][j] = 0;
       }
   }

   printf("\nInput the edges in the form 'nodeA nodeB': \n");
   
   while (count < edges)
   {
       int nodeA, nodeB;
       scanf("%d %d", &nodeA, &nodeB);
       if (nodeA == nodeB)
       {
           printf("Self-loops are not allowed.\n");
           continue;
       }
       if (adj_matrix[nodeA][nodeB] == 1)
       {
           printf("Duplicate edges are not allowed.\n");
           continue;
       }
       adj_matrix[nodeA][nodeB] = 1; // creating an edge between nodeA and nodeB
       count++;
   }

   printf("\nThe adjacency matrix representation of the given graph:\n\n");
   printf("   ");
   for (i = 0; i < nodes; i++)
   {
       printf("%d ", i);
   }
   printf("\n");
   
   for (i = 0; i < nodes; i++)
   {
       printf("%d: ", i);
       for (j = 0; j < nodes; j++)
       {
           printf("%d ", adj_matrix[i][j]); // printing the adjacency matrix
           if (adj_matrix[i][j] == 1)
           {
               index++;
           }
       }
       printf("\n");
   }

   printf("\nThe number of edges in the graph: %d\n", index);

   return 0;
}