//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Defining a structure to represent a point in the 2D space */

struct Point{
    float x;
    float y;
    int cluster;
    int visited;
};

/* Defining variables to be used in the algorithm */

int num_points, num_clusters;
float threshold;
struct Point *points;
struct Point *clusters;

/* Function to calculate distance between two points in 2D space */

float distance(struct Point p1, struct Point p2){
    float dist = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    return dist;
}

/* Function to randomly select initial clusters */

void select_clusters(){
    int i, j, index;
    for(i=0; i<num_clusters; i++){
        index = rand() % num_points;
        clusters[i] = points[index];
        for(j=0; j<i; j++){
            if(clusters[i].x == clusters[j].x && clusters[i].y == clusters[j].y){
                i--;
                break;
            }
        }
    }
}

/* Function to assign points to clusters */

void assign_clusters(){
    int i, j, k;
    float dist, min_dist;
    for(i=0; i<num_points; i++){
        min_dist = INFINITY;
        for(j=0; j<num_clusters; j++){
            dist = distance(points[i], clusters[j]);
            if(dist < min_dist){
                min_dist = dist;
                k = j;
            }
        }
        points[i].cluster = k;
    }
}

/* Function to re-calculate cluster centers */

void recalculate_centers(){
    int i, j, count;
    float sum_x, sum_y;
    for(i=0; i<num_clusters; i++){
        sum_x = 0.0;
        sum_y = 0.0;
        count = 0;
        for(j=0; j<num_points; j++){
            if(points[j].cluster == i){
                sum_x += points[j].x;
                sum_y += points[j].y;
                count++;
            }
        }
        clusters[i].x = sum_x / count;
        clusters[i].y = sum_y / count;
    }
}

/* Function to check if the algorithm has converged */

int check_convergence(){
    int i;
    for(i=0; i<num_points; i++){
        if(points[i].visited == 0){
            return 0;
        }
    }
    return 1;
}

/* Function to implement the clustering algorithm */

void k_means_clustering(){
    int i, j, iter = 0;
    select_clusters();
    while(1){
        assign_clusters();
        recalculate_centers();
        iter++;
        if(check_convergence() || iter == 100){
            break;
        }
    }
}

/* Function to print the results of the clustering */

void print_results(){
    int i, j;
    for(i=0; i<num_clusters; i++){
        printf("Cluster %d: (", i+1);
        for(j=0; j<num_points; j++){
            if(points[j].cluster == i){
                printf("%.2f, %.2f) ", points[j].x, points[j].y);
            }
        }
        printf("\n");
    }
}

/* Main function to run the program */

int main(){
    int i;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);
    points = (struct Point*)malloc(num_points*sizeof(struct Point));
    for(i=0; i<num_points; i++){
        printf("Enter the coordinates of point %d: ", i+1);
        scanf("%f%f", &points[i].x, &points[i].y);
        points[i].cluster = -1;
        points[i].visited = 0;
    }
    printf("Enter the number of clusters: ");
    scanf("%d", &num_clusters);
    clusters = (struct Point*)malloc(num_clusters*sizeof(struct Point));
    threshold = 0.001;
    k_means_clustering();
    print_results();
    return 0;
}