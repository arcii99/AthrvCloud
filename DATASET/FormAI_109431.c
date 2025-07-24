//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define K 3 // number of clusters
#define N 100 // number of data points
#define D 2 // dimension of data points

struct Point {
    float x[D];
    int cluster;
};

struct Cluster {
    float centroid[D];
    int size;
    struct Point *points[N];
};

float Distance(struct Point *p1, struct Point *p2) {
    float sum = 0;
    for (int i = 0; i < D; i++) {
        sum += (p1->x[i] - p2->x[i]) * (p1->x[i] - p2->x[i]);
    }
    return sqrt(sum);
}

void KMeans(struct Point *data, struct Cluster *clusters) {
    // initialize centroids
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < D; i++) {
            clusters[k].centroid[i] = data[rand() % N].x[i];
        }
        clusters[k].size = 0;
    }

    // assign each data point to the nearest cluster
    for (int i = 0; i < N; i++) {
        float min_dist = Distance(data + i, &(clusters[0].centroid));
        int min_idx = 0;
        for (int k = 1; k < K; k++) {
            float dist = Distance(data + i, &(clusters[k].centroid));
            if (dist < min_dist) {
                min_dist = dist;
                min_idx = k;
            }
        }
        data[i].cluster = min_idx;
        clusters[min_idx].points[clusters[min_idx].size++] = data + i;
    }

    // re-calculate centroids
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < D; i++) {
            float sum = 0;
            for (int j = 0; j < clusters[k].size; j++) {
                sum += clusters[k].points[j]->x[i];
            }
            clusters[k].centroid[i] = sum / clusters[k].size;
        }
    }
}

int main() {
    struct Point data[N];
    struct Cluster clusters[K];

    // generate random data points
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            data[i].x[j] = (float) rand() / RAND_MAX * 10;
        }
    }

    // run K-means algorithm
    for (int i = 0; i < 10; i++) {
        KMeans(data, clusters);
    }

    // print results
    for (int k = 0; k < K; k++) {
        printf("Cluster %d:\n", k);
        for (int j = 0; j < clusters[k].size; j++) {
            printf("  Point %d: (%f, %f)\n", j, clusters[k].points[j]->x[0], clusters[k].points[j]->x[1]);
        }
    }

    return 0;
}