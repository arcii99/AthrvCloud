//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 3

int random_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void k_means(int data[][2], int k, int labels[]) {
    int i, j, t, min_dist, cluster;
    int means[k][2], sums[k][2], counts[k];
    // Initialize means with random data points
    for (i = 0; i < k; i++) {
        means[i][0] = data[i][0];
        means[i][1] = data[i][1];
    }
    // Initialize sums and counts to 0 for each cluster
    for (i = 0; i < k; i++) {
        sums[i][0] = 0;
        sums[i][1] = 0;
        counts[i] = 0;
    }
    // Iterate until convergence
    for (t = 0; t < 100; t++) {
        // Assign each data point to a cluster based on the closest centroid
        for (i = 0; i < N; i++) {
            min_dist = distance(data[i][0], data[i][1], means[0][0], means[0][1]);
            cluster = 0;
            for (j = 1; j < k; j++) {
                if (distance(data[i][0], data[i][1], means[j][0], means[j][1]) < min_dist) {
                    min_dist = distance(data[i][0], data[i][1], means[j][0], means[j][1]);
                    cluster = j;
                }
            }
            labels[i] = cluster;
            sums[cluster][0] += data[i][0];
            sums[cluster][1] += data[i][1];
            counts[cluster]++;
        }
        // Update centroids
        for (i = 0; i < k; i++) {
            if (counts[i] == 0) {
                means[i][0] = random_num(0, 100);
                means[i][1] = random_num(0, 100);
            } else {
                means[i][0] = sums[i][0] / counts[i];
                means[i][1] = sums[i][1] / counts[i];
            }
        }
    }
}

int main() {
    int data[N][2] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6},
                      {7, 8}, {8, 9}, {9, 10}, {12, 13}, {13, 14}};
    int labels[N];
    k_means(data, K, labels);
    int i;
    for (i = 0; i < N; i++) {
        printf("(%d, %d) -> Cluster %d\n", data[i][0], data[i][1], labels[i]);
    }
    return 0;
}