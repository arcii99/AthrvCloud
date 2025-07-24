//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: statistical
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 10  //Number of data points
#define K 2 //Number of clusters

//Function to initialize centroids randomly
void initializeCentroids(double data[][2], int centroids[][2]) {
    int i, j;

    for(i=0; i<K; i++) {
        for(j=0; j<2; j++) {
            centroids[i][j] = rand() % 11; //Randomly assign coordinates between 0 and 10
        }
    }
}

//Function to calculate distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

//Function to assign each data point to a cluster based on distance from centroids
void assignDataPoints(double data[][2], int centroids[][2], int assignedCluster[]) {
    int i, j, k;
    double d1, d2;

    for(i=0; i<N; i++) {
        d1 = distance(data[i][0], data[i][1], centroids[0][0], centroids[0][1]);
        d2 = distance(data[i][0], data[i][1], centroids[1][0], centroids[1][1]);

        if(d1 < d2) {
            assignedCluster[i] = 0;
        } else {
            assignedCluster[i] = 1;
        }
    }
}

//Function to update centroids based on mean of data points assigned to them
void updateCentroids(double data[][2], int centroids[][2], int assignedCluster[]) {
    int i, j, k, count1 = 0, count2 = 0, sum1x = 0, sum1y = 0, sum2x = 0, sum2y = 0;

    for(i=0; i<N; i++) {
        if(assignedCluster[i] == 0) {
            count1++;
            sum1x += data[i][0];
            sum1y += data[i][1];
        } else {
            count2++;
            sum2x += data[i][0];
            sum2y += data[i][1];
        }
    }

    centroids[0][0] = sum1x/count1;
    centroids[0][1] = sum1y/count1;
    centroids[1][0] = sum2x/count2;
    centroids[1][1] = sum2y/count2;
}

//Function to print final cluster assignment
void printClusterAssignment(double data[][2], int assignedCluster[]) {
    int i;

    printf("Final cluster assignment:\n");
    for(i=0; i<N; i++) {
        printf("(%0.1f, %0.1f) belongs to cluster %d\n", data[i][0], data[i][1], assignedCluster[i]+1);
    }
}

int main() {
    double data[N][2] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {7, 5}, {6, 4}, {1, 2}, {4, 9}, {5, 4}, {6, 9}};
    int centroids[K][2], assignedCluster[N], i, j, k;

    initializeCentroids(data, centroids);

    printf("Initial centroids:\n");
    for(i=0; i<K; i++) {
        printf("(%d, %d)\n", centroids[i][0], centroids[i][1]);
    }

    for(k=0; k<5; k++) { //Number of iterations
        assignDataPoints(data, centroids, assignedCluster);
        updateCentroids(data, centroids, assignedCluster);
    }

    printf("\nFinal centroids:\n");
    for(i=0; i<K; i++) {
        printf("(%d, %d)\n", centroids[i][0], centroids[i][1]);
    }

    printClusterAssignment(data, assignedCluster);

    return 0;
}