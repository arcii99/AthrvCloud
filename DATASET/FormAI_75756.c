//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct for our data points
typedef struct Point {
    float x;
    float y;
    int cluster;
} Point;

// Function to calculate distance between two points
float distance(Point p1, Point p2) {
    return sqrt(pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2));
}

int main() {

    srand(time(NULL)); // seed RNG

    // Initialize data points
    Point data[100];
    for (int i = 0; i < 100; i++) {
        data[i].x = (float)rand()/(float)(RAND_MAX/100);
        data[i].y = (float)rand()/(float)(RAND_MAX/100);
        data[i].cluster = -1; // Initialize clusters to -1 (unassigned)
    }

    // Initialize centroids
    Point centroids[3];
    for (int i = 0; i < 3; i++) {
        centroids[i].x = (float)rand()/(float)(RAND_MAX/100);
        centroids[i].y = (float)rand()/(float)(RAND_MAX/100);
        centroids[i].cluster = i; // Initialize cluster to centroid index
    }

    // Iterate through data points assigning clusters to each
    for (int i = 0; i < 100; i++) {
        float minDist = 10000; // arbitrarily high value
        for (int j = 0; j < 3; j++) {
            float dist = distance(data[i], centroids[j]);
            if (dist < minDist) {
                minDist = dist;
                data[i].cluster = j; // Assign to closest centroid
            }
        }
    }

    // Calculate new centroids based on cluster assignments
    while (1) {
        Point newCentroids[3];
        for (int i = 0; i < 3; i++) {
            newCentroids[i].x = 0;
            newCentroids[i].y = 0;
            int count = 0;
            for (int j = 0; j < 100; j++) {
                if (data[j].cluster == i) {
                    newCentroids[i].x += data[j].x;
                    newCentroids[i].y += data[j].y;
                    count++;
                }
            }
            if (count > 0) { // Avoid dividing by zero
                newCentroids[i].x /= count;
                newCentroids[i].y /= count;
                newCentroids[i].cluster = i; // Initialize cluster to centroid index
            }
            else { // If there are no points in the cluster, reinitialize centroid randomly
                newCentroids[i].x = (float)rand()/(float)(RAND_MAX/100);
                newCentroids[i].y = (float)rand()/(float)(RAND_MAX/100);
                newCentroids[i].cluster = i; // Initialize cluster to centroid index
            }
        }

        // Check if centroids have converged
        if (centroids[0].x == newCentroids[0].x && centroids[0].y == newCentroids[0].y &&
            centroids[1].x == newCentroids[1].x && centroids[1].y == newCentroids[1].y &&
            centroids[2].x == newCentroids[2].x && centroids[2].y == newCentroids[2].y) {
            break;
        }

        // Update centroids and cluster assignments
        for (int i = 0; i < 100; i++) {
            float minDist = 10000; // arbitrarily high value
            for (int j = 0; j < 3; j++) {
                float dist = distance(data[i], newCentroids[j]);
                if (dist < minDist) {
                    minDist = dist;
                    data[i].cluster = j; // Assign to closest centroid
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            centroids[i] = newCentroids[i];
        }
    }

    // Print final clusters
    printf("Final clusters:\n");
    for (int i = 0; i < 100; i++) {
        printf("(%f,%f) -> cluster %d\n", data[i].x, data[i].y, data[i].cluster);
    }

    return 0;
}