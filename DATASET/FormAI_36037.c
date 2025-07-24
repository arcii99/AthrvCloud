//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DATA_POINTS 1000
#define ATTRIBUTES 5
#define CLUSTERS 4
#define MAX_ITERATIONS 100

void k_means_clustering(double data[DATA_POINTS][ATTRIBUTES], double centers[CLUSTERS][ATTRIBUTES], int assignments[DATA_POINTS]) {
    int i, j, k, min_index;
    double min_distance, distance_sum;
    int cluster_sizes[CLUSTERS];
    double new_centers[CLUSTERS][ATTRIBUTES];
    
    // initialize assignments to -1 to indicate no assignment
    for (i = 0; i < DATA_POINTS; i++) {
        assignments[i] = -1;
    }
    
    // assign each data point to the closest center
    for (i = 0; i < DATA_POINTS; i++) {
        min_distance = INFINITY;
        for (j = 0; j < CLUSTERS; j++) {
            distance_sum = 0;
            for (k = 0; k < ATTRIBUTES; k++) {
                distance_sum += pow(data[i][k] - centers[j][k], 2);
            }
            if (distance_sum < min_distance) {
                min_distance = distance_sum;
                min_index = j;
            }
        }
        assignments[i] = min_index;
    }
    
    // set cluster sizes to 0 and new centers to 0
    for (i = 0; i < CLUSTERS; i++) {
        cluster_sizes[i] = 0;
        for (j = 0; j < ATTRIBUTES; j++) {
            new_centers[i][j] = 0;
        }
    }
    
    // calculate new centers by averaging all data points in each cluster
    for (i = 0; i < DATA_POINTS; i++) {
        cluster_sizes[assignments[i]]++;
        for (j = 0; j < ATTRIBUTES; j++) {
            new_centers[assignments[i]][j] += data[i][j];
        }
    }
    for (i = 0; i < CLUSTERS; i++) {
        if (cluster_sizes[i] > 0) {
            for (j = 0; j < ATTRIBUTES; j++) {
                new_centers[i][j] /= cluster_sizes[i];
            }
        }
    }
    
    // update centers and repeat until convergence or max iterations
    for (i = 0; i < CLUSTERS; i++) {
        for (j = 0; j < ATTRIBUTES; j++) {
            centers[i][j] = new_centers[i][j];
        }
    }
}

int main() {
    int i, j, iteration;
    double data[DATA_POINTS][ATTRIBUTES];
    double centers[CLUSTERS][ATTRIBUTES];
    int assignments[DATA_POINTS];
    
    srand(time(NULL));
    
    // generate random data points
    for (i = 0; i < DATA_POINTS; i++) {
        for (j = 0; j < ATTRIBUTES; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // initialize random centroids
    for (i = 0; i < CLUSTERS; i++) {
        for (j = 0; j < ATTRIBUTES; j++) {
            centers[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // run k-means clustering algorithm
    iteration = 0;
    while (iteration < MAX_ITERATIONS) {
        k_means_clustering(data, centers, assignments);
        iteration++;
    }
    
    // print cluster assignments
    for (i = 0; i < DATA_POINTS; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");
    
    return 0;
}