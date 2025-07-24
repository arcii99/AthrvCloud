//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4
#define K 2
#define MAX_ITERATIONS 100

/* Define a struct for a point in N-dimensional space */
typedef struct _point {
    double coord[N];
} Point;

/* Define a struct for a cluster */
typedef struct _cluster {
    int num_points;
    Point centroid;
    Point* points;
} Cluster;

/* Define a function to calculate the Euclidean distance between two points */
double euclidean_distance(Point p1, Point p2) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += pow((p1.coord[i] - p2.coord[i]), 2);
    }
    return sqrt(sum);
}

/* Define a function to randomly initialize the centroids of the clusters */
void init_centroids(Point* points, Cluster* clusters) {
    for (int i = 0; i < K; i++) {
        clusters[i].num_points = 0;
        for (int j = 0; j < N; j++) {
            clusters[i].centroid.coord[j] = (double)rand() / (double)RAND_MAX;
        }
    }
}

/* Define a function to assign points to the nearest cluster */
void assign_clusters(Point* points, Cluster* clusters) {
    for (int i = 0; i < K; i++) {
        clusters[i].num_points = 0;
    }
    for (int i = 0; i < N; i++) {
        double min_dist = INFINITY;
        int min_index = 0;
        for (int j = 0; j < K; j++) {
            double dist = euclidean_distance(points[i], clusters[j].centroid);
            if (dist < min_dist) {
                min_dist = dist;
                min_index = j;
            }
        }
        clusters[min_index].points[clusters[min_index].num_points] = points[i];
        clusters[min_index].num_points++;
    }
}

/* Define a function to recalculate the centroid of a cluster */
void recalculate_centroid(Cluster* cluster) {
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < cluster->num_points; j++) {
            sum += cluster->points[j].coord[i];
        }
        cluster->centroid.coord[i] = sum / (double)cluster->num_points;
    }
}

/* Define the main function */
int main() {
    Point points[N] = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 8.0},
        {9.0, 10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0, 16.0}
    };

    Cluster clusters[K] = {
        {0, {0}},
        {0, {0}}
    };

    init_centroids(points, clusters);

    int num_iterations = 0;
    while (num_iterations < MAX_ITERATIONS) {
        assign_clusters(points, clusters);
        for (int i = 0; i < K; i++) {
            recalculate_centroid(&clusters[i]);
        }
        num_iterations++;
    }

    printf("Final centroids:\n");
    for (int i = 0; i < K; i++) {
        printf("Cluster %d centroid: (", i);
        for (int j = 0; j < N; j++) {
            printf("%.2f", clusters[i].centroid.coord[j]);
            if (j < N-1) {
                printf(", ");
            }
        }
        printf(")\n");
    }

    return 0;
}