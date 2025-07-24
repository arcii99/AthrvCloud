//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

struct Data_Point {
    float x;
    float y;
};

struct Cluster {
    int num_points;
    struct Data_Point points[100];
    struct Data_Point central_point;
};

float distance(struct Data_Point a, struct Data_Point b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return(sqrt(dx*dx + dy*dy));
}

void assign_points_to_clusters(struct Cluster clusters[], int num_clusters, struct Data_Point data_points[], int num_data_points) {
    for(int i = 0; i < num_data_points; i++) {
        int closest_cluster_index = 0;
        float closest_cluster_distance = distance(data_points[i], clusters[0].central_point);

        for(int j = 1; j < num_clusters; j++) {
            float dist = distance(data_points[i], clusters[j].central_point);
            if(dist < closest_cluster_distance) {
                closest_cluster_index = j;
                closest_cluster_distance = dist;
            }
        }

        clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points++] = data_points[i];
    }
}

struct Data_Point compute_centroid(struct Cluster c) {
    float x_sum = 0;
    float y_sum = 0;

    for(int i = 0; i < c.num_points; i++) {
        x_sum += c.points[i].x;
        y_sum += c.points[i].y;
    }

    struct Data_Point centroid;
    centroid.x = x_sum / c.num_points;
    centroid.y = y_sum / c.num_points;

    return centroid;
}

void compute_centroids(struct Cluster clusters[], int num_clusters) {
    for(int i = 0; i < num_clusters; i++) {
        clusters[i].central_point = compute_centroid(clusters[i]);
        clusters[i].num_points = 0;
    }
}

void print_clusters(struct Cluster clusters[], int num_clusters) {
    for(int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        for(int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("Centroid: (%f, %f)\n", clusters[i].central_point.x, clusters[i].central_point.y);
    }
}

int main() {
    struct Data_Point data_points[] = {{1, 2}, {1, 4}, {1, 0}, {4, 2}, {4, 4}, {4, 0}};
    int num_data_points = sizeof(data_points) / sizeof(data_points[0]);

    struct Cluster clusters[] = {{{0}, data_points[0]}, {{0}, data_points[5]}}; // Initializing clusters with first and last data points
    int num_clusters = sizeof(clusters) / sizeof(clusters[0]);

    assign_points_to_clusters(clusters, num_clusters, data_points, num_data_points);
    print_clusters(clusters, num_clusters);

    for(int i = 0; i < 10; i++) { // Iterating 10 times to recompute centroids and reassign points
        compute_centroids(clusters, num_clusters);
        assign_points_to_clusters(clusters, num_clusters, data_points, num_data_points);
        printf("\nAfter iteration %d:\n", i+1);
        print_clusters(clusters, num_clusters);
    }

    return 0;
}