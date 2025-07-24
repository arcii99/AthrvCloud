//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate Euclidean distance between two points.
double euclidean_distance(double *point1, double *point2, int n) {
    double sum = 0.0;
    for (int i=0; i<n; i++) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

int main() {
    int n_samples = 5;        // Number of samples
    int n_features = 2;       // Number of features per sample
    
    // Creating a sample dataset for clustering.
    double samples[5][2] = {{2.0, 10.0}, {2.0, 5.0}, {8.0, 4.0}, {5.0, 8.0}, {7.0, 5.0}};

    // Initializing variables for the K-Means algorithm.
    int n_clusters = 2;                  // Number of clusters
    double min_distance = INFINITY;      // Intializing the minimum distance using infinity.
    double centroids[2][2] = {{2.0, 10.0}, {5.0, 8.0}};    // Intializing the centroids for the clusters.

    // Applying the K-Means algorithm to cluster the samples.
    for (int i=0; i<n_samples; i++) {
        // Calculating the distance between the sample and the centroids.
        for (int j=0; j<n_clusters; j++) {
            double distance = euclidean_distance(samples[i], centroids[j], n_features);
            if (distance < min_distance) {
                min_distance = distance;
                samples[i][2] = j;      // Assigning the sample to the nearest cluster.
            }
        }
        min_distance = INFINITY;
    }

    // Updating the centroids based on the new assignments of samples.
    double mean[2] = {0.0};
    double n_samples_per_cluster[2] = {0.0};
    for (int i=0; i<n_samples; i++) {
        int cluster = (int) samples[i][2];
        n_samples_per_cluster[cluster] += 1;
        for (int j=0; j<n_features; j++) {
            mean[j] += samples[i][j];
        }
    }

    for (int i=0; i<n_clusters; i++) {
        for (int j=0; j<n_features; j++) {
            centroids[i][j] = mean[j] / n_samples_per_cluster[i];
        }
    }

    // Printing the samples and their assigned clusters.
    printf("Sample\tCluster\n");
    for (int i=0; i<n_samples; i++) {
        printf("%.2f\t%.0f\n", samples[i][0], samples[i][2]);
    }

    return 0;
}