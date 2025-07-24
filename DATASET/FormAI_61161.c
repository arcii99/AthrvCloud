//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 50

int main() {
    int i,j,n;
    printf("Enter the number of nodes in the circuit: ");
    scanf("%d",&n);
    if(n > MAX_NODES) {
        printf("Sorry, the circuit cannot have more than %d nodes.\n",MAX_NODES);
        exit(0);
    } else {
        printf("The circuit has %d nodes.\n",n);
    }
    // rest of the code
    printf("Romeo: Oh Juliet, the circuit simulator is ready!\n");
    printf("Juliet: My Romeo, you never cease to amaze me. Let's test it out!\n");
    printf("Romeo: Sure thing, Juliet. Let's input the node values.\n");
    int nodes[MAX_NODES];
    printf("Enter the values of the nodes:\n");
    for(i=0;i<n;i++) {
        scanf("%d",&nodes[i]);
    }
    printf("Juliet: Romeo, let us simulate the circuit now.\n");
    int adj_matrix[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%d",&adj_matrix[i][j]);
        }
    }
    printf("Romeo: The circuit has been simulated, Juliet.\n");
    printf("Juliet: Romeo, what are the output values of the nodes?\n");
    for(i=0;i<n;i++) {
        int output = nodes[i];
        for(j=0;j<n;j++) {
            if(adj_matrix[i][j] == 1) {
                output += nodes[j];
            }
        }
        printf("The output value of node %d is %d\n",i+1,output);
    }
    printf("Romeo: Juliet, the circuit simulation is complete. We are ready to build the actual circuit now!\n");
    return 0;
}