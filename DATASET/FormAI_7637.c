//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Defining constants
#define NC 4 // Number of Clusters 
#define NP 200 // Number of Data Points
#define NM 50 // Maximum Number of iterations
#define DIM 2 // Number of Dimensions of Data Points

// Function to calculate distance between two points
float calc_distance(float a[], float b[]){
    float distance = 0.0;
    for(int i=0;i<DIM;i++){
        distance += pow(a[i]-b[i],2);
    }
    return sqrt(distance);
}

int main(){
    srand(time(NULL));
    float data_points[NP][DIM]; // Data Points array
    
    // Generating Random Data Points
    for(int i=0;i<NP;i++){
        for(int j=0;j<DIM;j++){
            data_points[i][j] = (float) rand() / RAND_MAX;
        }
    }

    float cluster_centers[NC][DIM]; // Cluster Centers array

    // Initializing Cluster Centers using first NC Data Points
    for(int i=0;i<NC;i++){
        for(int j=0;j<DIM;j++){
            cluster_centers[i][j] = data_points[i][j];
        }
    }

    int cluster_assignments[NP]; // Cluster Assignments array

    // Cluster Assignment and Recalculation of Cluster Centers
    for(int k=0;k<NM;k++){
        // Assigning each Data Point to its closest Cluster Center
        for(int i=0;i<NP;i++){
            float min_distance = INFINITY;
            for(int j=0;j<NC;j++){
                float distance = calc_distance(data_points[i], cluster_centers[j]);
                if(distance < min_distance){
                    min_distance = distance;
                    cluster_assignments[i] = j;
                }
            }
        }
        // Recalculating Cluster Centers
        for(int i=0;i<NC;i++){
            float sum[DIM] = {0};
            int count = 0;
            for(int j=0;j<NP;j++){
                if(cluster_assignments[j] == i){
                    count++;
                    for(int d=0;d<DIM;d++){
                        sum[d] += data_points[j][d];
                    }
                }
            }
            if(count > 0){
                for(int d=0;d<DIM;d++){
                    cluster_centers[i][d] = sum[d] / count;
                }
            }
        }
    }

    // Printing Final Cluster Assignments
    printf("\nFinal Cluster Assignments:\n");
    for(int i=0;i<NP;i++){
        printf("%d ", cluster_assignments[i]);
    }
    printf("\n");

    return 0;
}