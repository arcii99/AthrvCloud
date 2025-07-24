//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10    // Number of data points
#define M 2     // Number of attributes in each data point
#define K 3     // Number of clusters to form

double data[N][M] = {  {2.0, 4.0}, {2.0, 3.0}, {3.0, 4.0}, {2.0, 2.0}, {4.0, 2.0}, {5.0, 3.0}, {5.0, 2.0}, {6.0, 4.0}, {6.0, 5.0}, {7.0, 4.0} };
double centroids[K][M] = { {2.0, 2.0}, {4.0, 2.0}, {5.0, 3.0} };

int main()
{
    int i, j, k, n, iteration, min_index;
    double distance, min_distance;
    
    // Array to hold the cluster assignments of each data point
    int cluster_assignment[N];
    
    // Display the initial centroids
    printf("Initial Centroids:\n");
    for (i = 0; i < K; i++)
    {
        printf("%.1f %.1f\n", centroids[i][0], centroids[i][1]);
    }
    
    // Iterative process to assign data points to clusters and update centroids
    for (iteration = 1; iteration <= 10; iteration++)
    {
        // Assign each data point to the nearest centroid
        for (n = 0; n < N; n++)
        {
            min_distance = INFINITY;
            for (k = 0; k < K; k++)
            {
                distance = 0.0;
                for (j = 0; j < M; j++)
                {
                    distance += pow((data[n][j] - centroids[k][j]), 2);
                }
                distance = sqrt(distance);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    min_index = k;
                }
            }
            cluster_assignment[n] = min_index;
        }
        
        // Update the centroids based on the mean of the assigned data points
        for (k = 0; k < K; k++)
        {
            int count = 0;
            double sum[M] = {0.0};
            for (n = 0; n < N; n++)
            {
                if (cluster_assignment[n] == k)
                {
                    for (j = 0; j < M; j++)
                    {
                        sum[j] += data[n][j];
                    }
                    count++;
                }
            }
            if (count != 0)
            {
                for (j = 0; j < M; j++)
                {
                    centroids[k][j] = sum[j] / count;
                }
            }
        }
        
        // Display the centroids after each iteration
        printf("After Iteration %d:\n", iteration);
        for (i = 0; i < K; i++)
        {
            printf("%.1f %.1f\n", centroids[i][0], centroids[i][1]);
        }
    }
    
    return 0;
}