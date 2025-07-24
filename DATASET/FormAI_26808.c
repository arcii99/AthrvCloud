//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Define constants */
#define NUM_POINTS 100			/* Number of points to generate */
#define DIMENSIONS 2			/* Number of dimensions */
#define NUM_CLUSTERS 5			/* Number of clusters */
#define MIN_VALUE 0.0			/* Minimum value for point */
#define MAX_VALUE 100.0			/* Maximum value for point */
#define MAX_ITERATIONS 100		/* Maximum number of iterations */

/* Define structures */
typedef struct Point {
    double x[DIMENSIONS];
} Point;

typedef struct Cluster {
    Point centroid;
    Point *points;
    int num_points;
} Cluster;

/* Function prototypes */
void generate_points(Point *points);
double euclidean_distance(Point a, Point b);
Point calculate_centroid(Point *points, int num_points);
int assign_points_to_clusters(Point *points, Cluster *clusters);
void update_cluster_centroids(Cluster *clusters);
int are_clusters_equal(Cluster *clusters, Cluster *prev_clusters);
void print_clusters(Cluster *clusters);

/* Main function */
int main() {
    srand(time(NULL));		/* Initialize random seed */
    Point points[NUM_POINTS];	/* Array of points */
    Cluster clusters[NUM_CLUSTERS];	/* Array of clusters */
    int i, j, num_iterations = 0;
    int converged = 0;		/* Flag to indicate if clustering has converged */

    /* Generate random points */
    generate_points(points);

    /* Initialize clusters */
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            clusters[i].centroid.x[j] = ((double) rand() / RAND_MAX) * (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
        }
        clusters[i].points = NULL;
        clusters[i].num_points = 0;
    }

    /* Perform K-Means clustering */ 
    while (num_iterations < MAX_ITERATIONS && !converged) {
        /* Assign points to clusters */
        converged = assign_points_to_clusters(points, clusters);

        /* Update cluster centroids */
        update_cluster_centroids(clusters);

        /* Increment iteration counter */
        num_iterations++;
    }
    
    /* Print final clusters */
    printf("Final clusters:\n");
    print_clusters(clusters);

    return 0;
}

/* Function to generate random points */
void generate_points(Point *points) {
    int i, j;

    for (i = 0; i < NUM_POINTS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            points[i].x[j] = ((double) rand() / RAND_MAX) * (MAX_VALUE - MIN_VALUE) + MIN_VALUE;
        }
    }
}

/* Function to calculate euclidean distance between two points */
double euclidean_distance(Point a, Point b) {
    int i;
    double distance = 0.0;

    for (i = 0; i < DIMENSIONS; i++) {
        distance += pow(a.x[i] - b.x[i], 2);
    }

    return sqrt(distance);
}

/* Function to calculate centroid of a cluster */
Point calculate_centroid(Point *points, int num_points) {
    int i, j;
    Point centroid;

    /* Initialize centroid to zero */
    for (j = 0; j < DIMENSIONS; j++) {
        centroid.x[j] = 0.0;
    }

    /* Calculate centroid */
    for (i = 0; i < num_points; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            centroid.x[j] += points[i].x[j];
        }
    }
    for (j = 0; j < DIMENSIONS; j++) {
        centroid.x[j] /= num_points;
    }

    return centroid;
}

/* Function to assign points to clusters */
int assign_points_to_clusters(Point *points, Cluster *clusters) {
    int i, j, k, min_index;
    double min_distance, distance;
    int changed = 0;

    /* Clear current cluster assignments */
    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].points = NULL;
        clusters[i].num_points = 0;
    }

    /* Assign each point to the nearest cluster */
    for (i = 0; i < NUM_POINTS; i++) {
        min_distance = INFINITY;
        for (j = 0; j < NUM_CLUSTERS; j++) {
            distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }
        if (clusters[min_index].points == NULL) {
            clusters[min_index].points = (Point *) malloc(sizeof(Point));
        } else {
            clusters[min_index].points = (Point *) realloc(clusters[min_index].points, (clusters[min_index].num_points + 1) * sizeof(Point));
        }
        clusters[min_index].points[clusters[min_index].num_points] = points[i];
        clusters[min_index].num_points++;
    }

    /* Check if any point assignments have changed */
    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < clusters[i].num_points; j++) {
            for (k = 0; k < DIMENSIONS; k++) {
                if (clusters[i].points[j].x[k] != clusters[i].points[j-1].x[k]) {
                    changed = 1;
                    break;
                }
            }
            if (changed) {
                break;
            }
        }
        if (changed) {
            break;
        }
    }

    /* Determine if clustering has converged */
    if (!changed) {
        return 1;
    } else {
        return 0;
    }
}

/* Function to update centroids of clusters */
void update_cluster_centroids(Cluster *clusters) {
    int i;

    for (i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].centroid = calculate_centroid(clusters[i].points, clusters[i].num_points);
    }
}

/* Function to determine if clusters have changed */
int are_clusters_equal(Cluster *clusters, Cluster *prev_clusters) {
    int i, j;

    for (i = 0; i < NUM_CLUSTERS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            if (clusters[i].centroid.x[j] != prev_clusters[i].centroid.x[j]) {
                return 0;
            }
        }
    }

    return 1;
}

/* Function to print clusters */
void print_clusters(Cluster *clusters) {
    int i, j;

    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i+1);
        for (j = 0; j < clusters[i].num_points; j++) {
            printf("(%0.2f, %0.2f) ", clusters[i].points[j].x[0], clusters[i].points[j].x[1]);
        }
        printf("\nCentroid: (%0.2f, %0.2f)\n", clusters[i].centroid.x[0], clusters[i].centroid.x[1]);
    }
}