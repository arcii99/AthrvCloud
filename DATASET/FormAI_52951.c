//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include<stdio.h>

// A function to implement Kruskal's algorithm
int kruskalMST(int n, int e, int edge[][3]){
    int parent[n], rank[n];
    for(int i=0;i<n;i++){
        parent[i] = i;
        rank[i] = 0;
    }
    int i = 0, j = 0, cost = 0;
    int result[n-1][2]; // To store the minimum spanning tree
    while(i<n-1 && j<e){
        int u = edge[j][0];
        int v = edge[j][1];
        int w = edge[j][2];
        j++;
        int x = find(parent, u);
        int y = find(parent, v);
        if(x != y){
            i++;
            result[i-1][0] = u;
            result[i-1][1] = v;
            unionNodes(parent, rank, x, y);
            cost += w;
        }
    }
    printf("Minimum Cost Spanning Tree: ");
    int count = 0;
    for(int i=0;i<n-1;i++){
        printf("\nEdge %d: %d - %d Weight: %d", i+1, result[i][0]+1, result[i][1]+1, findCost(result[i][0], result[i][1], edge));
        count += findCost(result[i][0], result[i][1], edge);
    }
    printf("\nTotal cost is %d", count);
    return cost;
}

// A utility function to find the parent node
int find(int parent[], int i){
    if(parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

// A utility function to join two nodes
void unionNodes(int parent[], int rank[], int x, int y){
    if(rank[x] > rank[y])
        parent[y] = x;
    else if(rank[x] < rank[y])
        parent[x] = y;
    else{
        parent[x] = y;
        rank[y]++;
    }
}

// A utility function to find the cost of an edge
int findCost(int u, int v, int edge[][3]){
    for(int i=0;i<3;i++)
        if(edge[i][0] == u && edge[i][1] == v)
            return edge[i][2];
    return -1;
}

// Driver program to test above functions
int main(){
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    int edge[e][3];
    printf("Enter the edges with weights: ");
    for(int i=0;i<e;i++)
        scanf("%d%d%d", &edge[i][0], &edge[i][1], &edge[i][2]);
    for(int i=0;i<e;i++)
        for(int j=i+1;j<e;j++)
            if(edge[i][2] > edge[j][2]){
                int temp[3];
                for(int k=0;k<3;k++)
                    temp[k] = edge[i][k];
                for(int k=0;k<3;k++)
                    edge[i][k] = edge[j][k];
                for(int k=0;k<3;k++)
                    edge[j][k] = temp[k];
            }
    printf("Minimum Total Cost: %d", kruskalMST(n, e, edge));
    return 0;
}