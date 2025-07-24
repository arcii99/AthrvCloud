//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 10;
    double data[10] = {1.2, 1.4, 1.5, 2.3, 2.4, 2.9, 3.2, 3.5, 4.1, 5.2};
    int k = 3;
    double centroids[3] = {1.0, 2.0, 5.0};
    double clusters[3][10];

    // Repeat until convergence
    while (1)
    {
        // Assign each point to its nearest centroid
        for (int i = 0; i < n; i++)
        {
            double min_distance = INFINITY;
            int min_idx = -1;
            for (int j = 0; j < k; j++)
            {
                double distance = fabs(data[i] - centroids[j]);
                if (distance < min_distance)
                {
                    min_distance = distance;
                    min_idx = j;
                }
            }
            clusters[min_idx][i] = data[i];
        }

        // Recalculate centroids
        int has_converged = 1;
        for (int j = 0; j < k; j++)
        {
            double sum = 0.0;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (clusters[j][i] != 0.0)
                {
                    sum += clusters[j][i];
                    count++;
                }
            }
            if (count > 0)
            {
                double new_centroid = sum / count;
                if (new_centroid != centroids[j])
                {
                    centroids[j] = new_centroid;
                    has_converged = 0;
                }
            }
        }

        if (has_converged)
        {
            break;
        }
    }

    // Print clusters
    for (int j = 0; j < k; j++)
    {
        printf("Cluster %d: ", j+1);
        for (int i = 0; i < n; i++)
        {
            if (clusters[j][i] != 0.0)
            {
                printf("%.1f ", clusters[j][i]);
            }
        }
        printf("\n");
    }

    return 0;
}