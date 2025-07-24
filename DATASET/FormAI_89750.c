//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100 // Max number of datapoints
#define D 2   // Number of dimensions

typedef struct {
    double x[D];
    int cluster;
} DataPoint;

typedef struct {
    double center[D];
    int size;
} Cluster;

int main(void) {
    DataPoint data[N];
    Cluster clusters[N];
    int k;

    // Randomly generate datapoints
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            data[i].x[j] = (double)rand() / RAND_MAX;
        }
        data[i].cluster = -1;
    }

    printf("Enter number of desired clusters (1 to 10): ");
    scanf("%d", &k);

    // Initialize clusters with random centers
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < D; j++) {
            clusters[i].center[j] = (double)rand() / RAND_MAX;
        }
        clusters[i].size = 0;
    }

    int changed = 1;
    while (changed) {
        // Reset cluster sizes and assignment flag
        for (int i = 0; i < k; i++) {
            clusters[i].size = 0;
        }
        changed = 0;

        // Assign each datapoint to closest cluster
        for (int i = 0; i < N; i++) {
            int best_cluster = -1;
            double best_distance = INFINITY;
            for (int j = 0; j < k; j++) {
                double distance = 0;
                for (int l = 0; l < D; l++) {
                    distance += (data[i].x[l] - clusters[j].center[l]) * (data[i].x[l] - clusters[j].center[l]);
                }
                if (distance < best_distance) {
                    best_cluster = j;
                    best_distance = distance;
                }
            }
            if (data[i].cluster != best_cluster) {
                data[i].cluster = best_cluster;
                changed = 1;
            }
            clusters[best_cluster].size++;
        }

        // Update cluster centers
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < D; j++) {
                clusters[i].center[j] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < D; j++) {
                clusters[data[i].cluster].center[j] += data[i].x[j];
            }
        }
        for (int i = 0; i < k; i++) {
            if (clusters[i].size > 0) {
                for (int j = 0; j < D; j++) {
                    clusters[i].center[j] /= clusters[i].size;
                }
            }
        }
    }

    // Print results
    printf("Result:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        printf("Center: ");
        for (int j = 0; j < D; j++) {
            printf("%.2f ", clusters[i].center[j]);
        }
        printf("\n");
        printf("Size: %d\n", clusters[i].size);
    }

    return 0;
}