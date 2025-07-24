//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100 //Maximum number of data points
#define K 3 //Number of clusters

//Data structure to store a point in 2D space
typedef struct Point {
    int x;
    int y;
} Point;

//Data structure to store a cluster with its center and number of points in it
typedef struct Cluster {
    Point center;
    int numPoints;
    Point points[N];
} Cluster;

//Function to calculate Euclidean distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

//Function to assign each point to a cluster based on minimum distance from the center
void assignPoints(Cluster* clusters, int numClusters, Point* data, int numPoints) {
    for(int i = 0; i < numPoints; i++) {
        double minDist = distance(data[i], clusters[0].center);
        int minCluster = 0;
        for(int j = 1; j < numClusters; j++) {
            double dist = distance(data[i], clusters[j].center);
            if(dist < minDist) {
                minDist = dist;
                minCluster = j;
            }
        }
        clusters[minCluster].points[clusters[minCluster].numPoints++] = data[i];
    }
}

//Function to calculate the center of each cluster based on the current points belonging to it
void calculateCenters(Cluster* clusters, int numClusters) {
    for(int i = 0; i < numClusters; i++) {
        int sumX = 0;
        int sumY = 0;
        for(int j = 0; j < clusters[i].numPoints; j++) {
            sumX += clusters[i].points[j].x;
            sumY += clusters[i].points[j].y;
        }
        clusters[i].center.x = sumX / clusters[i].numPoints;
        clusters[i].center.y = sumY / clusters[i].numPoints;
    }
}

int main() {
    Point data[N] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}, {11,12}, {13,14}, {15,16}, {17,18}, {19,20},
                    {21,22}, {23,24}, {25,26}, {27,28}, {29,30}, {31,32}, {33,34}, {35,36}, {37,38}, {39,40}}; //Dummy data
    int numPoints = 20; //Number of data points
    
    Cluster clusters[K] = {{{0,0}, 0}, {{4,4}, 0}, {{12,12}, 0}}; //Initial cluster centers
    int numClusters = K; //Number of clusters
    
    assignPoints(clusters, numClusters, data, numPoints);
    calculateCenters(clusters, numClusters);
    
    return 0;
}