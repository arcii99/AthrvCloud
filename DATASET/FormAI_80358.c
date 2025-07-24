//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include<stdio.h>

void main(){
    int choice = 0, i = 0, j = 0, n = 0, m = 0;
    printf("\nEnter the number of nodes in the circuit: ");
    scanf("%d", &n);
    printf("\nEnter the number of components in the circuit: ");
    scanf("%d", &m);
    int node[n], adj_mat[n][n];
    printf("\nEnter the node numbers:");
    for(i = 0; i < n; i++){
        scanf("%d", &node[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            adj_mat[i][j] = 0;
        }
    }
    for(i = 0; i < m; i++){
        int source = 0, dest = 0, val = 0;
        printf("\nEnter the source, destination and value of component %d: ",i);
        scanf("%d%d%d",&source,&dest,&val);
        adj_mat[source][dest] = val;
    }
    printf("\nAdjacency matrix of the circuit:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ",adj_mat[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the node for which you want to calculate circuit parameters: ");
    scanf("%d",&choice);
    int incoming = 0, outgoing = 0, resistance = 0, voltage = 0;
    for(i = 0; i < n; i++){
        if(i == choice){
            continue;
        }
        if(adj_mat[i][choice] > 0){
            incoming += 1;
            resistance += adj_mat[i][choice];
        }
        if(adj_mat[choice][i] > 0){
            outgoing += 1;
            voltage += adj_mat[choice][i];
        }
    }
    printf("\nNode: %d", choice);
    printf("\nIncoming branches: %d", incoming);
    printf("\nOutgoing branches: %d", outgoing);
    printf("\nTotal resistance: %dΩ", resistance);
    printf("\nTotal voltage: %dV", voltage);
}