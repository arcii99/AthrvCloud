//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 1000    // Maximum number of data points
#define MAX_CLUSTERS 10         // Maximum number of clusters
#define MAX_ITERATIONS 100      // Maximum number of iterations
#define THRESHOLD 0.01          // Minimum change required in centroids to stop iteration

// Structure to hold a data point
struct Data {
    double x;
    double y;
};

// Structure to hold a cluster and its centroids
struct Cluster {
    int num_points;
    struct Data data_points[MAX_DATA_POINTS];
    struct Data centroid;
};

// Function to calculate Euclidean distance between two data points
double distance(struct Data a, struct Data b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to randomly initialize centroids
void initialize_centroids(struct Data data[], int num_data_points, struct Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        int random_index = rand() % num_data_points;
        clusters[i].centroid = data[random_index];
    }
}

// Function to assign data points to the closest cluster
void assign_clusters(struct Data data[], int num_data_points, struct Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster_index = -1;

        for (int j = 0; j < num_clusters; j++) {
            struct Data centroid = clusters[j].centroid;
            double d = distance(data[i], centroid);

            if (d < min_distance) {
                min_distance = d;
                closest_cluster_index = j;
            }
        }

        clusters[closest_cluster_index].data_points[clusters[closest_cluster_index].num_points] = data[i];
        clusters[closest_cluster_index].num_points++;
    }
}

// Function to update centroids based on the mean of the data points in the cluster
void update_centroids(struct Cluster clusters[], int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        struct Data sum = {0, 0};

        for (int j = 0; j < clusters[i].num_points; j++) {
            sum.x += clusters[i].data_points[j].x;
            sum.y += clusters[i].data_points[j].y;
        }

        clusters[i].centroid.x = sum.x / clusters[i].num_points;
        clusters[i].centroid.y = sum.y / clusters[i].num_points;
    }
}

// Main function
int main() {
    struct Data data[MAX_DATA_POINTS] = {
        {1, 3}, {2, 5}, {3, 4}, {4, 2}, {5, 1}, 
        {6, 3}, {7, 2}, {8, 4}, {9, 5}, {10, 2} 
    };

    struct Cluster clusters[MAX_CLUSTERS] = {0};

    int num_data_points = sizeof(data) / sizeof(data[0]);
    int num_clusters = 2;
    int num_iterations = 0;

    // Initialize centroids
    initialize_centroids(data, num_data_points, clusters, num_clusters);

    // Iterate until maximum number of iterations or minimum change in centroids is reached
    while (num_iterations < MAX_ITERATIONS) {
        // Assign data points to clusters
        assign_clusters(data, num_data_points, clusters, num_clusters);

        // Update centroids
        struct Cluster previous_clusters[MAX_CLUSTERS];
        for (int i = 0; i < num_clusters; i++) {
            previous_clusters[i] = clusters[i];
        }
        update_centroids(clusters, num_clusters);

        // Check if centroids have changed by more than threshold
        double max_centroid_change = 0;
        for (int i = 0; i < num_clusters; i++) {
            double centroid_change = distance(previous_clusters[i].centroid, clusters[i].centroid);
            if (centroid_change > max_centroid_change) {
                max_centroid_change = centroid_change;
            }
        }

        if (max_centroid_change < THRESHOLD) {
            break;
        }

        num_iterations++;
    }

    // Print final clusters and their centroids
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%.2lf, %.2lf)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Data Points: {");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%.2lf, %.2lf), ", clusters[i].data_points[j].x, clusters[i].data_points[j].y);
        }
        printf("}\n");
    }

    return 0;
}