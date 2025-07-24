//FormAI DATASET v1.0 Category: Data mining ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function to generate a random number between two given values */
int rand_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Function to calculate the distance between two points in n-dimensional space */
double distance(double *p1, double *p2, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    }
    return sqrt(sum);
}

/* Main function to perform k-means clustering */
int main() {
    /* Initialize variables */
    int k = 3;
    int n = 8;
    double data[8][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}, {19, 20, 21}, {22, 23, 24}};
    double centroids[3][3] = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
    int cluster_assignments[8];

    /* Perform k-means clustering */
    int iterations = 0;
    while (iterations < 100) {

        /* Assign each data point to the nearest centroid */
        for (int i = 0; i < n; i++) {
            double min_distance = INFINITY;
            int min_index = -1;
            for (int j = 0; j < k; j++) {
                double d = distance(data[i], centroids[j], 3);
                if (d < min_distance) {
                    min_distance = d;
                    min_index = j;
                }
            }
            cluster_assignments[i] = min_index;
        }

        /* Update the centroids as the mean of the data points assigned to each cluster */
        for (int j = 0; j < k; j++) {
            int count = 0;
            double sum[3] = {0.0, 0.0, 0.0};
            for (int i = 0; i < n; i++) {
                if (cluster_assignments[i] == j) {
                    count++;
                    sum[0] += data[i][0];
                    sum[1] += data[i][1];
                    sum[2] += data[i][2];
                }
            }
            if (count > 0) {
                centroids[j][0] = sum[0] / count;
                centroids[j][1] = sum[1] / count;
                centroids[j][2] = sum[2] / count;
            } else {
                centroids[j][0] = rand_int(0, 24);
                centroids[j][1] = rand_int(0, 24);
                centroids[j][2] = rand_int(0, 24);
            }
        }

        /* Increment the iteration counter */
        iterations++;
    }

    /* Print the final cluster assignments and centroids */
    printf("Final cluster assignments:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", cluster_assignments[i]);
    }
    printf("\n\nFinal centroids:\n");
    for (int j = 0; j < k; j++) {
        printf("(%f, %f, %f) ", centroids[j][0], centroids[j][1], centroids[j][2]);
    }

    return 0;
}