//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euclidean_distance(double* a, double* b, int dims) {
    double distance = 0;
    for (int i = 0; i < dims; i++) {
        distance += pow((a[i] - b[i]), 2);
    }
    return sqrt(distance);
}

int main() {
    // Initialize data points
    double data[][2] = { {1, 2.5}, {3.5, 4}, {6, 8}, {10, 12}, {13, 15}, {2, 3} };
    int num_points = sizeof(data) / sizeof(data[0]);

    // Initialize cluster centers
    double centers[][2] = { {1, 2}, {4, 4}, {10, 10} };
    int num_centers = sizeof(centers) / sizeof(centers[0]);

    // Setup cluster assignments
    int assignments[num_points];

    // Iterate through clustering assignments
    for (;;) {
        // Reset assignments
        int changed = 0;
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int cluster_index = 0;

            // Find the closest center
            for (int j = 0; j < num_centers; j++) {
                double distance = euclidean_distance(data[i], centers[j], 2);

                if (distance < min_distance) {
                    min_distance = distance;
                    cluster_index = j;
                }
            }

            // Update cluster assignment
            if (assignments[i] != cluster_index) {
                assignments[i] = cluster_index;
                changed = 1;
            }
        }

        // Exit if no changes were made
        if (!changed) {
            break;
        }

        // Update cluster centers
        for (int i = 0; i < num_centers; i++) {
            double sum_x = 0, sum_y = 0, count = 0;

            for (int j = 0; j < num_points; j++) {
                if (assignments[j] == i) {
                    sum_x += data[j][0];
                    sum_y += data[j][1];
                    count++;
                }
            }

            if (count != 0) {
                centers[i][0] = sum_x / count;
                centers[i][1] = sum_y / count;
            }
        }
    }

    // Print final cluster assignments
    printf("Final cluster assignments:\n");
    for (int i = 0; i < num_points; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");

    return 0;
}