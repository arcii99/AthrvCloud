//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000     // number of data points
#define K 3        // number of clusters
#define D 2        // number of features (dimensions)
#define MAX_ITER 1000

double data[N][D];      // data matrix
double centroids[K][D]; // centroid matrix
int assignments[N];     // cluster assignment for each data point

// function to initialize centroids randomly
void initialize_centroids() {
    for(int i=0; i<K; i++) {
        for(int j=0; j<D; j++) {
            centroids[i][j] = (double)rand() / RAND_MAX;     // random number between 0 and 1
        }
    }
}

// function to compute Euclidean distance between two data points
double distance(double* a, double* b) {
    double d = 0;
    for(int i=0; i<D; i++) {
        d += pow(a[i]-b[i], 2);
    }
    return sqrt(d);
}

// function to assign each data point to the closest centroid
void assign_to_clusters() {
    for(int i=0; i<N; i++) {
        double min_dist = INFINITY;
        int min_idx = 0;
        for(int j=0; j<K; j++) {
            double d = distance(data[i], centroids[j]);
            if(d < min_dist) {
                min_dist = d;
                min_idx = j;
            }
        }
        assignments[i] = min_idx;
    }
}

// function to update the centroids based on the current assignment of data points
void update_centroids() {
    double sum[K][D];
    int counts[K] = {0};
    
    // initialize sums to zero
    for(int i=0; i<K; i++) {
        for(int j=0; j<D; j++) {
            sum[i][j] = 0;
        }
    }
    
    // accumulate the values
    for(int i=0; i<N; i++) {
        int k = assignments[i];
        for(int j=0; j<D; j++) {
            sum[k][j] += data[i][j];
        }
        counts[k]++;
    }
    
    // compute the new centroids
    for(int i=0; i<K; i++) {
        for(int j=0; j<D; j++) {
            centroids[i][j] = counts[i] > 0 ? sum[i][j] / counts[i] : centroids[i][j];
        }
    }
}

int main() {
    // generate random data points
    for(int i=0; i<N; i++) {
        for(int j=0; j<D; j++) {
            data[i][j] = (double)rand() / RAND_MAX;
        }
    }
    
    // initialize centroids randomly
    initialize_centroids();
    
    // run K-Means algorithm
    for(int i=0; i<MAX_ITER; i++) {
        assign_to_clusters();
        update_centroids();
    }
    
    // print final assignments
    printf("Final cluster assignments:\n");
    for(int i=0; i<N; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");
    
    return 0;
}