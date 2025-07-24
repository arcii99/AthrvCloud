//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMENSIONS 2
#define CLUSTERS 3
#define POINTS 10

typedef struct{
    double x[DIMENSIONS];
    int cluster;
} Point;

typedef struct{
    Point center;
    Point list[POINTS];
    int count;
} Cluster;

double dist(Point a, Point b){
    double sum = 0;
    int i;
    for(i = 0; i < DIMENSIONS; i++){
        sum += pow(a.x[i] - b.x[i], 2);
    }
    return sqrt(sum);
}

void assign_cluster(Point *point, Cluster *clusters){
    double minDist = INFINITY;
    int i, j, index = 0;
    for(i = 0; i < CLUSTERS; i++){
        double d = dist(*point, clusters[i].center);
        if(d < minDist){
            minDist = d;
            index = i;
        }
    }
    point->cluster = index;
    clusters[index].list[clusters[index].count++] = *point;
}

void print_cluster(Cluster *clusters){
    int i, j, k;
    for(i = 0; i < CLUSTERS; i++){
        printf("Cluster %d:\n", i);
        printf("Center: [");
        for(j = 0; j < DIMENSIONS; j++){
            printf("%.1f", clusters[i].center.x[j]);
            if(j < DIMENSIONS - 1)
                printf(", ");
        }
        printf("]\nPoints:\n");
        for(k = 0; k < clusters[i].count; k++){
            printf("[");
            for(j = 0; j < DIMENSIONS; j++){
                printf("%.1f", clusters[i].list[k].x[j]);
                if(j < DIMENSIONS - 1)
                    printf(", ");
            }
            printf("]\n");
        }
        printf("\n");
    }
}

void update_center(Cluster *clusters){
    int i, j, k;
    for(i = 0; i < CLUSTERS; i++){
        double sum[DIMENSIONS];
        for(k = 0; k < DIMENSIONS; k++){
            sum[k] = 0;
            for(j = 0; j < clusters[i].count; j++){
                sum[k] += clusters[i].list[j].x[k];
            }
        }
        for(k = 0; k < DIMENSIONS; k++){
            clusters[i].center.x[k] = sum[k] / clusters[i].count;
        }
    }
}

int main(){
    int i;
    Point data[POINTS];
    Cluster clusters[CLUSTERS];
    
    //initialize data
    for(i = 0; i < POINTS; i++){
        data[i].x[0] = rand() % 10;
        data[i].x[1] = rand() % 10;
        data[i].cluster = -1;
    }
    
    //initialize clusters
    for(i = 0; i < CLUSTERS; i++){
        clusters[i].center = data[rand() % POINTS];
        clusters[i].count = 0;
    }
    
    printf("Initial Clusters:\n");
    print_cluster(clusters);
    
    int changed = 1;
    while(changed){
        //assign points to clusters
        for(i = 0; i < POINTS; i++){
            assign_cluster(&data[i], clusters);
        }
        
        Cluster old_clusters[CLUSTERS];
        for(i = 0; i < CLUSTERS; i++){
            old_clusters[i] = clusters[i];
        }
        
        //update cluster centers
        update_center(clusters);
        
        //check if clusters have changed
        changed = 0;
        for(i = 0; i < CLUSTERS; i++){
            if(old_clusters[i].center.x[0] != clusters[i].center.x[0] || old_clusters[i].center.x[1] != clusters[i].center.x[1]){
                changed = 1;
                break;
            }
        }
        
        printf("Updated Clusters:\n");
        print_cluster(clusters);
    }
    
    return 0;
}