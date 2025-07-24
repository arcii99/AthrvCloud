//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K 3 //Defining K as 3 for three clusters

//Structure to store data points
struct DataPoint{
    float x;
    float y;
};

//Function to calculate Euclidean distance between two points
float euclideanDistance(struct DataPoint a, struct DataPoint b) {
    float distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    return distance;
}

//Function to assign cluster to each data point
void assignClusters(struct DataPoint *data, struct DataPoint *centroids, int *cluster) {
    int i, j;
    float distance, min_distance;

    //Iterating through all the data points
    for(i=0;i<K;i++) {
        cluster[i] = i; //Setting the initial cluster assignment as the index of centroid array
    }

    //Iterating through the remaining data points
    for(i=K;i<10;i++) {
        min_distance = euclideanDistance(data[i], centroids[0]); //Setting initial minimum distance
        cluster[i] = 0; //Setting initial cluster assignment
        //Checking Euclidean distance with all the centroids and updating cluster assignment
        for(j=1;j<K;j++) {
            distance = euclideanDistance(data[i], centroids[j]);
            if(distance < min_distance) {
                min_distance = distance;
                cluster[i] = j;
            }
        }
    }
}

//Function to calculate new centroids
void calculateCentroids(struct DataPoint *data, struct DataPoint *centroids, int *cluster) {
    int i, j, count;
    float sum_x, sum_y;

    //Iterating through all clusters
    for(i=0;i<K;i++) {
        count = 0; //Initial count of data points in each cluster
        sum_x = 0; //Initial sum of x values in each cluster
        sum_y = 0; //Initial sum of y values in each cluster
        //Iterating through all data points and checking if a data point is in current cluster
        for(j=0;j<10;j++) {
            if(cluster[j] == i) {
                sum_x += data[j].x;
                sum_y += data[j].y;
                count++;
            }
        }
        //Calculating new centroid
        centroids[i].x = sum_x / count;
        centroids[i].y = sum_y / count;
    }
}

//Main function
int main() {
    struct DataPoint data[10] = {{1,1},{1.5,2},{3,4},{5,7},{3.5,5},{4.5,5},{3.5,4.5},{4.5,4.5},{5.5,6},{2,2.5}}; //Sample data points
    struct DataPoint centroids[K] = {{1,1},{3,4},{5,7}}; //Initial centroids
    int cluster[10]; //Cluster assignments

    int i, j, flag = 1, count = 0;

    while(flag) {
        assignClusters(data, centroids, cluster); //Assigning clusters to data points
        calculateCentroids(data, centroids, cluster); //Calculating new centroids
        count++; //Incrementing count of iterations

        //Checking for convergence
        flag = 0;
        for(i=0;i<K;i++) {
            for(j=0;j<10;j++) {
                if(cluster[j] == i && euclideanDistance(data[j], centroids[i]) > 0.01) {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
    }

    //Printing final cluster assignments and centroids
    printf("Final Cluster Assignments:\n");
    for(i=0;i<10;i++) {
        printf("Data Point %d: Cluster %d\n", i+1, cluster[i]+1);
    }

    printf("\nFinal Centroids:\n");
    for(i=0;i<K;i++) {
        printf("Centroid %d: (%.2f, %.2f)\n", i+1, centroids[i].x, centroids[i].y);
    }
    printf("\nNumber of iterations: %d\n", count);

    return 0;
}