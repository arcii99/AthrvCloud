//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_POINTS 500
#define MAX_ITERATIONS 50
#define NUM_CLUSTERS 5
#define DIMENSIONS 2

typedef struct {
    double data[DIMENSIONS];
    int cluster;
} Point;

void initialize_points(Point *points);
double distance(Point *p1, Point *p2);
void print_clusters(Point *points);

int main() {
    Point points[NUM_POINTS];
    int i, j, k, l;
    double min_distance, current_distance;
    int min_cluster;
    Point centroids[NUM_CLUSTERS];
    int iterations = 0;
    
    srand(time(NULL));
    initialize_points(points);
    
    // set initial clusters randomly
    for (i = 0; i < NUM_POINTS; i++) {
        points[i].cluster = rand() % NUM_CLUSTERS;
    }
    
    // repeat until convergence or max iterations reached
    while (iterations < MAX_ITERATIONS) {
        // calculate cluster centroids
        for (i = 0; i < NUM_CLUSTERS; i++) {
            int num_points_in_cluster = 0;
            double temp_centroid[DIMENSIONS] = {0};
            for (j = 0; j < NUM_POINTS; j++) {
                if (points[j].cluster == i) {
                    num_points_in_cluster++;
                    for (k = 0; k < DIMENSIONS; k++) {
                        temp_centroid[k] += points[j].data[k];
                    }
                }
            }
            for (l = 0; l < DIMENSIONS; l++) {
                centroids[i].data[l] = temp_centroid[l] / num_points_in_cluster;
            }
        }
        
        // assign points to clusters
        for (i = 0; i < NUM_POINTS; i++) {
            min_distance = distance(&points[i], &centroids[0]);
            min_cluster = 0;
            for (j = 1; j < NUM_CLUSTERS; j++) {
                current_distance = distance(&points[i], &centroids[j]);
                if (current_distance < min_distance) {
                    min_distance = current_distance;
                    min_cluster = j;
                }
            }
            points[i].cluster = min_cluster;
        }
        
        // check if we have converged
        int num_misclassified_points = 0;
        for (i = 0; i < NUM_POINTS; i++) {
            if (points[i].cluster != points[0].cluster) {
                num_misclassified_points++;
            }
        }
        if (num_misclassified_points == 0) {
            break;
        }
        
        iterations++;
    }
    
    print_clusters(points);
    
    return 0;
}

// initialize the points with random data
void initialize_points(Point *points) {
    int i, j;
    for (i = 0; i < NUM_POINTS; i++) {
        for (j = 0; j < DIMENSIONS; j++) {
            points[i].data[j] = (double)rand()/RAND_MAX * 100.0;
        }
    }
}

// calculate the distance between two points
double distance(Point *p1, Point *p2) {
    int i;
    double sum = 0;
    for (i = 0; i < DIMENSIONS; i++) {
        sum += (p1->data[i] - p2->data[i])*(p1->data[i] - p2->data[i]);
    }
    return sum;
}

// print out the clusters
void print_clusters(Point *points) {
    int i, j;
    for (i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for (j = 0; j < NUM_POINTS; j++) {
            if (points[j].cluster == i) {
                printf("(%lf,%lf)\n", points[j].data[0], points[j].data[1]);
            }
        }
        printf("\n");
    }
}