//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define K 5

/* Function to calculate Euclidean distance */
double euclidean_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
}

/* Function to initialize centroids */
void init_centroids(double *centroids_x, double *centroids_y, double *data_x, double *data_y) {
    int i;
    for(i=0; i<K; i++) {
        centroids_x[i] = data_x[i];
        centroids_y[i] = data_y[i];
    }
}

/* Main function */
int main() {
    int i, j, k;
    double data_x[N], data_y[N];
    double centroids_x[K], centroids_y[K];
    int cluster_assignment[N];
    double distances[K];
    double min_distance;
    int min_index;

    /* Generate random data points */
    for(i=0; i<N; i++) {
        data_x[i] = ((double)rand()/(double)RAND_MAX) * 100.0;
        data_y[i] = ((double)rand()/(double)RAND_MAX) * 100.0;
    }

    /* Initialize centroids */
    init_centroids(centroids_x, centroids_y, data_x, data_y);

    /* Loop through each data point */
    for(i=0; i<N; i++) {
        /* Calculate distance to each centroid */
        for(j=0; j<K; j++) {
            distances[j] = euclidean_distance(data_x[i], data_y[i], centroids_x[j], centroids_y[j]);
        }

        /* Assign data point to closest centroid */
        min_distance = distances[0];
        min_index = 0;
        for(k=1; k<K; k++) {
            if(distances[k] < min_distance) {
                min_distance = distances[k];
                min_index = k;
            }
        }
        cluster_assignment[i] = min_index;
    }

    /* Print out cluster assignments */
    for(i=0; i<N; i++) {
        printf("Data point %d belongs to cluster %d\n", i, cluster_assignment[i]);
    }

    return 0;
}