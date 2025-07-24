//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define POINTS 10       // Number of points to be generated
#define FEATURES 3      // Number of features per point
#define CLUSTERS 2      // Number of clusters to be formed
#define MAX_ITER 100    // Maximum number of iterations

// Structure to define a data point
struct Point {
    float features[FEATURES];
    int cluster;
};

// Function to generate random data points
void generate_random_points(struct Point p[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<FEATURES; j++) {
            p[i].features[j] = (float)rand() / RAND_MAX; // Range [0,1]
        }
    }
}

// Function to initialize cluster centers
void initialize_centers(struct Point p[], struct Point centers[], int n) {
    // Randomly select initial centers from data points
    for(int i=0; i<CLUSTERS; i++) {
        int index = rand() % n;
        for(int j=0; j<FEATURES; j++) {
            centers[i].features[j] = p[index].features[j];
        }
    }
}

// Function to calculate distance between two points
float calculate_distance(struct Point p1, struct Point p2) {
    float sum = 0.0;
    for(int i=0; i<FEATURES; i++) {
        sum += pow(p1.features[i] - p2.features[i], 2);
    }
    return sqrt(sum);
}

// Function to assign points to clusters
void assign_to_clusters(struct Point p[], struct Point centers[], int n) {
    for(int i=0; i<n; i++) {
        float min_distance = INFINITY;
        for(int j=0; j<CLUSTERS; j++) {
            float distance = calculate_distance(p[i], centers[j]);
            if(distance < min_distance) {
                min_distance = distance;
                p[i].cluster = j;
            }
        }
    }
}

// Function to recalculate cluster centers
void recalculate_centers(struct Point p[], struct Point centers[], int n) {
    float sum[CLUSTERS][FEATURES];
    int count[CLUSTERS] = {0};
    // Initialize sums to 0
    for(int i=0; i<CLUSTERS; i++) {
        for(int j=0; j<FEATURES; j++) {
            sum[i][j] = 0.0;
        }
    }
    // Calculate sum and count for each cluster
    for(int i=0; i<n; i++) {
        for(int j=0; j<FEATURES; j++) {
            sum[p[i].cluster][j] += p[i].features[j];
        }
        count[p[i].cluster]++;
    }
    // Calculate new cluster centers
    for(int i=0; i<CLUSTERS; i++) {
        for(int j=0; j<FEATURES; j++) {
            if(count[i] != 0) {
                centers[i].features[j] = sum[i][j] / count[i];
            }
        }
    }
}

// Function to check if clusters have converged
int converged(struct Point centers_old[], struct Point centers_new[]) {
    for(int i=0; i<CLUSTERS; i++) {
        if(calculate_distance(centers_old[i], centers_new[i]) > 0.0001) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // Seed the random number generator
    srand(0);
    // Allocate memory for data points and cluster centers
    struct Point p[POINTS];
    struct Point centers[CLUSTERS];
    // Generate random data points
    generate_random_points(p, POINTS);
    // Initialize cluster centers
    initialize_centers(p, centers, POINTS);
    // Perform clustering
    int iterations = 0;
    while(iterations < MAX_ITER) {
        struct Point centers_old[CLUSTERS];
        for(int i=0; i<CLUSTERS; i++) {
            centers_old[i] = centers[i];
        }
        assign_to_clusters(p, centers, POINTS);
        recalculate_centers(p, centers, POINTS);
        if(converged(centers_old, centers)) {
            break; // Clusters have converged
        }
        iterations++;
    }
    // Print results
    printf("Clusters after %d iterations:\n", iterations);
    for(int i=0; i<CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for(int j=0; j<POINTS; j++) {
            if(p[j].cluster == i) {
                for(int k=0; k<FEATURES; k++) {
                    printf("%f ", p[j].features[k]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}