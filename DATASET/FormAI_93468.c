//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_POINTS 100
#define N_CLUSTERS 3
#define N_ITERATIONS 10

// Function to calculate Euclidean distance between two points
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    // Generate random data points with x and y coordinates
    double points[N_POINTS][2];
    for(int i = 0; i < N_POINTS; i++) {
        points[i][0] = (double)rand() / RAND_MAX * 100;
        points[i][1] = (double)rand() / RAND_MAX * 100;
    }

    // Initialize cluster centers
    double cluster_centers[N_CLUSTERS][2];
    for(int i = 0; i < N_CLUSTERS; i++) {
        int index = (int)rand() % N_POINTS;
        cluster_centers[i][0] = points[index][0];
        cluster_centers[i][1] = points[index][1];
    }

    // Loop over number of iterations
    for(int iteration = 0; iteration < N_ITERATIONS; iteration++) {
        // Initialize empty cluster arrays
        double clusters[N_CLUSTERS][N_POINTS][2];
        int indexes[N_CLUSTERS];
        for(int i = 0; i < N_CLUSTERS; i++) {
            indexes[i] = 0;
        }

        // Assign each point to the nearest cluster center
        for(int i = 0; i < N_POINTS; i++) {
            double min_distance = INFINITY;
            int cluster_index;
            for(int j = 0; j < N_CLUSTERS; j++) {
                double distance = euclidean_distance(points[i][0], points[i][1], 
                                                     cluster_centers[j][0], cluster_centers[j][1]);
                if(distance < min_distance) {
                    min_distance = distance;
                    cluster_index = j;
                }
            }
            clusters[cluster_index][indexes[cluster_index]][0] = points[i][0];
            clusters[cluster_index][indexes[cluster_index]][1] = points[i][1];
            indexes[cluster_index]++;
        }

        // Calculate new cluster centers as the mean of the points in each cluster
        for(int i = 0; i < N_CLUSTERS; i++) {
            double sum_x = 0;
            double sum_y = 0;
            for(int j = 0; j < indexes[i]; j++) {
                sum_x += clusters[i][j][0];
                sum_y += clusters[i][j][1];
            }
            cluster_centers[i][0] = sum_x / indexes[i];
            cluster_centers[i][1] = sum_y / indexes[i];
        }
    }

    // Print final cluster centers
    printf("Cluster centers:\n");
    for(int i = 0; i < N_CLUSTERS; i++) {
        printf("(%f, %f)\n", cluster_centers[i][0], cluster_centers[i][1]);
    }

    return 0;
}