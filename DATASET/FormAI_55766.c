//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define k 3     //number of clusters
#define n 10    //number of data points

float euclideanDistance(float x1, float y1, float x2, float y2){
    float d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return d;
}

int main()
{
    //data points
    float data[n][2] = {{1.2, 3.7}, {4.1, 7.9}, {2.8, 1.3}, {7.9, 9.7}, {9.2, 6.6},
                     {10, 7.1}, {5.6, 2.3}, {6.1, 1.5}, {9.5, 7.1}, {8.1, 5.4}};
                     
    //initial centroids
    float centroids[k][2] = {{1.2, 3.7}, {9.2, 6.6}, {6.1, 1.5}};
    
    //arrays to hold cluster information
    int cluster[n]; //stores index of centroid that is closest to data point
    float distances[n][k]; //stores distances between all data points and centroids
    
    //loop variable declarations
    int i, j, c, closestCentroidIndex;
    
    //initialize clusters
    for(i = 0; i < n; i++){
        cluster[i] = -1; //set all indices to -1
    }
    
    //loop through data points and calculate distances
    for(i = 0; i < n; i++){
        for(j = 0; j < k; j++){
            distances[i][j] = euclideanDistance(data[i][0], data[i][1], 
                                                centroids[j][0], centroids[j][1]);
        }
    }
    
    //loop through data points and assign them to a cluster
    for(i = 0; i < n; i++){
        float minDistance = distances[i][0];
        closestCentroidIndex = 0;
        for(j = 0; j < k; j++){
            if(distances[i][j] < minDistance){
                minDistance = distances[i][j];
                closestCentroidIndex = j;
            }
        }
        cluster[i] = closestCentroidIndex;
    }
    
    //update centroid locations
    for(c = 0; c < k; c++){
        int count = 0;
        float xSum = 0, ySum = 0;
        for(i = 0; i < n; i++){
            if(cluster[i] == c){
                xSum += data[i][0];
                ySum += data[i][1];
                count++;
            }
        }
        centroids[c][0] = xSum / count;
        centroids[c][1] = ySum / count;
    }
    
    //print clusters
    for(c = 0; c < k; c++){
        printf("\nCluster %d: \n", c+1);
        for(i = 0; i < n; i++){
            if(cluster[i] == c){
                printf("(%f, %f) ", data[i][0], data[i][1]);
            }
        }
    }
    
    return 0;
}