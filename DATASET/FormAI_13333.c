//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define NO_OF_POINTS 100
#define NO_OF_CLUSTERS 3

struct point{
    double x;
    double y;
    int cluster_no;
};

struct cluster{
    double x;
    double y;
    int no_of_points;
    struct point points[NO_OF_POINTS];
};

double euclidean_distance(struct point p1, struct point p2);
void initialize_clusters(struct point points[], struct cluster clusters[]);
void assign_points_to_clusters(struct point points[], struct cluster clusters[]);
void update_cluster_centers(struct point points[], struct cluster clusters[]);

int main(){
    struct point points[NO_OF_POINTS];
    struct cluster clusters[NO_OF_CLUSTERS];
    int i, j, k;

    /* Generate random points */
    srand(0);
    for(i = 0; i < NO_OF_POINTS; i++){
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    initialize_clusters(points, clusters);

    /* K-means Clustering */
    for(k = 0; k < 10; k++){ // run 10 iterations
        assign_points_to_clusters(points, clusters);
        update_cluster_centers(points, clusters);
    }

    /* Print the points in each cluster */
    for(i = 0; i < NO_OF_CLUSTERS; i++){
        printf("Cluster %d: ", i);
        for(j = 0; j < clusters[i].no_of_points; j++){
            printf("(%lf, %lf) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    return 0;
}

double euclidean_distance(struct point p1, struct point p2){
    double d = sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
    return d;
}

void initialize_clusters(struct point points[], struct cluster clusters[]){
    int i;

    /* Assign initial cluster centers */
    clusters[0].x = rand() % 100;
    clusters[0].y = rand() % 100;
    clusters[1].x = rand() % 100;
    clusters[1].y = rand() % 100;
    clusters[2].x = rand() % 100;
    clusters[2].y = rand() % 100;

    /* Assign all points to the first cluster initially */
    for(i = 0; i < NO_OF_POINTS; i++){
        points[i].cluster_no = 0;
        clusters[0].points[i] = points[i];
        clusters[0].no_of_points++;
    }
}

void assign_points_to_clusters(struct point points[], struct cluster clusters[]){
    int i, j, min_distance_cluster_no;
    double min_distance, distance;

    for(i = 0; i < NO_OF_POINTS; i++){
        min_distance = euclidean_distance(points[i], clusters[0].points[0]);
        min_distance_cluster_no = 0;
        for(j = 1; j < NO_OF_CLUSTERS; j++){
            distance = euclidean_distance(points[i], clusters[j].points[0]);
            if(distance < min_distance){
                min_distance = distance;
                min_distance_cluster_no = j;
            }
        }
        if(points[i].cluster_no != min_distance_cluster_no){ // if point changes cluster
            clusters[points[i].cluster_no].no_of_points--;
            clusters[min_distance_cluster_no].no_of_points++;
            clusters[min_distance_cluster_no].points[clusters[min_distance_cluster_no].no_of_points-1] = points[i];
            points[i].cluster_no = min_distance_cluster_no;
        }
    }
}

void update_cluster_centers(struct point points[], struct cluster clusters[]){
    int i, j;
    double sum_x, sum_y;

    for(i = 0; i < NO_OF_CLUSTERS; i++){
        sum_x = 0;
        sum_y = 0;
        for(j = 0; j < clusters[i].no_of_points; j++){
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].x = sum_x / clusters[i].no_of_points;
        clusters[i].y = sum_y / clusters[i].no_of_points;
    }
}