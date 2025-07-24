//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM_POINTS 10
#define DIMENSIONS 2
#define NUM_CLUSTERS 2
#define MAX_ITER 100

int main()
{
    // Data points
    float data[NUM_POINTS][DIMENSIONS] = {{5.0, 3.0},
                                          {4.0, 7.0},
                                          {6.0, 2.0},
                                          {8.0, 9.0},
                                          {1.0, 5.0},
                                          {3.0, 8.0},
                                          {7.0, 2.0},
                                          {9.0, 5.0},
                                          {3.0, 1.0},
                                          {2.0, 6.0}};

    // Centroids
    float centroids[NUM_CLUSTERS][DIMENSIONS] = {{2.0, 2.0},
                                                  {8.0, 8.0}};

    // Clusters
    int clusters[NUM_POINTS];

    // Iteration variables
    int i, j, k, iter;
    float dist, min_dist;

    // Main loop
    for(iter = 0; iter < MAX_ITER; iter++)
    {
        // Clear clusters
        for(i = 0; i < NUM_POINTS; i++)
            clusters[i] = -1;

        // Assign points to clusters
        for(i = 0; i < NUM_POINTS; i++)
        {
            min_dist = INFINITY;
            for(j = 0; j < NUM_CLUSTERS; j++)
            {
                dist = 0;
                for(k = 0; k < DIMENSIONS; k++)
                    dist += pow(data[i][k] - centroids[j][k], 2);
                dist = sqrt(dist);
                if(dist < min_dist)
                {
                    min_dist = dist;
                    clusters[i] = j;
                }
            }
        }

        // Calculate new centroids
        for(i = 0; i < NUM_CLUSTERS; i++)
        {
            float sum[DIMENSIONS] = {0};
            int count = 0;
            for(j = 0; j < NUM_POINTS; j++)
            {
                if(clusters[j] == i)
                {
                    for(k = 0; k < DIMENSIONS; k++)
                        sum[k] += data[j][k];
                    count++;
                }
            }

            if(count > 0)
            {
                for(k = 0; k < DIMENSIONS; k++)
                    centroids[i][k] = sum[k] / count;
            }
        }
    }

    // Print results
    printf("Final clusters:\n");
    for(i = 0; i < NUM_POINTS; i++)
        printf("(%f, %f) belongs to cluster %d\n", data[i][0], data[i][1], clusters[i]);

    return 0;
}