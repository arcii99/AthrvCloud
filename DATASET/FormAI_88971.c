//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUM_POINTS 1000
#define MAX_NUM_CLUSTERS 100

struct Point {
    float x, y;
};

struct Cluster {
    struct Point centroid;
    int num_points;
    struct Point points[MAX_NUM_POINTS];
};

float euclidean_distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void add_point_to_cluster(struct Cluster *cluster, struct Point point) {
    cluster->points[cluster->num_points] = point;
    cluster->num_points++;
}

void reset_cluster(struct Cluster *cluster) {
    cluster->num_points = 0;
}

void update_centroid(struct Cluster *cluster) {
    float total_x = 0, total_y = 0;
    
    for (int i = 0; i < cluster->num_points; i++) {
        total_x += cluster->points[i].x;
        total_y += cluster->points[i].y;
    }
    
    cluster->centroid.x = total_x / cluster->num_points;
    cluster->centroid.y = total_y / cluster->num_points;
}

int main() {
    struct Point points[MAX_NUM_POINTS];
    int num_points;
    
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    
    printf("Enter the x and y coordinates of each point: \n");
    for (int i = 0; i < num_points; i++) {
        scanf("%f %f", &points[i].x, &points[i].y);
    }
    
    int num_clusters;
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    
    struct Cluster clusters[MAX_NUM_CLUSTERS];
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = points[i].x;
        clusters[i].centroid.y = points[i].y;
        reset_cluster(&clusters[i]);
    }
    
    int max_iterations;
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);
    
    int iteration_count = 0;
    int is_converged = 0;
    
    while (iteration_count < max_iterations && !is_converged) {
        // Assign points to nearest cluster
        for (int i = 0; i < num_points; i++) {
            float min_distance = euclidean_distance(points[i], clusters[0].centroid);
            int min_distance_cluster_index = 0;
            
            for (int j = 1; j < num_clusters; j++) {
                float distance = euclidean_distance(points[i], clusters[j].centroid);
                
                if (distance < min_distance) {
                    min_distance = distance;
                    min_distance_cluster_index = j;
                }
            }
            
            add_point_to_cluster(&clusters[min_distance_cluster_index], points[i]);
        }
        
        // Update centroids
        for (int i = 0; i < num_clusters; i++) {
            update_centroid(&clusters[i]);
        }
        
        // Check for convergence
        is_converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].num_points > 0) {
                float distance = euclidean_distance(clusters[i].centroid, points[0]);
                
                for (int j = 1; j < clusters[i].num_points; j++) {
                    if (euclidean_distance(clusters[i].centroid, clusters[i].points[j]) != distance) {
                        is_converged = 0;
                        break;
                    }
                }
            }
            
            if (!is_converged) {
                break;
            }
        }
        
        iteration_count++;
        
        // Reset clusters
        for (int i = 0; i < num_clusters; i++) {
            reset_cluster(&clusters[i]);
        }
    }
    
    printf("Final clusters:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:\n");
        
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
    
    return 0;
}