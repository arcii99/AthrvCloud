//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

#define MAX_CLUSTERS 5
#define MAX_ELEMENTS 100
#define THRESHOLD 0.1

// Data structure to store the coordinates of each point
typedef struct Point {
    float x;
    float y;
} Point;

// Data structure to store each cluster
typedef struct Cluster {
    Point centroid;
    Point* elements[MAX_ELEMENTS];
    int size;
} Cluster;

// Euclidean distance calculation function
float dist(Point* p1, Point* p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

// Initialization function to create the initial clusters
void initialize(Cluster clusters[], Point points[], int num_points, int k) {
    for(int i=0; i<k; i++) {
        clusters[i].centroid = points[i];
        clusters[i].size = 0;
    }
    for(int i=k; i<num_points; i++) {
        int random_cluster = rand() % k;
        clusters[random_cluster].elements[clusters[random_cluster].size] = &points[i];
        clusters[random_cluster].size++;
    }
}

// Function to update cluster centroids
void update_centroids(Cluster clusters[], int k) {
    for(int i=0; i<k; i++) {
        float sum_x = 0, sum_y = 0;
        for(int j=0; j<clusters[i].size; j++) {
            Point* curr = clusters[i].elements[j];
            sum_x += curr->x;
            sum_y += curr->y;
        }
        clusters[i].centroid.x = sum_x/clusters[i].size;
        clusters[i].centroid.y = sum_y/clusters[i].size;
    }
}

// Function to assign points to clusters
int assign_points(Cluster clusters[], Point points[], int num_points) {
    int changed = 0;
    for(int i=0; i<num_points; i++) {
        Point* curr = &points[i];
        int closest_cluster = 0;
        float min_dist = dist(curr, &clusters[0].centroid);
        for(int j=1; j<MAX_CLUSTERS; j++) {
            float d = dist(curr, &clusters[j].centroid);
            if(d < min_dist) {
                min_dist = d;
                closest_cluster = j;
            }
        }
        if(min_dist > THRESHOLD) changed = 1;
        clusters[closest_cluster].elements[clusters[closest_cluster].size] = curr;
        clusters[closest_cluster].size++;
    }
    return changed;
}

// Function to print the clusters
void print_clusters(Cluster clusters[], int k) {
    for(int i=0; i<k; i++) {
        printf("Cluster %d: (%.2f, %.2f) - %d elements\n", i, clusters[i].centroid.x, clusters[i].centroid.y, clusters[i].size);
        printf("Elements: ");
        for(int j=0; j<clusters[i].size; j++) {
            printf("(%.2f, %.2f) ", clusters[i].elements[j]->x, clusters[i].elements[j]->y);
        }
        printf("\n\n");
    }
}

// Main function
int main() {
    srand(time(0)); // Seed for random function
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    Point points[MAX_ELEMENTS];
    for(int i=0; i<num_points; i++) {
        printf("Enter the coordinates of point %d (x y): ", i+1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }
    int k;
    printf("Enter the number of clusters (max 5): ");
    scanf("%d", &k);
    Cluster clusters[MAX_CLUSTERS];
    initialize(clusters, points, num_points, k);
    int iterations = 0;
    int changed = 1;
    while(changed) {
        printf("Iteration %d:\n", ++iterations);
        changed = assign_points(clusters, points, num_points);
        update_centroids(clusters, k);
        print_clusters(clusters, k);
    }
    return 0;
}