//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define DIMENSIONS 2
#define POINTS 100
#define CLUSTERS 5
#define MAX_ITERATIONS 10

// Return the Euclidean distance between two points
float euclidean_distance(float *point1, float *point2){
    float distance = 0;
    for (int i = 0; i < DIMENSIONS; i++){
        distance += pow(point1[i] - point2[i], 2);
    }
    return sqrt(distance);
}

int main(){
    float points[POINTS][DIMENSIONS];
    int cluster_assignments[POINTS] = {0};
    float cluster_centroids[CLUSTERS][DIMENSIONS];
    bool converged = false;
    int iterations = 0;

    // Generate random points
    for (int i = 0; i < POINTS; i++){
        for (int j = 0; j < DIMENSIONS; j++){
            points[i][j] = (float) rand() / RAND_MAX;
        }
    }

    // Initialize random centroids
    for (int i = 0; i < CLUSTERS; i++){
        for (int j = 0; j < DIMENSIONS; j++){
            cluster_centroids[i][j] = (float) rand() / RAND_MAX;
        }
    }

    while (!converged && iterations < MAX_ITERATIONS){
        converged = true;
        iterations++;

        // Assign points to closest centroid
        for (int i = 0; i < POINTS; i++){
            float min_distance = INFINITY;
            int min_cluster = 0;
            for (int j = 0; j < CLUSTERS; j++){
                float distance = euclidean_distance(points[i], cluster_centroids[j]);
                if (distance < min_distance){
                    min_distance = distance;
                    min_cluster = j;
                }
            }
            if (cluster_assignments[i] != min_cluster){
                converged = false;
                cluster_assignments[i] = min_cluster;
            }
        }

        // Recalculate centroids
        for (int i = 0; i < CLUSTERS; i++){
            float new_centroid[DIMENSIONS] = {0};
            int count = 0;
            for (int j = 0; j < POINTS; j++){
                if (cluster_assignments[j] == i){
                    for (int k = 0; k < DIMENSIONS; k++){
                        new_centroid[k] += points[j][k];
                    }
                    count++;
                }
            }
            if (count > 0){
                for (int k = 0; k < DIMENSIONS; k++){
                    new_centroid[k] /= count;
                }
                for (int k = 0; k < DIMENSIONS; k++){
                    if (cluster_centroids[i][k] != new_centroid[k]){
                        converged = false;
                    }
                    cluster_centroids[i][k] = new_centroid[k];
                }
            }
        }
    }

    // Print results
    for (int i = 0; i < POINTS; i++){
        printf("(%f, %f) -> Cluster %d\n", points[i][0], points[i][1], cluster_assignments[i]+1);
    }

    return 0;
}