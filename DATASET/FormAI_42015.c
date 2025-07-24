//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define K 3 // number of clusters to be formed
#define N 50 // number of data points to be generated
#define MAX_ITER 100 // maximum number of iterations to be performed

struct Point {
    double x;
    double y;
};

double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void kmeans_clustering(struct Point data[], int clusters[], int n) {
    struct Point means[K];
    int i, j, k, iter, minCluster;
    double minDistance, distanceFromMean;

    // initialize means with random data points
    srand(time(NULL));
    for (i = 0; i < K; i++) {
        int randomIndex = rand() % n;
        means[i] = data[randomIndex];
    }

    for (iter = 0; iter < MAX_ITER; iter++) {
        // assign each data point to the closest mean (cluster)
        for (i = 0; i < n; i++) {
            minCluster = 0;
            minDistance = distance(data[i], means[0]);
            for (j = 1; j < K; j++) {
                distanceFromMean = distance(data[i], means[j]);
                if (distanceFromMean < minDistance) {
                    minCluster = j;
                    minDistance = distanceFromMean;
                }
            }
            clusters[i] = minCluster;
        }

        // calculate new means
        for (i = 0; i < K; i++) {
            int clusterSize = 0;
            double sumX = 0, sumY = 0;
            for (j = 0; j < n; j++) {
                if (clusters[j] == i) {
                    sumX += data[j].x;
                    sumY += data[j].y;
                    clusterSize++;
                }
            }
            if (clusterSize > 0) {
                means[i].x = sumX / clusterSize;
                means[i].y = sumY / clusterSize;
            }
        }
    }
}

int main() {
    struct Point data[N];
    int clusters[N];
    int i;

    // generate random data points
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        data[i].x = (double)(rand() % 1000) / 1000;
        data[i].y = (double)(rand() % 1000) / 1000;
    }

    // perform k-means clustering
    kmeans_clustering(data, clusters, N);

    // print results
    for (i = 0; i < N; i++) {
       printf("Data Point %d : (%f, %f)  - Cluster %d\n", i+1, data[i].x, data[i].y, clusters[i]+1);
    }

    return 0;
}