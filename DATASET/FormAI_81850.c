//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 /* Number of data points */
#define K 2 /* Number of clusters */
#define D 2 /* Number of dimensions */

/* Data points */
double data_points[N][D] = {{32, 46}, {33, 50}, {28, 42}, {36, 53}, {30, 45},
                            {35, 55}, {27, 50}, {37, 51}, {29, 48}, {38, 46}};

/* Initial centroid positions */
double centroid_positions[K][D] = {{30, 50}, {35, 45}};

/* Cluster assignment for each data point */
int cluster_assignment[N] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

/* Function to calculate Euclidean distance between two data points */
double euclidean_distance(double *p1, double *p2, int d)
{
    int i;
    double distance = 0.0;
    for (i = 0; i < d; i++)
    {
        distance += pow(*(p1 + i) - *(p2 + i), 2);
    }
    return sqrt(distance);
}

/* Function to print current cluster assignments */
void print_cluster_assignments()
{
    int i;
    printf("Current cluster assignments:\n");
    for (i = 0; i < N; i++)
    {
        printf("Data point %d -> Cluster %d\n", i, cluster_assignment[i]);
    }
    printf("\n");
}

/* Function to calculate new centroid positions */
void calculate_new_centroid_positions()
{
    int i, j, k, num_points_in_cluster;
    double sum[D], average[D];
    for (k = 0; k < K; k++)
    {
        num_points_in_cluster = 0;
        for (j = 0; j < D; j++)
        {
            sum[j] = 0.0;
        }
        for (i = 0; i < N; i++)
        {
            if (cluster_assignment[i] == k)
            {
                num_points_in_cluster++;
                for (j = 0; j < D; j++)
                {
                    sum[j] += data_points[i][j];
                }
            }
        }
        for (j = 0; j < D; j++)
        {
            average[j] = sum[j] / num_points_in_cluster;
            centroid_positions[k][j] = average[j];
        }
    }
}

/* Main function */
int main()
{
    int i, j, k, min_cluster, num_iterations = 0, max_iterations = 100;
    double min_distance, distance;
    /* Iterate until convergence or maximum iterations reached */
    while (num_iterations < max_iterations)
    {
        printf("Iteration %d:\n", num_iterations + 1);
        /* Assign each data point to the closest centroid */
        for (i = 0; i < N; i++)
        {
            min_cluster = -1;
            min_distance = INFINITY;
            for (k = 0; k < K; k++)
            {
                distance = euclidean_distance(data_points[i], centroid_positions[k], D);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    min_cluster = k;
                }
            }
            cluster_assignment[i] = min_cluster;
        }
        print_cluster_assignments();
        /* Re-calculate centroid positions */
        calculate_new_centroid_positions();
        num_iterations++;
    }
    return 0;
}