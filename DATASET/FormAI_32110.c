//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>

// Define a struct to represent a point
typedef struct {
    double x;
    double y;
} Point;

// Define a struct to represent a cluster of points
typedef struct {
    int size;
    Point center;
    Point *points;
} Cluster;

int main() {
    // Initialize an array of points
    Point points[] = {{1.2, 3.4}, {5.6, 7.8}, {9.0, 1.2}, {3.4, 5.6}, {7.8, 9.0}};
    int numPoints = sizeof(points) / sizeof(Point);

    // Initialize an array of clusters
    Cluster clusters[] = {
        {1, {1.2, 3.4}, &points[0]},
        {1, {5.6, 7.8}, &points[1]},
        {1, {9.0, 1.2}, &points[2]},
        {1, {3.4, 5.6}, &points[3]},
        {1, {7.8, 9.0}, &points[4]}
    };
    int numClusters = sizeof(clusters) / sizeof(Cluster);

    // Define a function to calculate the distance between two points
    double distance(Point a, Point b) {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx*dx + dy*dy);
    }

    // Define a function to calculate the new center of a cluster
    Point calculateCenter(Cluster cluster) {
        Point center = {0, 0};
        for (int i = 0; i < cluster.size; i++) {
            center.x += cluster.points[i].x;
            center.y += cluster.points[i].y;
        }
        center.x /= cluster.size;
        center.y /= cluster.size;
        return center;
    }

    // Perform iterations until convergence
    int converged = 0;
    while (!converged) {
        // Assign each point to the nearest cluster
        for (int i = 0; i < numPoints; i++) {
            int nearestCluster = 0;
            double minDistance = distance(points[i], clusters[0].center);
            for (int j = 1; j < numClusters; j++) {
                double d = distance(points[i], clusters[j].center);
                if (d < minDistance) {
                    nearestCluster = j;
                    minDistance = d;
                }
            }
            clusters[nearestCluster].points[clusters[nearestCluster].size] = points[i];
            clusters[nearestCluster].size++;
        }

        // Update the centers of each cluster
        converged = 1;
        for (int i = 0; i < numClusters; i++) {
            Point newCenter = calculateCenter(clusters[i]);
            if (newCenter.x != clusters[i].center.x || newCenter.y != clusters[i].center.y) {
                clusters[i].center = newCenter;
                converged = 0;
            }
        }
    }

    // Print the final clusters and their points
    for (int i = 0; i < numClusters; i++) {
        printf("Cluster %d: (%f, %f)\n", i, clusters[i].center.x, clusters[i].center.y);
        printf("Points:");
        for (int j = 0; j < clusters[i].size; j++) {
            printf(" (%f, %f)", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}