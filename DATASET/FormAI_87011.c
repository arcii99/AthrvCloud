//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>

#define MAX 100

int main(){
    int n, i, j, adj_matrix[MAX][MAX];
    float degree_centrality[MAX], mean_degree_ctr=0, std_dev_degree_ctr=0, sum=0, sum_sq=0;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &adj_matrix[i][j]);
        }
    }
    
    // Degree Centrality Calculation
    for(i=0; i<n; i++){
        int degree=0;
        for(j=0; j<n; j++){
            if(adj_matrix[i][j]==1)
                degree++;
        }
        degree_centrality[i] = (float)degree/(n-1);
        sum += degree_centrality[i];
        sum_sq += (degree_centrality[i] * degree_centrality[i]);
    }

    mean_degree_ctr = sum/n;
    std_dev_degree_ctr = sqrt((sum_sq/n) - (mean_degree_ctr * mean_degree_ctr));

    printf("\nDegree Centrality:\n");
    for(i=0; i<n; i++){
        printf("Vertex %d: %f\n", i+1, degree_centrality[i]);
    }

    printf("\nMean Degree Centrality: %f\n", mean_degree_ctr);
    printf("Standard Deviation of Degree Centrality: %f\n", std_dev_degree_ctr);

    return 0;
}