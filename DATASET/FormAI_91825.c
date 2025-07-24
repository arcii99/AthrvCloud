//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3      // Number of clusters
#define N 10     // Number of data points
#define DIM 2    // Number of dimensions

double data[N][DIM] = {{2,3},{5,4},{1,2},{3,5},{4,5},
                       {7,6},{8,8},{9,8},{8,9},{9,10}};   // Data points

double centers[K][DIM];
double distances[K];
int clusters[N];

// Function to calculate distance between two points
double dist(double *p1, double *p2) {
    double d = 0;
    for(int i=0; i<DIM; i++) {
        d += pow(p1[i] - p2[i], 2);
    }
    return sqrt(d);
}

// Function to initialize cluster centers
void init_centers() {
    for(int i=0; i<K; i++) {
        for(int j=0; j<DIM; j++) {
            centers[i][j] = data[i][j];
        }
    }
}

// Function to assign each data point to a cluster
void assign_clusters() {
    for(int i=0; i<N; i++) {
        double min_dist = INFINITY;
        int min_index = -1;
        for(int j=0; j<K; j++) {
            distances[j] = dist(data[i], centers[j]);
            if(distances[j] < min_dist) {
                min_dist = distances[j];
                min_index = j;
            }
        }
        clusters[i] = min_index;
    }
}

// Function to recompute cluster centers
void recompute_centers() {
    for(int i=0; i<K; i++) {
        int count = 0;
        for(int j=0; j<N; j++) {
            if(clusters[j] == i) {
                count++;
                for(int k=0; k<DIM; k++) {
                    centers[i][k] += data[j][k];
                }
            }
        }
        if(count > 0) {
            for(int k=0; k<DIM; k++) {
                centers[i][k] /= count;
            }
        }
    }
}

// Function to print cluster data
void print_clusters() {
    for(int i=0; i<K; i++) {
        printf("Cluster %d:\n", i);
        for(int j=0; j<N; j++) {
            if(clusters[j] == i) {
                printf("(%lf, %lf)\n", data[j][0], data[j][1]);
            }
        }
        printf("Center: (%lf, %lf)\n", centers[i][0], centers[i][1]);
    }
}

// Main function
int main() {
    init_centers();
    for(int i=0; i<5; i++) {
        printf("Iteration %d:\n", i+1);
        assign_clusters();
        recompute_centers();
        print_clusters();
        printf("\n");
    }
    return 0;
}