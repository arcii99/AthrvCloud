//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#define max_size 100
int G[max_size][max_size],colors[max_size];
int n,m;

int promising(int i,int color){
    for(int j=0;j<n;j++){
        if(G[i][j] && color==colors[j]){      //Checking if the edge is there and the neighboring vertex is using the same color or not
            return 0;
        }
    }
    return 1;
}

void graph_color(int v){
    int color;
    if(v==n){                      //Base condition
        for(int i=0;i<n;i++){
            printf("\nVertex %d is colored with %d\n",i+1,colors[i]);
        }
        return;
    }
    for(color=1;color<=m;color++){
        if(promising(v,color)){   //Checking promising
            colors[v] = color;
            graph_color(v+1);
            colors[v] = 0;
        }
    }
}


int main(){
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the number of colors:\n");
    scanf("%d",&m);
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("Coloring the vertices...\n");
    graph_color(0);
    return 0;
}