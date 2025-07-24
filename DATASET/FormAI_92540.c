//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // number of data points
#define K 3  // number of clusters

// structure to represent a data point
struct Point {
    double x, y;
};

// global array to store data points
struct Point data[N];

// global array to store centroids
struct Point centroids[K];

double distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// function to assign each data point to a cluster
void assign_clusters(int cluster_ids[N]) {
    for (int i = 0; i < N; i++) {
        double min_dist = INFINITY;
        int cluster_id = -1;
        for (int j = 0; j < K; j++) {
            double d = distance(data[i], centroids[j]);
            if (d < min_dist) {
                min_dist = d;
                cluster_id = j;
            }
        }
        cluster_ids[i] = cluster_id;
    }
}

// function to update centroids based on assigned data points
void update_centroids(int cluster_ids[N]) {
    for (int i = 0; i < K; i++) {
        int count = 0;
        double sum_x = 0, sum_y = 0;
        for (int j = 0; j < N; j++) {
            if (cluster_ids[j] == i) {
                count++;
                sum_x += data[j].x;
                sum_y += data[j].y;
            }
        }
        if (count > 0) {
            centroids[i].x = sum_x / count;
            centroids[i].y = sum_y / count;
        }
    }
}

// function to print data points and their assigned cluster ids
void print_clusters(int cluster_ids[N]) {
    printf("Data points and their assigned cluster ids:\n");
    for (int i = 0; i < N; i++) {
        printf("(%.2f, %.2f) -> %d\n", data[i].x, data[i].y, cluster_ids[i]);
    }
}

int main() {
    // initialize data points
    data[0].x = 1.0; data[0].y = 2.0;
    data[1].x = 2.0; data[1].y = 1.0;
    data[2].x = 2.0; data[2].y = 2.0;
    data[3].x = 3.0; data[3].y = 1.0;
    data[4].x = 3.0; data[4].y = 2.0;
    data[5].x = 3.0; data[5].y = 3.0;
    data[6].x = 4.0; data[6].y = 1.0;
    data[7].x = 4.0; data[7].y = 2.0;
    data[8].x = 5.0; data[8].y = 2.0;
    data[9].x = 5.0; data[9].y = 3.0;

    // initialize centroids
    centroids[0].x = 1.0; centroids[0].y = 2.0;
    centroids[1].x = 3.0; centroids[1].y = 1.0;
    centroids[2].x = 4.0; centroids[2].y = 3.0;

    int cluster_ids[N];
    assign_clusters(cluster_ids);
    print_clusters(cluster_ids);

    update_centroids(cluster_ids);
    assign_clusters(cluster_ids);
    print_clusters(cluster_ids);

    update_centroids(cluster_ids);
    assign_clusters(cluster_ids);
    print_clusters(cluster_ids);

    return 0;
}