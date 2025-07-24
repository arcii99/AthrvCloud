//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTER_SIZE 150
#define DISTANCE_THRESHOLD 0.5

// A struct for holding data points
typedef struct{
    double x;
    double y;
    int cluster; // an ID for the current cluster the point belongs to
} Point;

// Function to read data points from a file and return them as an array of Point
Point* readPoints(char* filename, int* numPoints){
    FILE* fp = fopen(filename, "r");
    fscanf(fp, "%d", numPoints);

    Point* points = (Point*)malloc((*numPoints)*sizeof(Point));
    for(int i=0; i<*numPoints; i++){
        fscanf(fp, "%lf %lf", &points[i].x, &points[i].y);
        points[i].cluster = -1; // initialize to no cluster
    }

    fclose(fp);
    return points;
}

// Function to compute the Euclidean distance between two points
double distance(Point p1, Point p2){
    return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

// Function to randomly assign initial clusters to the points
void initializeClusters(Point* points, int numPoints, int numClusters){
    for(int i=0; i<numPoints; i++){
        points[i].cluster = rand()%numClusters;
    }
}

// Function to compute the centroid of a cluster of points
Point computeCentroid(Point* points, int numPoints){
    double xSum = 0, ySum = 0;
    for(int i=0; i<numPoints; i++){
        xSum += points[i].x;
        ySum += points[i].y;
    }
    Point centroid;
    centroid.x = xSum/numPoints;
    centroid.y = ySum/numPoints;
    return centroid;
}

// Function to update the clusters of the points based on their distances from the centroids
void updateClusters(Point* points, int numPoints, Point* centroids, int numClusters){
    for(int i=0; i<numPoints; i++){
        double minDist = INFINITY;
        int minCluster = -1;
        for(int j=0; j<numClusters; j++){
            double dist = distance(points[i], centroids[j]);
            if(dist < minDist){
                minDist = dist;
                minCluster = j;
            }
        }
        points[i].cluster = minCluster;
    }
}

// Function to run the k-means clustering algorithm on the given set of points
void kMeansClustering(Point* points, int numPoints, int numClusters){
    initializeClusters(points, numPoints, numClusters);

    Point* centroids = (Point*)malloc(numClusters*sizeof(Point));
    for(int i=0; i<numClusters; i++){
        centroids[i] = computeCentroid(points, numPoints);
    }

    int iter = 0;
    while(iter < 100){
        updateClusters(points, numPoints, centroids, numClusters);

        int numPointsInCluster[numClusters];
        for(int i=0; i<numClusters; i++){
            numPointsInCluster[i] = 0;
        }

        for(int i=0; i<numPoints; i++){
            numPointsInCluster[points[i].cluster]++;
        }

        for(int i=0; i<numClusters; i++){
            Point* clusterPoints = (Point*)malloc(numPointsInCluster[i]*sizeof(Point));
            int count = 0;
            for(int j=0; j<numPoints; j++){
                if(points[j].cluster == i){
                    clusterPoints[count++] = points[j];
                }
            }
            centroids[i] = computeCentroid(clusterPoints, numPointsInCluster[i]);
            free(clusterPoints);
        }

        int numChanged = 0;
        for(int i=0; i<numPoints; i++){
            double dist = distance(points[i], centroids[points[i].cluster]);
            if(dist > DISTANCE_THRESHOLD){
                int newCluster = rand()%numClusters;
                while(newCluster == points[i].cluster){
                    newCluster = rand()%numClusters;
                }
                points[i].cluster = newCluster;
                numChanged++;
            }
        }

        if(numChanged == 0) break;
        iter++;
    }

    free(centroids);
}

int main(){
    int numPoints, numClusters;
    Point* points = readPoints("data.txt", &numPoints);
    printf("Enter number of clusters: ");
    scanf("%d", &numClusters);

    kMeansClustering(points, numPoints, numClusters);

    for(int i=0; i<numPoints; i++){
        printf("Point (%lf, %lf) belongs to cluster %d\n", points[i].x, points[i].y, points[i].cluster);
    }

    free(points);

    return 0;
}