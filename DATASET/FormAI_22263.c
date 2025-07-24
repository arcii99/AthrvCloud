//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2  // number of dimensions in the dataset
#define K 3  // number of clusters to form
#define MAX_ITERATIONS 100  // maximum number of iterations allowed for convergence
#define EPSILON 0.0001  // threshold for convergence

// define a struct for a 2-dimensional point
typedef struct {
    double x;
    double y;
} point_t;

// initialize the dataset
point_t dataset[] = {
    {1.0, 1.0},
    {1.5, 2.0},
    {3.0, 4.0},
    {5.0, 7.0},
    {3.5, 5.0},
    {4.5, 5.0},
    {3.5, 4.5},
    {4.5, 4.5},
    {6.5, 7.5},
    {7.0, 7.0},
    {7.5, 8.0},
    {8.0, 9.0},
    {8.5, 9.5},
    {9.0, 10.0},
    {9.5, 10.5},
    {10.0, 11.0},
};

// initialize the centroids
point_t centroids[K];

// compute the Euclidean distance between two points
double distance(point_t a, point_t b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// assign each point to the closest centroid
void assign_clusters(point_t dataset[], int clusters[], int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        for (int j = 0; j < K; j++) {
            double d = distance(dataset[i], centroids[j]);
            if (d < min_distance) {
                min_distance = d;
                clusters[i] = j;
            }
        }
    }
}

// update the centroids based on the assigned points
void update_centroids(point_t dataset[], int clusters[], int num_points) {
    for (int i = 0; i < K; i++) {
        int count = 0;
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < num_points; j++) {
            if (clusters[j] == i) {
                count++;
                sum_x += dataset[j].x;
                sum_y += dataset[j].y;
            }
        }
        centroids[i].x = sum_x / count;
        centroids[i].y = sum_y / count;
    }
}

// perform the clustering algorithm
void cluster_data(point_t dataset[], int num_points) {
    // initialize clusters randomly
    int clusters[num_points];
    for (int i = 0; i < num_points; i++) {
        clusters[i] = rand() % K;
    }

    // update centroids and reassign clusters until convergence or max iterations reached
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        update_centroids(dataset, clusters, num_points);
        int unchanged = 1;
        for (int j = 0; j < num_points; j++) {
            double d = distance(dataset[j], centroids[clusters[j]]);
            if (d > EPSILON) {
                assign_clusters(dataset, clusters, num_points);
                unchanged = 0;
                break;
            }
        }
        if (unchanged) {
            printf("Converged after %d iterations\n", i + 1);
            break;
        }
    }
}

// print the centroids and clusters
void print_clusters(point_t dataset[], int clusters[], int num_points) {
    for (int i = 0; i < K; i++) {
        printf("Centroid %d: (%lf, %lf)\n", i, centroids[i].x, centroids[i].y);
    }
    for (int i = 0; i < num_points; i++) {
        printf("Point (%lf, %lf) assigned to cluster %d\n", dataset[i].x, dataset[i].y, clusters[i]);
    }
}

int main() {
    int num_points = sizeof(dataset) / sizeof(point_t);
    cluster_data(dataset, num_points);
    int clusters[num_points];
    assign_clusters(dataset, clusters, num_points);
    print_clusters(dataset, clusters, num_points);
    return 0;
}