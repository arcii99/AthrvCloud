//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Number of data points
#define N 10

// Maximum number of clusters
#define K 3

// The dimensions of the data points
#define D 2

// Maximum number of iterations
#define MAX_ITER 100

// A point in D dimensions
typedef struct {
    double coords[D];
} Point;

// A cluster of points
typedef struct {
    int id;
    Point centroid;
    int num_points;
    Point points[N];
} Cluster;

// A dataset of N points
typedef struct {
    int num_points;
    Point points[N];
} Dataset;

// Get the Euclidean distance between two points
double distance(Point p1, Point p2) {
    double sum = 0;
    for (int i = 0; i < D; i++) {
        sum += pow(p1.coords[i] - p2.coords[i], 2);
    }
    return sqrt(sum);
}

// Given a dataset and the current centroids, assign each point to a cluster
void assign_points(Dataset* dataset, Cluster* clusters, int k) {
    // For each point in the dataset
    for (int i = 0; i < dataset->num_points; i++) {
        Point p = dataset->points[i];
        int closest_cluster = 0;
        double min_distance = distance(p, clusters[0].centroid);
        for (int j = 1; j < k; j++) {
            double dist = distance(p, clusters[j].centroid);
            if (dist < min_distance) {
                closest_cluster = j;
                min_distance = dist;
            }
        }
        clusters[closest_cluster].points[clusters[closest_cluster].num_points++] = p;
    }
}

// Given a cluster, recompute its centroid
void update_centroid(Cluster* cluster) {
    Point sum = { 0 };
    for (int i = 0; i < cluster->num_points; i++) {
        Point p = cluster->points[i];
        for (int j = 0; j < D; j++) {
            sum.coords[j] += p.coords[j];
        }
    }
    for (int i = 0; i < D; i++) {
        cluster->centroid.coords[i] = sum.coords[i] / cluster->num_points;
    }
}

// Given all the clusters, recompute the centroids of each
void update_centroids(Cluster* clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].num_points > 0) {
            update_centroid(&clusters[i]);
        }
    }
}

// Initialize the centroids of the clusters randomly
void initialize_clusters(Dataset* dataset, Cluster* clusters, int k) {
    for (int i = 0; i < k; i++) {
        int index = rand() % dataset->num_points;
        clusters[i].centroid = dataset->points[index];
        clusters[i].id = i;
    }
}

// Given a dataset and the current clusters, compute the total within-cluster sum of squares
double compute_total_wcss(Dataset* dataset, Cluster* clusters, int k) {
    double total_wcss = 0;
    for (int i = 0; i < k; i++) {
        Cluster c = clusters[i];
        for (int j = 0; j < c.num_points; j++) {
            Point p = c.points[j];
            total_wcss += pow(distance(p, c.centroid), 2);
        }
    }
    return total_wcss;
}

// Print all the points in a dataset
void print_dataset(Dataset* dataset) {
    for (int i = 0; i < dataset->num_points; i++) {
        printf("(");
        for (int j = 0; j < D; j++) {
            printf("%0.1f", dataset->points[i].coords[j]);
            if (j < D - 1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
}

// Print all the clusters and their points
void print_clusters(Cluster* clusters, int k) {
    for (int i = 0; i < k; i++) {
        Cluster c = clusters[i];
        printf("Cluster %d:\n", c.id);
        printf("Centroid: (");
        for (int j = 0; j < D; j++) {
            printf("%0.1f", c.centroid.coords[j]);
            if (j < D - 1) {
                printf(", ");
            }
        }
        printf(")\n");
        printf("Points: \n");
        for (int j = 0; j < c.num_points; j++) {
            printf("(");
            for (int l = 0; l < D; l++) {
                printf("%0.1f", c.points[j].coords[l]);
                if (l < D - 1) {
                    printf(", ");
                }
            }
            printf(")\n");
        }
    }
}

int main() {
    Dataset dataset;
    Cluster clusters[K];

    // Initialize the dataset
    dataset.num_points = N;
    dataset.points[0] = (Point) { .coords = { 1, 2 } };
    dataset.points[1] = (Point) { .coords = { 2, 3 } };
    dataset.points[2] = (Point) { .coords = { 10, 11 } };
    dataset.points[3] = (Point) { .coords = { 11, 11 } };
    dataset.points[4] = (Point) { .coords = { 12, 11 } };
    dataset.points[5] = (Point) { .coords = { 10, 12 } };
    dataset.points[6] = (Point) { .coords = { 15, 16 } };
    dataset.points[7] = (Point) { .coords = { 16, 18 } };
    dataset.points[8] = (Point) { .coords = { 17, 18 } };
    dataset.points[9] = (Point) { .coords = { 20, 20 } };

    // Print the dataset
    printf("Dataset:\n");
    print_dataset(&dataset);

    // Initialize the clusters randomly
    initialize_clusters(&dataset, clusters, K);

    // Assign each point to a cluster
    assign_points(&dataset, clusters, K);

    // Print the initial clusters
    printf("Initial clusters:\n");
    print_clusters(clusters, K);

    // Run the main clustering loop
    for (int i = 0; i < MAX_ITER; i++) {
        double old_wcss = compute_total_wcss(&dataset, clusters, K);
        update_centroids(clusters, K);
        for (int j = 0; j < K; j++) {
            clusters[j].num_points = 0;
        }
        assign_points(&dataset, clusters, K);
        double new_wcss = compute_total_wcss(&dataset, clusters, K);
        if (new_wcss >= old_wcss) {
            break;
        }
    }

    // Print the final clusters
    printf("Final clusters:\n");
    print_clusters(clusters, K);

    return 0;
}