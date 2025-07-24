//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 1000
#define THRESHOLD 0.01

typedef struct{
    double x;
    double y;
}point;

double distance(point a, point b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

int main(){
    srand(time(0));
    point data[N];
    for(int i=0; i<N; i++){
        data[i].x = rand()%100;
        data[i].y = rand()%100;
    }

    int num_clusters = 5;
    point centroids[num_clusters];

    //initialize cluster centroids
    for(int i=0; i<num_clusters; i++){
        centroids[i].x = rand()%100;
        centroids[i].y = rand()%100;
    }

    //initialize cluster assignments
    int cluster_assignments[N] = {0};

    double prev_cost = -1;
    double cost = 0;
    while(fabs(prev_cost - cost) > THRESHOLD){
        prev_cost = cost;

        //assign each point to its nearest cluster
        for(int i=0; i<N; i++){
            double min_dist = distance(data[i], centroids[0]);
            int closest_cluster = 0;

            for(int j=1; j<num_clusters; j++){
                double dist = distance(data[i], centroids[j]);
                if(dist < min_dist){
                    min_dist = dist;
                    closest_cluster = j;
                }
            }

            cluster_assignments[i] = closest_cluster;
        }

        //recalculate cluster centroids
        for(int i=0; i<num_clusters; i++){
            double sum_x = 0;
            double sum_y = 0;
            int count = 0;

            for(int j=0; j<N; j++){
                if(cluster_assignments[j] == i){
                    sum_x += data[j].x;
                    sum_y += data[j].y;
                    count++;
                }
            }

            centroids[i].x = sum_x/count;
            centroids[i].y = sum_y/count;
        }

        //calculate total cost
        cost = 0;
        for(int i=0; i<N; i++){
            int cluster = cluster_assignments[i];
            cost += pow(distance(data[i], centroids[cluster]), 2);
        }
    }

    for(int i=0; i<num_clusters; i++){
        printf("Cluster %d centroid: (%f, %f)\n", i, centroids[i].x, centroids[i].y);
    }

    return 0;
}