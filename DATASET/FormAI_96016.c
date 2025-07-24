//FormAI DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define THRESHOLD 0.0001

int main()
{
    int num_points, num_clusters, i, j, n, index, iteration;
    double **points, **centroids, **new_centroids, *distances, min_distance, total_distance, change;
    
    // Get user input for number of data points and number of clusters
    printf("Enter the number of data points to generate: ");
    scanf("%d", &num_points);
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    
    // Allocate memory for arrays
    points = (double **)malloc(num_points * sizeof(double *));
    centroids = (double **)malloc(num_clusters * sizeof(double *));
    new_centroids = (double **)malloc(num_clusters * sizeof(double *));
    distances = (double *)malloc(num_clusters * sizeof(double));
    
    for(i = 0; i < num_points; i++)
    {
        points[i] = (double *)malloc(2 * sizeof(double));
    }
    
    for(i = 0; i < num_clusters; i++)
    {
        centroids[i] = (double *)malloc(2 * sizeof(double));
        new_centroids[i] = (double *)malloc(2 * sizeof(double));
    }
    
    // Generate random data points
    srand(time(NULL));
    for(i = 0; i < num_points; i++)
    {
        points[i][0] = (double)rand() / RAND_MAX;
        points[i][1] = (double)rand() / RAND_MAX;
    }
    
    // Initialize centroids to random data points
    for(i = 0; i < num_clusters; i++)
    {
        index = rand() % num_points;
        centroids[i][0] = points[index][0];
        centroids[i][1] = points[index][1];
    }
    
    // Run k-means algorithm
    iteration = 0;
    do
    {
        // Assign each data point to nearest centroid
        total_distance = 0.0;
        for(i = 0; i < num_points; i++)
        {
            min_distance = INFINITY;
            for(j = 0; j < num_clusters; j++)
            {
                distances[j] = sqrt(pow(points[i][0] - centroids[j][0], 2) + pow(points[i][1] - centroids[j][1], 2));
                if(distances[j] < min_distance)
                {
                    min_distance = distances[j];
                    n = j;
                }
            }
            total_distance += min_distance;
            points[i][2] = n;
        }
        
        // Calculate new centroids
        for(i = 0; i < num_clusters; i++)
        {
            new_centroids[i][0] = 0.0;
            new_centroids[i][1] = 0.0;
            n = 0;
            for(j = 0; j < num_points; j++)
            {
                if(points[j][2] == i)
                {
                    new_centroids[i][0] += points[j][0];
                    new_centroids[i][1] += points[j][1];
                    n++;
                }
            }
            if(n > 0)
            {
                new_centroids[i][0] /= n;
                new_centroids[i][1] /= n;
            }
        }
        
        // Calculate change in centroid positions
        change = 0.0;
        for(i = 0; i < num_clusters; i++)
        {
            change += sqrt(pow(new_centroids[i][0] - centroids[i][0], 2) + pow(new_centroids[i][1] - centroids[i][1], 2));
            centroids[i][0] = new_centroids[i][0];
            centroids[i][1] = new_centroids[i][1];
        }
        
        iteration++;
    } while(iteration < MAX_ITERATIONS && change > THRESHOLD);
    
    // Print results
    printf("\nFinal centroids:\n");
    for(i = 0; i < num_clusters; i++)
    {
        printf("(%lf, %lf)\n", centroids[i][0], centroids[i][1]);
    }
    printf("Total distance: %lf\n", total_distance);
    
    // Free memory
    for(i = 0; i < num_points; i++)
    {
        free(points[i]);
    }
    for(i = 0; i < num_clusters; i++)
    {
        free(centroids[i]);
        free(new_centroids[i]);
    }
    free(points);
    free(centroids);
    free(new_centroids);
    free(distances);
    
    return 0;
}