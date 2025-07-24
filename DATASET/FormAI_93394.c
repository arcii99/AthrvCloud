//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100 // Maximum number of data points
#define K 3 // Maximum number of clusters

typedef struct {
    float x;
    float y;
} point;

typedef struct {
    point centroid;
    int count;
    point* points; // Array of pointers to data points
} cluster;

// Calculates Euclidean distance between two points
float distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Initializes centroids with random data points
void initialize_clusters(cluster* clusters, int k, point* data, int n) {
    int i, j;
    for (i = 0; i < k; i++) {
        clusters[i].centroid = data[rand() % n];
        clusters[i].count = 0;
        clusters[i].points = malloc(N * sizeof(point));
        for (j = 0; j < N; j++) {
            clusters[i].points[j].x = 0.0;
            clusters[i].points[j].y = 0.0;
        }
    }
}

// Assigns each data point to the closest centroid
void assign_points(cluster* clusters, int k, point* data, int n) {
    int i, j, index;
    float min_distance, d;
    for (i = 0; i < n; i++) {
        index = 0;
        min_distance = distance(data[i], clusters[0].centroid);
        for (j = 1; j < k; j++) {
            d = distance(data[i], clusters[j].centroid);
            if (d < min_distance) {
                index = j;
                min_distance = d;
            }
        }
        clusters[index].points[clusters[index].count++] = data[i];
    }
}

// Calculates new centroids based on average of assigned points
void update_centroids(cluster* clusters, int k) {
    int i, j, l;
    float sx, sy;
    for (i = 0; i < k; i++) {
        sx = sy = 0.0;
        for (j = 0; j < clusters[i].count; j++) {
            sx += clusters[i].points[j].x;
            sy += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sx / clusters[i].count;
        clusters[i].centroid.y = sy / clusters[i].count;
        
        // Clear assigned points array
        for (l = 0; l < clusters[i].count; l++) {
            clusters[i].points[l].x = 0.0;
            clusters[i].points[l].y = 0.0;
        }
        clusters[i].count = 0;
    }
}

// Check if two arrays of clusters are equal
int clusters_equal(cluster* c1, cluster* c2, int k) {
    int i, j;
    for (i = 0; i < k; i++) {
        if (c1[i].count != c2[i].count) {
            return 0;
        }
        for (j = 0; j < c1[i].count; j++) {
            if (c1[i].points[j].x != c2[i].points[j].x || c1[i].points[j].y != c2[i].points[j].y) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, k, i, iteration = 1;
    point data[N];
    cluster clusters[K], prev_clusters[K];
    
    // Prompt user to enter number of data points and clusters
    printf("Enter number of data points (maximum %d): ", N);
    scanf("%d", &n);
    printf("Enter number of clusters (maximum %d): ", K);
    scanf("%d", &k);
    
    // Prompt user to enter data points
    printf("Enter data points (x, y):\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &data[i].x, &data[i].y);
    }
    
    // Initialize clusters
    srand(1); // Seed random number generator to produce same results every time
    initialize_clusters(clusters, k, data, n);
    
    // Run K-means algorithm
    while (1) {
        // Assign points to clusters
        assign_points(clusters, k, data, n);
        
        // Save previous clusters
        for (i = 0; i < k; i++) {
            prev_clusters[i] = clusters[i];
        }
        
        // Update centroids
        update_centroids(clusters, k);
        
        // Check if clusters have converged
        if (clusters_equal(clusters, prev_clusters, k)) {
            break;
        }
        
        // Print current iteration
        printf("Iteration %d:\n", iteration++);
        for (i = 0; i < k; i++) {
            printf("Cluster %d: Centroid (%.2f, %.2f)\n", i + 1, clusters[i].centroid.x, clusters[i].centroid.y);
        }
    }
    
    // Print final clusters
    printf("Final Clusters:\n");
    for (i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points: ");
        for (int j = 0; j < clusters[i].count; j++) {
            printf("(%.2f, %.2f) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
    
    return 0;
}