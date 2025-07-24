//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

struct point {
    double x, y;
};

struct cluster {
    struct point centroid;
    int size;
    struct point points[MAX_POINTS];
};

int main() {

    int k = 3; // number of clusters
    struct point data[] = {{1,2}, {2,3}, {5,4}, {7,6}, {9,7}, {10,15}, {12,17}, {16,15}, {18,19}, {20,21}}; // sample data
    int n = sizeof(data) / sizeof(struct point); // number of data points
    struct cluster clusters[k]; // clusters

    // selecting initial centroids at random
    for(int i=0; i<k; i++) {
        int rand_idx = rand() % n;
        clusters[i].centroid.x = data[rand_idx].x;
        clusters[i].centroid.y = data[rand_idx].y;
    }

    int iters = 10; // number of iterations
    while(iters--) {

        // assign each data point to the nearest centroid
        for(int i=0; i<n; i++) {

            // calculating distances to each centroid
            double min_dist = INFINITY;
            int cluster_id = 0;
            for(int j=0; j<k; j++) {
                double dist = sqrt(pow(data[i].x - clusters[j].centroid.x, 2) + pow(data[i].y - clusters[j].centroid.y, 2));
                if(dist < min_dist) {
                    min_dist = dist;
                    cluster_id = j;
                }
            }

            // adding the data point to the corresponding cluster
            clusters[cluster_id].points[clusters[cluster_id].size++] = data[i];
        }

        // recalculating centroids
        for(int i=0; i<k; i++) {
            double sum_x = 0.0, sum_y = 0.0;
            for(int j=0; j<clusters[i].size; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].size;
            clusters[i].centroid.y = sum_y / clusters[i].size;
        }

        // clearing data points from each cluster
        for(int i=0; i<k; i++) {
            clusters[i].size = 0;
        }
    }

    // printing the final clusters and their centroids
    for(int i=0; i<k; i++) {
        printf("Cluster %d centroid: (%.2f, %.2f) points: [", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
        for(int j=0; j<clusters[i].size; j++) {
            printf("(%.2f, %.2f)", clusters[i].points[j].x, clusters[i].points[j].y);
            if(j < clusters[i].size-1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    return 0;
}