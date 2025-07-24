//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define K 3

double points[N][2];
double centroids[K][2];

void init_data(){
    //Generate N random points
    for(int i=0;i<N;i++){
        points[i][0] = (double)rand()/(double)RAND_MAX;  //X-coordinate
        points[i][1] = (double)rand()/(double)RAND_MAX;  //Y-coordinate
    }

    //Randomly select K points to be initial centroids
    for(int i=0;i<K;i++){
        int idx = rand()%N;
        centroids[i][0] = points[idx][0];
        centroids[i][1] = points[idx][1];
    }
}

double euclidean_distance(double x1, double y1, double x2, double y2){
    //Calculate Euclidean distance between 2 points
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void assign_clusters(){
    double min_distance = INFINITY;

    //For each point, assign it to the nearest centroid
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            double distance = euclidean_distance(points[i][0], points[i][1], centroids[j][0], centroids[j][1]);
            if(distance<min_distance){
                //Point is closer to the jth centroid
                points[i][2] = j;
                min_distance = distance;
            }
        }
        min_distance = INFINITY;
    }
}

void update_centroids(){
    //For each cluster, recalculate its centroid
    for(int k=0;k<K;k++){
        double sum_x = 0;
        double sum_y= 0;
        int cluster_size = 0;

        for(int i=0;i<N;i++){
            if(points[i][2] == k){
                //Add point to cluster sum
                sum_x += points[i][0];
                sum_y += points[i][1];
                cluster_size++;
            }
        }

        //Calculate new centroid as average of cluster points
        centroids[k][0] = sum_x/(double)cluster_size;
        centroids[k][1] = sum_y/(double)cluster_size;
    }
}

void paranoid_clustering(){
    int iterations = 0;

    while(iterations<10){
        assign_clusters();    //Assign each point to a cluster based on current centroids
        update_centroids();   //Recalculate centroids based on current point clusters
        iterations++;

        printf("Iteration %d:\n", iterations);

        //Print point assignments and current centroids
        for(int i=0;i<N;i++){
            printf("Point %d: (%.2f,%.2f) assigned to cluster %d\n", i, points[i][0], points[i][1], (int)points[i][2]);
        }

        for(int k=0;k<K;k++){
            printf("Centroid %d: (%.2f,%.2f)\n", k, centroids[k][0], centroids[k][1]);
        }

        //Perform paranoid check to make sure all clusters have at least one point
        int num_empty_clusters = 0;
        for(int k=0;k<K;k++){
            int cluster_size = 0;
            for(int i=0;i<N;i++){
                if(points[i][2] == k){
                    cluster_size++;
                    break;
                }
            }
            if(cluster_size==0){
                num_empty_clusters++;
                //If a cluster is empty, randomly reassign one point to the empty cluster
                int idx = rand()%N;
                points[idx][2] = k;
            }
        }

        if(num_empty_clusters>0){
            printf("WARNING: %d empty clusters found! Performing random reassignment of points...\n", num_empty_clusters);
        }
    }
}

int main(){
    init_data();            //Generate random points and centroids
    paranoid_clustering();  //Perform paranoid clustering algorithm
    return 0;
}