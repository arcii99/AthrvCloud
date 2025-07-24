//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 100           // number of data points
#define DIMENSION 2     // Dimension of the vector space

double data_points[N][DIMENSION] = {{0.5, 0.6}, {0.3, 0.2}, {0.1, 0.3}, {0.3, 0.5}, {0.7, 0.8}, {0.5, 0.4}, {0.4, 0.6}, {0.6, 0.7}};

int main() {
    double clusters[N][DIMENSION] = {{0}};         // cluster centroids
    int cluster_assignments[N] = {0};             // array with index of cluster for each point
    int num_clusters = 0;                         // number of clusters found
    int change = 1;                               // flag for changes in cluster assignment
    double distance, min_distance;                // variables for calculating distance between points
    int i, j, k;                                   // loop control variables

    // assign the first data point to the first cluster
    for(i = 0; i < DIMENSION; i++) {
        clusters[0][i] = data_points[0][i];
    }

    // update cluster centroids until no further changes in cluster assignment occur
    while(change == 1) {
        // reset the flag for changes in cluster assignment
        change = 0;

        // iterate through all data points
        for(i = 0; i < N; i++) {
            // initialize minimum distance as distance to first cluster
            min_distance = 0;
            for(j = 0; j < DIMENSION; j++) {
                min_distance += pow(data_points[i][j] - clusters[0][j], 2);
            }
            // iterate through remaining clusters to find the closest one
            for(k = 1; k < num_clusters; k++) {
                distance = 0;
                for(j = 0; j < DIMENSION; j++) {
                    distance += pow(data_points[i][j] - clusters[k][j], 2);
                }
                if(distance < min_distance) {
                    // update minimum distance and cluster assignment
                    min_distance = distance;
                    cluster_assignments[i] = k;
                    change = 1;
                }
            }
            // if no closer cluster was found, keep current assignment
            if(cluster_assignments[i] == 0) {
                cluster_assignments[i] = num_clusters;
                num_clusters++;
                change = 1;
                for(j = 0; j < DIMENSION; j++) {
                    clusters[num_clusters][j] = data_points[i][j];
                }
            }
        }
        // recalculate the centroids for each cluster
        for(k = 0; k < num_clusters; k++) {
            int count = 0;
            for(j = 0; j < DIMENSION; j++) {
                clusters[k][j] = 0;
            }
            for(i = 0; i < N; i++) {
                if(cluster_assignments[i] == k) {
                    count++;
                    for(j = 0; j < DIMENSION; j++) {
                        clusters[k][j] += data_points[i][j];
                    }
                }
            }
            if(count != 0) {
                for(j = 0; j < DIMENSION; j++) {
                    clusters[k][j] /= count;
                }
            }
        }
    }
    // print the results
    printf("Number of clusters: %d\n", num_clusters);
    for(k = 0; k < num_clusters; k++) {
        printf("Cluster %d: ", k+1);
        for(j = 0; j < DIMENSION; j++) {
            printf("%.2f ", clusters[k][j]);
        }
        printf("\n");
    }
    return 0;
}