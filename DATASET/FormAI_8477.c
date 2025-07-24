//FormAI DATASET v1.0 Category: Graph representation ; Style: scientific
/*This program generates a random directed graph with n number of nodes, and then prints a scientific representation of the graph using adjacency matrix*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int n, i, j, k;

    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    int graph[n][n];

    srand(time(0));

    /*generate random directed graph*/
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i!=j){
                graph[i][j]=rand()%2;
            }
            else{
                graph[i][j]=0;
            }
        }
    }

    /*print adjacency matrix*/
    printf("\n\nScientific representation of graph using adjacency matrix:\n");
    printf("\n\t");
    for(k=0; k<n; k++){
        printf("%d\t",k+1);
    }
    printf("\n");

    for(i=0; i<n; i++){
        printf("%d\t",i+1);
        for(j=0; j<n; j++){
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}