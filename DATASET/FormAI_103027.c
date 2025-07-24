//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NUM_POINTS 100
#define THRESHOLD 0.01

typedef struct {
    float x;
    float y;
    float z;
} point;

typedef struct {
    float x;
    float y;
    float z;
} centroid;

void assign_points_to_clusters(point *points, centroid *centroids, int *assignments){
    float distance;
    float min_distance;
    int closest_centroid_index;
    for(int i=0;i<NUM_POINTS;i++){
        min_distance = INFINITY;
        closest_centroid_index = -1;
        for(int j=0;j<NUM_POINTS;j++){
            distance = sqrt(pow(points[i].x-centroids[j].x,2) + pow(points[i].y-centroids[j].y,2) + pow(points[i].z-centroids[j].z,2));
            if(distance < min_distance){
                min_distance = distance;
                closest_centroid_index = j;
            }
        }
        assignments[i] = closest_centroid_index;
    }
}

void update_centroids(point *points, centroid *centroids, int *assignments){
    int count;
    for(int i=0;i<NUM_POINTS;i++){
        count = 0;
        centroids[assignments[i]].x += points[i].x;
        centroids[assignments[i]].y += points[i].y;
        centroids[assignments[i]].z += points[i].z;
        count++;
    }
    for(int i=0;i<NUM_POINTS;i++){
        centroids[i].x /= count;
        centroids[i].y /= count;
        centroids[i].z /= count;
    }
}

float calculate_distance(centroid *prev_centroids, centroid *centroids){
    float distance = 0;
    for(int i=0;i<NUM_POINTS;i++){
        distance += sqrt(pow(prev_centroids[i].x-centroids[i].x,2) + pow(prev_centroids[i].y-centroids[i].y,2) + pow(prev_centroids[i].z-centroids[i].z,2));
    }
    return distance;
}

void k_means_clustering(point *points, centroid *centroids, int *assignments){
    centroid prev_centroids[NUM_POINTS];
    float distance;
    do{
        for(int i=0;i<NUM_POINTS;i++){
            prev_centroids[i].x = centroids[i].x;
            prev_centroids[i].y = centroids[i].y;
            prev_centroids[i].z = centroids[i].z;
        }
        assign_points_to_clusters(points, centroids, assignments);
        update_centroids(points, centroids, assignments);
        distance = calculate_distance(prev_centroids, centroids);
    }while(distance >= THRESHOLD);
}

int main(){
    point points[NUM_POINTS];
    centroid centroids[NUM_POINTS];
    int assignments[NUM_POINTS];

    //Initialize points array
    for(int i=0;i<NUM_POINTS;i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
        points[i].z = rand() % 100;
    }

    //Initialize centroids array
    centroids[0].x = rand() % 100;
    centroids[0].y = rand() % 100;
    centroids[0].z = rand() % 100;
    for(int i=1;i<NUM_POINTS;i++){
        int index = rand() % NUM_POINTS;
        centroids[i].x = points[index].x;
        centroids[i].y = points[index].y;
        centroids[i].z = points[index].z;
    }

    k_means_clustering(points, centroids, assignments);

    //Print final centroids
    printf("Final centroids:\n");
    for(int i=0;i<NUM_POINTS;i++){
        printf("Centroid %d: (%.2f,%.2f,%.2f)\n", i, centroids[i].x, centroids[i].y, centroids[i].z);
    }

    return 0;
}