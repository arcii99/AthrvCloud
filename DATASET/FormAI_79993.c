//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define K 2 // Number of clusters
#define N 15 // Number of data points 
#define MAX_ITER 100 // Max iterations

double distance(double a[], double b[]) { // Euclidean distance function
    double dist = 0;
    for(int i=0; i<K; i++) {
        dist += pow((a[i]-b[i]), 2);
    }
    return sqrt(dist);
}

int main() {
    double data[N][K] = {{1, 1}, {1, 2}, {2, 1}, {2, 2}, {3, 1}, {3, 2},
                        {6, 5}, {6, 6}, {7, 5}, {7, 6}, {8, 5}, {8, 6},
                        {12, 10}, {12, 11}, {13, 10}}; // Data points
    double centroids[K][N] = {{2, 2}, {8, 5}}; // Initial centroids
    int cluster[N]; // Cluster array
    int iter = 0;
    double error = 1;

    while(iter < MAX_ITER && error > 0.001) { // Loop until convergence
        error = 0;
        for(int i=0; i<N; i++) {
            double min_dist = 1000;
            int min_centroid = 0;
            for(int j=0; j<K; j++) {
                double dist = distance(data[i], centroids[j]);
                if(dist < min_dist) {
                    min_dist = dist;
                    min_centroid = j;
                }
            }
            if(cluster[i] != min_centroid) {
                error += 1;
            }
            cluster[i] = min_centroid;
        }
        for(int j=0; j<K; j++) {
            double sum[K] = {0};
            int count = 0;
            for(int i=0; i<N; i++) {
                if(cluster[i] == j) {
                    for(int k=0; k<K; k++) {
                        sum[k] += data[i][k];
                    }
                    count++;
                }
            }
            for(int k=0; k<K; k++) {
                if(count != 0) {
                    centroids[j][k] = sum[k]/count;
                }
            }
        }
        iter++;
    }
    for(int i=0; i<N; i++) { // Print final clusters
        printf("Data point (%.1f, %.1f) belongs to cluster %d\n", data[i][0], data[i][1], cluster[i]+1);
    }
    return 0;
}