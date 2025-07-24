//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_POINTS 100
#define NUM_CLUSTERS 3

struct Point {
    int x;
    int y;
};

struct Cluster {
    int x;
    int y;
    struct Point* points;
    int num_points;
};

void initialize_points(struct Point* points) {
    srand(time(NULL));
    for(int i = 0; i < NUM_POINTS; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }
}

void initialize_clusters(struct Cluster* clusters) {
    srand(time(NULL));
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        clusters[i].x = rand() % 100;
        clusters[i].y = rand() % 100;
        clusters[i].points = malloc(NUM_POINTS * sizeof(struct Point));
        clusters[i].num_points = 0;
    }
}

void assign_points_to_clusters(struct Point* points, struct Cluster* clusters) {
    int min_distance, distance;
    int cluster_index;
    for(int i = 0; i < NUM_POINTS; i++) {
        min_distance = 1000;
        for(int j = 0; j < NUM_CLUSTERS; j++) {
            distance = abs(points[i].x - clusters[j].x) + abs(points[i].y - clusters[j].y);
            if(distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }
}

void update_clusters(struct Cluster* clusters) {
    int total_x, total_y;
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        total_x = 0;
        total_y = 0;
        for(int j = 0; j < clusters[i].num_points; j++) {
            total_x += clusters[i].points[j].x;
            total_y += clusters[i].points[j].y;
        }
        clusters[i].x = total_x / clusters[i].num_points;
        clusters[i].y = total_y / clusters[i].num_points;
    }
}

int main() {
    struct Point points[NUM_POINTS];
    initialize_points(points);
    
    struct Cluster clusters[NUM_CLUSTERS];
    initialize_clusters(clusters);
    
    for(int i = 0; i < 10; i++) {
        assign_points_to_clusters(points, clusters);
        update_clusters(clusters);
    }
    
    // Print the final clusters
    for(int i = 0; i < NUM_CLUSTERS; i++) {
        printf("Cluster %d:\n", i);
        for(int j = 0; j < clusters[i].num_points; j++) {
            printf("(%d,%d) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
    
    return 0;
}