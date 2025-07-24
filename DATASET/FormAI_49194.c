//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 100
#define K 3

typedef struct point {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int get_nearest_cluster(Point point, Point centroids[], int k) {
    double min_dist = distance(point, centroids[0]);
    int min_index = 0;
    for(int i=1; i<k; i++) {
        double dist = distance(point, centroids[i]);
        if(dist < min_dist){
            min_dist = dist;
            min_index = i;
        }
    }
    return min_index;
}

Point get_centroid(Point points[], int cluster[], int n, int index) {
    double x_total = 0;
    double y_total = 0;
    int count = 0;
    for(int i=0; i<n; i++){
        if(cluster[i]==index){
            x_total += points[i].x;
            y_total += points[i].y;
            count++;
        }
    }
    Point centroid = {.x = x_total/count, .y = y_total/count};
    return centroid;
}

void print_clusters(Point points[], int cluster[], int n, int k) {
    for(int i=0; i<k; i++) {
        printf("Cluster %d:\n", i+1);
        for(int j=0; j<n; j++) {
            if(cluster[j]==i) {
                printf("(%lf, %lf)\n", points[j].x, points[j].y);
            }
        }
    }
}

void kmeans(Point points[], int n, int k) {
    Point old_centroids[k];
    Point centroids[k];
    int cluster[n];

    // randomly initialize centroids
    for(int i=0; i<k; i++) {
        centroids[i].x = rand() % SIZE;
        centroids[i].y = rand() % SIZE;
    }

    while(1) {
        
        // assign points to their cluster
        for(int i=0; i<n; i++){
            cluster[i] = get_nearest_cluster(points[i], centroids, k);
        }

        // calculate new centroids
        for(int i=0; i<k; i++) {
            old_centroids[i] = centroids[i];
            centroids[i] = get_centroid(points, cluster, n, i);
        }

        // check for convergence
        int converge = 1;
        for(int i=0; i<k; i++) {
            if(distance(old_centroids[i], centroids[i]) > 0.001) {
                converge = 0;
            }
        }
        if(converge == 1) {
            break;
        } 
    }

    print_clusters(points, cluster, n, k);

}

int main() {
    Point points[SIZE];
    for(int i=0; i<SIZE; i++) {
        points[i].x = rand() % SIZE;
        points[i].y = rand() % SIZE;
    }
    kmeans(points, SIZE, K);
    return 0;
}