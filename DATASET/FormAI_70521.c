//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_POINTS 1000
#define NUM_CLUSTERS 4
#define DIMENSIONS 2
#define MAX_ITERATIONS 50

// Function to generate random points
void generate_points(float points[NUM_POINTS][DIMENSIONS]) {
    srand(time(NULL));
    for(int i=0; i<NUM_POINTS; i++) {
        for(int j=0; j<DIMENSIONS; j++) {
            points[i][j] = (float) rand() / (float) RAND_MAX;
        }
    }
}

// Function to calculate distance between two points
float distance(float point1[DIMENSIONS], float point2[DIMENSIONS]) {
    float sum = 0.0;
    for(int i=0; i<DIMENSIONS; i++) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// Function to assign points to clusters
void assign_points_to_clusters(float points[NUM_POINTS][DIMENSIONS], float clusters[NUM_CLUSTERS][DIMENSIONS], int assignments[NUM_POINTS]) {
    for(int i=0; i<NUM_POINTS; i++) {
        float min_distance = INFINITY;
        int cluster_index = 0;
        for(int j=0; j<NUM_CLUSTERS; j++) {
            float d = distance(points[i], clusters[j]);
            if(d < min_distance) {
                min_distance = d;
                cluster_index = j;
            }
        }
        assignments[i] = cluster_index;
    }
}

// Function to calculate cluster means
void recalculate_cluster_means(float points[NUM_POINTS][DIMENSIONS], float clusters[NUM_CLUSTERS][DIMENSIONS], int assignments[NUM_POINTS]) {
    float cluster_sums[NUM_CLUSTERS][DIMENSIONS] = {0};
    int cluster_sizes[NUM_CLUSTERS] = {0};
    for(int i=0; i<NUM_POINTS; i++) {
        int cluster_index = assignments[i];
        for(int j=0; j<DIMENSIONS; j++) {
            cluster_sums[cluster_index][j] += points[i][j];
        }
        cluster_sizes[cluster_index]++;
    }
    for(int i=0; i<NUM_CLUSTERS; i++) {
        for(int j=0; j<DIMENSIONS; j++) {
            if(cluster_sizes[i] > 0) {
                clusters[i][j] = cluster_sums[i][j] / cluster_sizes[i];
            }
        }
    }
}

// Function to print the results
void print_results(float points[NUM_POINTS][DIMENSIONS], float clusters[NUM_CLUSTERS][DIMENSIONS], int assignments[NUM_POINTS]) {
    printf("Final cluster centers:\n");
    for(int i=0; i<NUM_CLUSTERS; i++) {
        printf("Cluster %d: (%f, %f)\n", i, clusters[i][0], clusters[i][1]);
    }
    printf("\n");
    printf("Assigned points:\n");
    for(int i=0; i<NUM_POINTS; i++) {
        printf("Point %d: Cluster %d\n", i, assignments[i]);
    }
}

int main() {
    // Generate random points
    float points[NUM_POINTS][DIMENSIONS];
    generate_points(points);

    // Initialize cluster centers
    float clusters[NUM_CLUSTERS][DIMENSIONS];
    for(int i=0; i<NUM_CLUSTERS; i++) {
        for(int j=0; j<DIMENSIONS; j++) {
            clusters[i][j] = points[i][j];
        }
    }

    // Assign each point to an initial cluster randomly
    int assignments[NUM_POINTS];
    srand(time(NULL));
    for(int i=0; i<NUM_POINTS; i++) {
        int cluster_index = rand() % NUM_CLUSTERS;
        assignments[i] = cluster_index;
    }

    // Iterate until convergence or maximum iterations reached
    int iteration = 0;
    while(iteration < MAX_ITERATIONS) {
        // Recalculate cluster means
        recalculate_cluster_means(points, clusters, assignments);

        // Assign points to new clusters
        assign_points_to_clusters(points, clusters, assignments);

        iteration++;
    }

    // Print the results
    print_results(points, clusters, assignments);

    return 0;
}