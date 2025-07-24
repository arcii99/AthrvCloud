//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define k 3 //Change this to adjust number of clusters

typedef struct {
    float x;
    float y;
    float z;
} Point;

float getDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    Point dataset[10] = {
        {2.0, 3.0, 1.0},
        {4.0, 5.0, 2.0},
        {8.0, 9.0, 3.0},
        {1.0, 2.0, 2.0},
        {3.0, 4.0, 3.0},
        {6.0, 7.0, 1.0},
        {9.0, 8.0, 2.0},
        {2.0, 5.0, 3.0},
        {7.0, 4.0, 2.0},
        {1.0, 9.0, 1.0}
    }; //Sample dataset with 10 points
    
    int clusters[k];
    //Randomly assign initial clusters for each point
    for (int i = 0; i < k; i++) {
        clusters[i] = rand() % 10;
    }
    
    Point clusterCenters[k];
    //Calculate initial cluster centers
    for (int i = 0; i < k; i++) {
        float xAvg = 0.0, yAvg = 0.0, zAvg = 0.0;
        int count = 0;
        for (int j = 0; j < 10; j++) {
            if (clusters[i] == j) {
                xAvg += dataset[j].x;
                yAvg += dataset[j].y;
                zAvg += dataset[j].z;
                count++;
            }
        }
        clusterCenters[i].x = xAvg / count;
        clusterCenters[i].y = yAvg / count;
        clusterCenters[i].z = zAvg / count;
    }
    
    //Repeat until convergence
    int continueLoop = 1;
    while (continueLoop) {
        continueLoop = 0;
        //Assign each point to the nearest cluster center
        for (int i = 0; i < 10; i++) {
            float minDistance = INFINITY;
            int nearestCluster = 0;
            for (int j = 0; j < k; j++) {
                float distance = getDistance(dataset[i], clusterCenters[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestCluster = j;
                }
            }
            if (clusters[nearestCluster] != i) {
                clusters[nearestCluster] = i;
                continueLoop = 1;
            }
        }
        
        //Calculate new cluster centers
        for (int i = 0; i < k; i++) {
            float xAvg = 0.0, yAvg = 0.0, zAvg = 0.0;
            int count = 0;
            for (int j = 0; j < 10; j++) {
                if (clusters[i] == j) {
                    xAvg += dataset[j].x;
                    yAvg += dataset[j].y;
                    zAvg += dataset[j].z;
                    count++;
                }
            }
            Point newClusterCenter;
            newClusterCenter.x = xAvg / count;
            newClusterCenter.y = yAvg / count;
            newClusterCenter.z = zAvg / count;
            if (newClusterCenter.x != clusterCenters[i].x || newClusterCenter.y != clusterCenters[i].y || newClusterCenter.z != clusterCenters[i].z) {
                clusterCenters[i] = newClusterCenter;
                continueLoop = 1;
            }
        }
    }
    
    //Print out final clusters
    printf("Final clusters:\n");
    for (int i = 0; i < k; i++) {
        printf("Cluster %d: [", i);
        for (int j = 0; j < 10; j++) {
            if (clusters[j] == i) {
                printf("%d ", j);
            }
        }
        printf("]\n");
    }
    
    return 0;
}