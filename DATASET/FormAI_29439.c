//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define struct for point in 2D space
struct point {
    double x;
    double y;
};

// function to calculate euclidean distance between two points
double distance(struct point p1, struct point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// main function
int main() {

    int k = 3; // number of clusters we want to form
    int max_iterations = 50; // maximum number of iterations we want to run
    double tolerance = 0.001; // tolerance for convergence

    // array of points to cluster
    struct point points[] = {
        {2, 10},
        {2, 5},
        {8, 4},
        {5, 8},
        {7, 5},
        {6, 4},
        {1, 2},
        {4, 9}
    };

    int n = sizeof(points) / sizeof(points[0]); // number of points

    // randomly initialize centroids
    struct point centroids[k];
    for (int i = 0; i < k; i++) {
        centroids[i] = points[rand() % n];
    }

    // allocate memory for clusters
    struct point *clusters[k];
    for (int i = 0; i < k; i++) {
        clusters[i] = malloc(n * sizeof(struct point));
    }

    // main loop for clustering
    for (int iteration = 0; iteration < max_iterations; iteration++) {

        // assign each point to closest centroid
        for (int i = 0; i < n; i++) {
            double min_distance = distance(points[i], centroids[0]);
            int nearest_centroid = 0;
            for (int j = 1; j < k; j++) {
                double d = distance(points[i], centroids[j]);
                if (d < min_distance) {
                    min_distance = d;
                    nearest_centroid = j;
                }
            }
            clusters[nearest_centroid][i] = points[i];
        }

        // save old centroids for convergence check
        struct point old_centroids[k];
        for (int i = 0; i < k; i++) {
            old_centroids[i] = centroids[i];
        }

        // calculate new centroids
        for (int i = 0; i < k; i++) {
            double sum_x = 0;
            double sum_y = 0;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (clusters[i][j].x != 0 && clusters[i][j].y != 0) {
                    sum_x += clusters[i][j].x;
                    sum_y += clusters[i][j].y;
                    count++;
                }
            }
            if (count > 0) {
                centroids[i].x = sum_x / count;
                centroids[i].y = sum_y / count;
            }
        }

        // check for convergence
        int converged = 1;
        for (int i = 0; i < k; i++) {
            if (distance(centroids[i], old_centroids[i]) > tolerance) {
                converged = 0;
                break;
            }
        }
        if (converged) {
            break;
        }

        // reset clusters for next iteration
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                clusters[i][j].x = 0;
                clusters[i][j].y = 0;
            }
        }

    }

    // print final centroids and clusters
    printf("Final centroids:\n");
    for (int i = 0; i < k; i++) {
        printf("(%f, %f)\n", centroids[i].x, centroids[i].y);
    }
    printf("Final clusters:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (clusters[i][j].x != 0 && clusters[i][j].y != 0) {
                printf("(%f, %f)\n", clusters[i][j].x, clusters[i][j].y);
            }
        }
    }

    // free memory
    for (int i = 0; i < k; i++) {
        free(clusters[i]);
    }

    return 0;
}