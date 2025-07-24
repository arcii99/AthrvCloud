//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include <stdio.h>

/* Define the maximum number of nodes this circuit will have */
#define MAX_NODES 100

int main() {
    int i,j,k;
    int numNodes,numElems;
    int A[MAX_NODES][MAX_NODES+1];
    int node1,node2,value;
  
    /* Ask user for the number of nodes in the circuit and the number of elements */
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d",&numNodes);
    printf("Enter the number of elements in the circuit: ");
    scanf("%d",&numElems);

    /* Initialize matrix A to all zeroes */
    for (i=0;i<numNodes;i++) {
        for (j=0;j<=numNodes;j++) {
            A[i][j] = 0;
        }
    }

    /* Ask user for each element and its values, and update matrix A accordingly */
    for (k=0;k<numElems;k++) {
        printf("Enter element %d (node1,node2,value): ",k+1);
        scanf("%d %d %d",&node1,&node2,&value);
        A[node1-1][node1-1] += 1.0/value;
        A[node1-1][node2-1] -= 1.0/value;
        A[node2-1][node1-1] -= 1.0/value;
        A[node2-1][node2-1] += 1.0/value;
    }

    /* Print out the matrix A for debugging purposes */
    for (i=0;i<numNodes;i++) {
        for (j=0;j<=numNodes;j++) {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
  
    return 0;
}