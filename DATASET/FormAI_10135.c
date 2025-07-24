//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 100

typedef struct point {
    double x, y;
} Point;

typedef struct cluster {
    Point centroid;
    int size;
    Point points[MAX_POINTS];
} Cluster;

typedef struct kmeans {
    int num_points, num_clusters, max_iterations;
    Point points[MAX_POINTS];
    Cluster clusters[MAX_CLUSTERS];
} KMeans;

double dist(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

void print_point(Point p) {
    printf("(%lf, %lf)", p.x, p.y);
}

void print_cluster(Cluster c) {
    printf("Centroid: ");
    print_point(c.centroid);
    printf("\nPoints: ");
    for (int i = 0; i < c.size; i++) {
        print_point(c.points[i]);
        printf(" ");
    }
    printf("\n");
}

void init_clusters(KMeans *km) {
    for (int i = 0; i < km->num_clusters; i++) {
        km->clusters[i].centroid = km->points[i];
        km->clusters[i].size = 0;
    }
    for (int i = km->num_clusters; i < MAX_CLUSTERS; i++) {
        km->clusters[i].centroid = (Point) {0, 0};
        km->clusters[i].size = 0;
    }
}

void assign_points_to_clusters(KMeans *km) {
    for (int i = 0; i < km->num_points; i++) {
        double min_dist = INFINITY;
        int closest_cluster = 0;
        for (int j = 0; j < km->num_clusters; j++) {
            double d = dist(km->points[i], km->clusters[j].centroid);
            if (d < min_dist) {
                min_dist = d;
                closest_cluster = j;
            }
        }
        km->clusters[closest_cluster].points[km->clusters[closest_cluster].size++] = km->points[i];
    }
}

void recalculate_centroids(KMeans *km) {
    for (int i = 0; i < km->num_clusters; i++) {
        double sum_x = 0, sum_y = 0;
        Cluster *c = &km->clusters[i];
        for (int j = 0; j < c->size; j++) {
            sum_x += c->points[j].x;
            sum_y += c->points[j].y;
        }
        c->centroid.x = sum_x / c->size;
        c->centroid.y = sum_y / c->size;
    }
}

void kmeans_algorithm(KMeans *km) {
    init_clusters(km);
    for (int i = 0; i < km->max_iterations; i++) {
        assign_points_to_clusters(km);
        recalculate_centroids(km);
    }
}

int main() {
    // Generate some random points
    srand(42);
    KMeans km = {0};
    km.num_points = rand() % MAX_POINTS + 1;
    for (int i = 0; i < km.num_points; i++) {
        km.points[i].x = (double) rand() / RAND_MAX;
        km.points[i].y = (double) rand() / RAND_MAX;
    }
    // Set number of clusters and max iterations
    km.num_clusters = rand() % 10 + 1;
    km.max_iterations = rand() % 100 + 1;
    kmeans_algorithm(&km);
    // Print results
    printf("Points:\n");
    for (int i = 0; i < km.num_points; i++) {
        print_point(km.points[i]);
        printf("\n");
    }
    printf("Clusters:\n");
    for (int i = 0; i < km.num_clusters; i++) {
        print_cluster(km.clusters[i]);
    }
    return 0;
}