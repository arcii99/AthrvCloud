//FormAI DATASET v1.0 Category: Data mining ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//function to calculate euclidean distance
float euclideanDist(float *p1, float *p2, int dim){
    float distance = 0.0;
    for(int i=0; i<dim; i++){
        distance += pow(p1[i]-p2[i], 2);
    }
    return sqrt(distance);
}

int main(){
    
    //initialize dataset
    float dataset[10][5] = {
        {5.1, 3.5, 1.4, 0.2, 0.0},
        {4.9, 3.0, 1.4, 0.2, 0.0},
        {4.7, 3.2, 1.3, 0.2, 0.0},
        {4.6, 3.1, 1.5, 0.2, 0.0},
        {5.0, 3.6, 1.4, 0.2, 0.0},
        {5.4, 3.9, 1.7, 0.4, 0.0},
        {4.6, 3.4, 1.4, 0.3, 0.0},
        {5.0, 3.4, 1.5, 0.2, 0.0},
        {4.4, 2.9, 1.4, 0.2, 0.0},
        {4.9, 3.1, 1.5, 0.1, 0.0}
    };
    
    int k = 3; //number of clusters
    
    //initialize cluster centers randomly
    float clusterCenters[k][4];
    srand(0);
    for(int i=0; i<k; i++){
        for(int j=0; j<4; j++){
            float range = (j == 3) ? 0.1 : 1.0;
            clusterCenters[i][j] = ((float)rand()/(float)RAND_MAX)*range;
        }
    }
    
    //initialize variables
    int maxIterations = 100;
    int iteration = 0;
    float epsilon = 0.01;
    float prevCost = INFINITY;
    float cost = 0.0;
    float clusterAssignment[10][k];
    
    //perform k-means clustering
    while(iteration < maxIterations && fabs(cost-prevCost) > epsilon){
        //reset cluster assignment
        for(int i=0; i<10; i++){
            for(int j=0; j<k; j++){
                clusterAssignment[i][j] = 0.0;
            }
        }
        //assign each data point to nearest cluster center
        cost = 0.0;
        for(int i=0; i<10; i++){
            float minDist = INFINITY;
            int closestCluster = -1;
            for(int j=0; j<k; j++){
                float dist = euclideanDist(dataset[i], clusterCenters[j], 4);
                if(dist < minDist){
                    minDist = dist;
                    closestCluster = j;
                }
            }
            clusterAssignment[i][closestCluster] = 1.0;
            cost += minDist;
        }
        //recompute cluster centers
        for(int j=0; j<k; j++){
            for(int l=0; l<4; l++){
                float sum = 0.0;
                float count = 0.0;
                for(int i=0; i<10; i++){
                    sum += clusterAssignment[i][j]*dataset[i][l];
                    count += clusterAssignment[i][j];
                }
                if(count > 0){
                    clusterCenters[j][l] = sum/count;
                }
            }
        }
        prevCost = cost;
        iteration++;
    }
    
    //print cluster assignments
    printf("Cluster Assignments:\n");
    for(int i=0; i<10; i++){
        printf("Data Point %d: ", i+1);
        for(int j=0; j<k; j++){
            if(clusterAssignment[i][j] > 0.0){
                printf("%d ", j+1);
            }
        }
        printf("\n");
    }
    
    //print cluster centers
    printf("Cluster Centers:\n");
    for(int i=0; i<k; i++){
        printf("Cluster %d: ", i+1);
        for(int j=0; j<4; j++){
            printf("%f ", clusterCenters[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}