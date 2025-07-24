//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIM 10
#define MAX_POINTS 1000

typedef struct {
    double point[MAX_DIM];
    int group;
} Point;

Point data[MAX_POINTS];
int k, n, d;

double distance(Point p1, Point p2) {
    double sum = 0;
    for (int i = 0; i < d; i++) {
        sum += pow((p1.point[i] - p2.point[i]), 2);
    }
    return sqrt(sum);
}

Point get_centroid(Point *points, int num_points) {
    Point centroid;
    for (int i = 0; i < d; i++) {
        double sum = 0;
        for (int j = 0; j < num_points; j++) {
            sum += points[j].point[i];
        }
        centroid.point[i] = sum / num_points;
    }
    return centroid;
}

void print_clusters() {
    printf("Clusters:\n");
    for (int i = 1; i <= k; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < n; j++) {
            if (data[j].group == i) {
                printf("(%f", data[j].point[0]);
                for (int l = 1; l < d; l++) {
                    printf(", %f", data[j].point[l]);
                }
                printf(")\n");
            }
        }
    }
}

int main() {
    printf("C Clustering Algorithm Implementation\n");
    printf("Enter number of dimensions (1-%d): ", MAX_DIM);
    scanf("%d", &d);
    printf("Enter number of data points (1-%d): ", MAX_POINTS);
    scanf("%d", &n);
    printf("Enter value of k (number of clusters): ");
    scanf("%d", &k);
    printf("\nEnter data points:\n");
    for (int i = 0; i < n; i++) {
        printf("Data point %d: ", i+1);
        for (int j = 0; j < d; j++) {
            scanf("%lf", &data[i].point[j]);
        }
        data[i].group = 0;
    }
    
    // Initialize centroid points
    Point centroids[k];
    for (int i = 0; i < k; i++) {
        centroids[i] = data[i];
        centroids[i].group = i+1;
    }
    
    int iterations = 0;
    while (1) {
        iterations++;
        // Assign points to clusters
        for (int i = 0; i < n; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < k; j++) {
                double dist = distance(data[i], centroids[j]);
                if (dist < min_distance) {
                    min_distance = dist;
                    data[i].group = j+1;
                }
            }
        }
        
        // Check if clusters have changed
        int done = 1;
        for (int i = 0; i < k; i++) {
            Point points[n];
            int count = 0;
            double prev_distance = distance(centroids[i], centroids[i]);
            for (int j = 0; j < n; j++) {
                if (data[j].group == i+1) {
                    points[count] = data[j];
                    count++;
                }
            }
            Point new_centroid = get_centroid(points, count);
            double new_distance = distance(centroids[i], new_centroid);
            if (new_distance - prev_distance > 0.0001) {
                centroids[i] = new_centroid;
                centroids[i].group = i+1;
                done = 0;
            }
        }
        
        if (done) break;
    }
    
    print_clusters();
    printf("Converged after %d iterations\n", iterations);
    return 0;
}