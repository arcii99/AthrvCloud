//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define a 'Cluster' data structure
typedef struct {
    double x; 
    double y; 
    int size;
} Cluster;

// Define a 'Point' data structure
typedef struct {
    double x; 
    double y; 
} Point;

// Function to calculate Euclidean distance between two points
double distance(Point *p1, Point *p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Function to initialize random centroids
void initialize_centroids(Point *dataset, int num_points, Cluster *centroids, int num_clusters) {
    srand(time(NULL)); // Seed for random number generator
    
    // Assign random points as initial centroids
    int *chosen_indices = calloc(num_clusters, sizeof(int));
    for (int i = 0; i < num_clusters; i++) {
        int rand_index;
        do {
            rand_index = rand() % num_points;
        } while (chosen_indices[rand_index]);
        chosen_indices[rand_index] = 1;
        centroids[i].x = dataset[rand_index].x;
        centroids[i].y = dataset[rand_index].y;
        centroids[i].size = 0;
    }
    free(chosen_indices);
}

// Function to assign points to nearest centroid
void assign_to_clusters(Point *dataset, int num_points, Cluster *centroids, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster_index = -1;
        for (int j = 0; j < num_clusters; j++) {
            double dist = distance(&dataset[i], &centroids[j]);
            if (dist < min_distance) {
                min_distance = dist;
                closest_cluster_index = j;
            }
        }
        centroids[closest_cluster_index].size++;
        double mean_x = centroids[closest_cluster_index].x + 
            ((dataset[i].x - centroids[closest_cluster_index].x) / (double) centroids[closest_cluster_index].size);
        double mean_y = centroids[closest_cluster_index].y + 
            ((dataset[i].y - centroids[closest_cluster_index].y) / (double) centroids[closest_cluster_index].size);
        centroids[closest_cluster_index].x = mean_x;
        centroids[closest_cluster_index].y = mean_y;
    }
}

// Function to print out current state of the clusters
void print_clusters(Cluster *centroids, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("\tCentroid: (%.2lf, %.2lf)\n", centroids[i].x, centroids[i].y);
        printf("\tSize: %d\n", centroids[i].size);
    }
    printf("--------------------------\n");
}

int main() {
    // Generate random dataset of 50 points
    Point dataset[50];
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < 50; i++) {
        dataset[i].x = (double) (rand() % 100) / 10.0;
        dataset[i].y = (double) (rand() % 100) / 10.0;
    }
    
    // Initialize 3 random centroids
    Cluster centroids[3];
    initialize_centroids(dataset, 50, centroids, 3);
    
    // Perform clustering iterations
    int max_iterations = 100;
    for (int i = 0; i < max_iterations; i++) {
        assign_to_clusters(dataset, 50, centroids, 3);
        printf("After iteration %d:\n", i+1);
        print_clusters(centroids, 3);
    }
    
    return 0;
}