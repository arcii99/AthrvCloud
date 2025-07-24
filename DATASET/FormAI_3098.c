//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSION 2 // you can change the dimension of the dataset
#define DATA_SIZE 10 // you can change the number of data points in the dataset
#define CLUSTER_SIZE 3 // you can change the number of clusters that we want to form

typedef struct {
    double x[DIMENSION];
} Point;

typedef struct {
    Point center;
    int count;
} Cluster;

double distance(Point p1, Point p2) {
    double sum = 0;
    for (int i = 0; i < DIMENSION; i++) {
        double d = p1.x[i] - p2.x[i];
        sum += d * d;
    }
    return sqrt(sum);
}

void init_clusters(Point data[], Cluster clusters[]) {
    // initialize the clusters randomly
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        clusters[i].center = data[rand() % DATA_SIZE];
        clusters[i].count = 0;
    }
}

int find_closest_cluster(Point p, Cluster clusters[]) {
    int closest_cluster = 0;
    double min_distance = INFINITY;
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        double d = distance(p, clusters[i].center);
        if (d < min_distance) {
            min_distance = d;
            closest_cluster = i;
        }
    }
    return closest_cluster;
}

void assign_points_to_clusters(Point data[], Cluster clusters[]) {
    // assign each data point to its nearest cluster
    for (int i = 0; i < DATA_SIZE; i++) {
        int closest_cluster = find_closest_cluster(data[i], clusters);
        clusters[closest_cluster].count++;
    }
}

void update_cluster_centers(Point data[], Cluster clusters[]) {
    // update the centers of the clusters
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        Point sum = {0};
        for (int j = 0; j < DATA_SIZE; j++) {
            int closest_cluster = find_closest_cluster(data[j], clusters);
            if (closest_cluster == i) {
                for (int k = 0; k < DIMENSION; k++) {
                    sum.x[k] += data[j].x[k];
                }
            }
        }
        for (int k = 0; k < DIMENSION; k++) {
            clusters[i].center.x[k] = sum.x[k] / clusters[i].count;
        }
    }
}

void print_clusters(Cluster clusters[]) {
    for (int i = 0; i < CLUSTER_SIZE; i++) {
        printf("Cluster %d: center = (%lf, %lf), count = %d\n", 
            i+1, clusters[i].center.x[0], clusters[i].center.x[1], clusters[i].count);
    }
}

int main() {
    // initialize the data points
    Point data[DATA_SIZE];
    srand(42);
    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            data[i].x[j] = (double) rand() / RAND_MAX;
        }
    }
    
    // initialize the clusters
    Cluster clusters[CLUSTER_SIZE];
    init_clusters(data, clusters);
    
    // assign the data points to the clusters
    assign_points_to_clusters(data, clusters);
    
    // update the centers of the clusters
    update_cluster_centers(data, clusters);
    
    // repeat the above steps until convergence (you can set a maximum number of iterations if you want to)
    for (int i = 0; i < 10; i++) {
        printf("Iteration %d:\n", i+1);
        print_clusters(clusters);
        assign_points_to_clusters(data, clusters);
        update_cluster_centers(data, clusters);
    }
    
    return 0;
}