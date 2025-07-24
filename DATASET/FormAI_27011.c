//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 10

int main()
{
    float points[MAX_POINTS][2]; // array to store input points
    int num_points = 0; // number of input points
    int k; // Number of clusters
    int i, j, l; // loop variables
    float centroids[MAX_POINTS][2]; // array to store cluster centroids
    int membership[MAX_POINTS]; // array to store membership of each point
    float distance, min_distance; // variables to store distance between points and minimum distance between point and centroid
    float error; // variable to store error between centroid locations in iteration
    
    // Get input points
    printf("Enter the number of input points (Maximum %d): ", MAX_POINTS);
    scanf("%d", &num_points);
    printf("Enter the input points (x,y):\n");
    for (i = 0; i < num_points; i++) {
        scanf("%f %f", &points[i][0], &points[i][1]);
    }
    
    // Get number of clusters
    printf("Enter the number of clusters: ");
    scanf("%d", &k);
    
    // Initialize centroids randomly
    for (i = 0; i < k; i++) {
        centroids[i][0] = points[rand() % num_points][0];
        centroids[i][1] = points[rand() % num_points][1];
    }
    
    // Iterate until convergence or maximum iteration limit is reached
    for (l = 0; l < MAX_ITERATIONS; l++) {
        
        // Assign each point to a cluster
        for (i = 0; i < num_points; i++) {
            min_distance = INFINITY;
            for (j = 0; j < k; j++) {
                distance = sqrt(pow(points[i][0]-centroids[j][0],2) + pow(points[i][1]-centroids[j][1],2));
                if (distance < min_distance) {
                    min_distance = distance;
                    membership[i] = j;
                }
            }
        }
        
        // Update cluster centroids
        error = 0;
        for (i = 0; i < k; i++) {
            int count = 0;
            float x_sum = 0, y_sum = 0;
            for (j = 0; j < num_points; j++) {
                if (membership[j] == i) {
                    count++;
                    x_sum += points[j][0];
                    y_sum += points[j][1];
                }
            }
            centroids[i][0] = x_sum / count;
            centroids[i][1] = y_sum / count;
            error += sqrt(pow(centroids[i][0]-points[membership[i]][0],2) + pow(centroids[i][1]-points[membership[i]][1],2));
        }
        printf("Iteration %d, Error: %f\n", l+1, error);
    }
    
    // Print final cluster centroids and membership
    printf("Final cluster centroids:\n");
    for (i = 0; i < k; i++) {
        printf("%f %f\n", centroids[i][0], centroids[i][1]);
    }
    printf("Membership:\n");
    for (i = 0; i < num_points; i++) {
        printf("%d ", membership[i]);
    }
    printf("\n");
    
    return 0;
}