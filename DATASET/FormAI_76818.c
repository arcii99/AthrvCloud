//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 200
#define K 5
#define ITERATIONS 50

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    int x[N], y[N];
    int i, j, k, l, m, t, min_index;
    double distances[K], min_distance, total_distance;
    int cluster_sizes[K], assignments[N], old_assignments[N], moved_points[K];
    double centroids_x[K], centroids_y[K];

    srand(time(NULL));

    // Randomly generate N points
    for(i = 0; i < N; i++)
    {
        x[i] = rand() % 100;
        y[i] = rand() % 100;
    }

    // Initialize centroids
    for(i = 0; i < K; i++)
    {
        centroids_x[i] = x[rand() % N];
        centroids_y[i] = y[rand() % N];
        cluster_sizes[i] = 0;
    }

    // Iterate K-Means algorithm
    for(m = 0; m < ITERATIONS; m++)
    {
        printf("Iteration %d\n", m);

        // Assign points to clusters
        total_distance = 0;
        for(i = 0; i < N; i++)
        {
            min_distance = 1000;
            for(j = 0; j < K; j++)
            {
                distances[j] = distance(x[i], y[i], centroids_x[j], centroids_y[j]);
                if(distances[j] < min_distance)
                {
                    min_distance = distances[j];
                    min_index = j;
                }
            }
            assignments[i] = min_index;
            total_distance += min_distance;
        }
        printf("Average distance to centroid: %f\n", total_distance / N);

        // Calculate new centroids
        for(k = 0; k < K; k++)
        {
            centroids_x[k] = 0;
            centroids_y[k] = 0;
            cluster_sizes[k] = 0;
        }
        for(l = 0; l < N; l++)
        {
            int cluster = assignments[l];
            centroids_x[cluster] += x[l];
            centroids_y[cluster] += y[l];
            cluster_sizes[cluster]++;
        }
        for(t = 0; t < K; t++)
        {
            if(cluster_sizes[t] != 0)
            {
                centroids_x[t] /= cluster_sizes[t];
                centroids_y[t] /= cluster_sizes[t];
            }
        }

        // Check for convergence
        if(m > 0)
        {
            int num_same = 0;
            for(int f = 0; f < N; f++)
            {
                if(assignments[f] == old_assignments[f])
                {
                    num_same++;
                }
            }
            if(num_same == N)
            {
                printf("Converged after %d iterations\n", m);
                break;
            }
        }

        // Store assignments for comparison in the next iteration
        for(int g = 0; g < N; g++)
        {
            old_assignments[g] = assignments[g];
        }
    }

    // Print final cluster assignments
    printf("Final cluster assignments:\n");
    for(int h = 0; h < K; h++)
    {
        int cluster_size = 0;
        for(int n = 0; n < N; n++)
        {
            if(assignments[n] == h)
            {
                cluster_size++;
            }
        }
        printf("Cluster %d (%d points):\n", h, cluster_size);
        printf("Centroid: (%f, %f)\n", centroids_x[h], centroids_y[h]);
    }

    return 0;
}