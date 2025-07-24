//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 100

// function to get the distance between two points
float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

// function to initialize the clusters
void initClusters(float *x, float *y, int *cluster, int n, int k){
    for(int i=0;i<n;i++){
        cluster[i] = rand()%k+1;
    }
}

// function to calculate the centroid of the cluster
void centroid(int cluster_id, float *x, float *y, int *cluster, int n){
    int count = 0;
    float x_centroid = 0, y_centroid = 0;
    for(int i=0;i<n;i++){
        if(cluster[i]==cluster_id){
            x_centroid += x[i];
            y_centroid += y[i];
            count++;
        }
    }
    x_centroid /= count;
    y_centroid /= count;
    printf("Centroid %d: (%.2f,%.2f)\n", cluster_id, x_centroid, y_centroid);
}

// function to update the cluster of each data point based on the current centroids
void updateClusters(float *x, float *y, int *cluster, int n, float *centroids, int k){
    for(int i=0;i<n;i++){
        float min_dist = distance(x[i], y[i], centroids[0], centroids[1]);
        int min_cluster = 0;
        for(int j=1;j<k;j++){
            float dist = distance(x[i], y[i], centroids[2*j], centroids[2*j+1]);
            if(dist<min_dist){
                min_dist = dist;
                min_cluster = j;
            }
        }
        cluster[i] = min_cluster+1;
    }
}

int main(){
    // take input from user
    int n, k;
    printf("Enter the number of data points: ");
    scanf("%d",&n);
    printf("Enter the number of clusters: ");
    scanf("%d",&k);
    float x[n], y[n];

    // randomly generate the data points
    printf("Generating %d data points randomly...\n", n);
    for(int i=0;i<n;i++){
        x[i] = rand()%MAX_SIZE;
        y[i] = rand()%MAX_SIZE;
        printf("Data point %d: (%.2f,%.2f)\n", i+1, x[i], y[i]);
    }

    // initialize the clusters
    int cluster[n];
    initClusters(x, y, cluster, n, k);
    printf("Initial clusters:\n");
    for(int i=0;i<n;i++){
        printf("Data point %d: Cluster %d\n", i+1, cluster[i]);
    }

    // perform clustering
    float centroids[2*k];
    for(int i=0;i<k;i++){
        centroid(i+1, x, y, cluster, n);
        centroids[2*i] = rand()%MAX_SIZE;
        centroids[2*i+1] = rand()%MAX_SIZE;
    }
    printf("Initial centroids:\n");
    for(int i=0;i<k;i++){
        printf("Cluster %d: (%.2f,%.2f)\n", i+1, centroids[2*i], centroids[2*i+1]);
    }
    printf("\nPerforming clustering...\n");
    for(int i=0;i<10;i++){
        printf("Iteration %d:\n",i+1);
        updateClusters(x, y, cluster, n, centroids, k);
        for(int j=0;j<k;j++){
            centroid(j+1, x, y, cluster, n);
            centroids[2*j] += rand()%MAX_SIZE/10.0;
            centroids[2*j+1] += rand()%MAX_SIZE/10.0;
        }
    }

    // print the final clusters
    printf("\nFinal clusters:\n");
    for(int i=0;i<n;i++){
        printf("Data point %d: Cluster %d\n", i+1, cluster[i]);
    }
    return 0;
}