//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX_DATA_POINTS 100

/*struct for representing a data point*/
typedef struct{
    float x;
    float y;
    float distance;
    int cluster;
} data_point;

/*struct for representing a cluster*/
typedef struct{
    float x;
    float y;
    int num_points;
    data_point points[MAX_DATA_POINTS];
} cluster;

/*function to calculate Euclidean distance between two data points*/
float distance(data_point p, data_point q){
    return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
}

/*function to initialize k clusters randomly*/
void initialize_clusters(cluster clusters[], int k, data_point data[], int num_data_points){
    for(int i=0; i<k; i++){
        clusters[i].x = data[rand() % num_data_points].x;
        clusters[i].y = data[rand() % num_data_points].y;
        clusters[i].num_points = 0;
    }
}

/*function to assign each data point to the nearest cluster*/
void assign_clusters(cluster clusters[], int k, data_point data[], int num_data_points){
    for(int i=0; i<num_data_points; i++){
        float min_distance = INFINITY;
        for(int j=0; j<k; j++){
            float d = distance(data[i], clusters[j].points[0]);
            if(d < min_distance){
                min_distance = d;
                data[i].distance = d;
                data[i].cluster = j;
            }
        }
        clusters[data[i].cluster].points[clusters[data[i].cluster].num_points++] = data[i];
    }
}

/*function to recalculate the center of each cluster*/
void recalculate_centers(cluster clusters[], int k){
    for(int i=0; i<k; i++){
        float sum_x = 0, sum_y = 0;
        for(int j=0; j<clusters[i].num_points; j++){
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].x = sum_x / clusters[i].num_points;
        clusters[i].y = sum_y / clusters[i].num_points;
    }
}

/*function to print the current state of each cluster*/
void print_clusters(cluster clusters[], int k){
    for(int i=0; i<k; i++){
        printf("Cluster %d (Center: (%.2f, %.2f)):\n", i+1, clusters[i].x, clusters[i].y);
        for(int j=0; j<clusters[i].num_points; j++){
            printf("\t(%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}

/*function to check if the clusters have converged*/
int converged(cluster clusters[], int k){
    for(int i=0; i<k; i++){
        for(int j=0; j<clusters[i].num_points; j++){
            if(distance(clusters[i].points[j], clusters[i].points[0]) != 0){
                return 0;
            }
        }
    }
    return 1;
}

/*main function*/
int main(){
    int num_data_points, k;
    data_point data[MAX_DATA_POINTS];
    cluster clusters[MAX_DATA_POINTS];

    /*read input from user*/
    printf("Enter number of data points: ");
    scanf("%d", &num_data_points);

    printf("Enter data points in the format 'x y':\n");
    for(int i=0; i<num_data_points; i++){
        scanf("%f%f", &data[i].x, &data[i].y);
        data[i].cluster = -1;
        data[i].distance = 0;
    }

    printf("Enter number of clusters: ");
    scanf("%d", &k);

    /*initialize clusters randomly*/
    initialize_clusters(clusters, k, data, num_data_points);

    /*repeat until clusters converge*/
    int iterations = 0;
    while(!converged(clusters, k)){
        printf("\nIteration %d:\n", ++iterations);

        /*assign each data point to the nearest cluster*/
        assign_clusters(clusters, k, data, num_data_points);

        /*recalculate the center of each cluster*/
        recalculate_centers(clusters, k);

        /*print the current state of each cluster*/
        print_clusters(clusters, k);
    }

    return 0;
}