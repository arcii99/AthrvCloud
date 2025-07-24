//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include<stdio.h>
#define MAX 10

int main(){
   int i,j,n;
   int arr[MAX][MAX];
   
   printf("Enter the number of nodes in the graph: ");
   scanf("%d",&n);
   
   // taking input for adjacency matrix
   printf("Enter the adjacency matrix:\n");
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         scanf("%d",&arr[i][j]);
      }
   }
   
   // printing graph representation
   printf("\nGraph representation using C Graph:\n");
   printf("graph G { \n");
   for(i=0;i<n;i++){
      for(j=i;j<n;j++){
         if(arr[i][j]!=0){
            printf("%d -- %d [label=%d];\n",i+1,j+1,arr[i][j]);
         }
      }
   }
   printf("}\n");
   
   return 0;
}