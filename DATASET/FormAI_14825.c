//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define size 5

float findDistance(float x1, float y1, float x2, float y2){
    float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return distance;
}

int main(){
    float x[size] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float y[size] = {1.0, 2.0, 3.0, 4.0, 5.0};

    int cluster1[size];
    int cluster2[size];
    int num_cluster1 = 0;
    int num_cluster2 = 0;
    
    //initialize random centroids for both clusters
    float C1_x = x[0];
    float C1_y = y[0];
    float C2_x = x[size-1];
    float C2_y = y[size-1];

    float cost1, cost2, prevCost1 = 0, prevCost2 = 0;
    int iterations = 0;
    do{
        cost1 = 0;
        cost2 = 0;
        num_cluster1 = 0;
        num_cluster2 = 0;

        //assign data points to their nearest cluster centroid
        for(int i=0; i<size; i++){
            float d1 = findDistance(C1_x, C1_y, x[i], y[i]);
            float d2 = findDistance(C2_x, C2_y, x[i], y[i]);
            if(d1 <= d2){
                cluster1[num_cluster1] = i;
                num_cluster1++;
                cost1 += pow(d1, 2);
            }
            else{
                cluster2[num_cluster2] = i;
                num_cluster2++;
                cost2 += pow(d2, 2);
            }
        }

        //update centroids of clusters
        float sumX1 = 0, sumY1 = 0;
        float sumX2 = 0, sumY2 = 0;
        for(int i=0; i<num_cluster1; i++){
            sumX1 += x[cluster1[i]];
            sumY1 += y[cluster1[i]];
        }
        for(int i=0; i<num_cluster2; i++){
            sumX2 += x[cluster2[i]];
            sumY2 += y[cluster2[i]];
        }
        C1_x = sumX1/num_cluster1;
        C1_y = sumY1/num_cluster1;
        C2_x = sumX2/num_cluster2;
        C2_y = sumY2/num_cluster2;

        //calculate cost function
        cost1 /= num_cluster1;
        cost2 /= num_cluster2;
        iterations++;

        //print iteration details
        printf("Iteration %d:\nCluster 1: ", iterations);
        for(int i=0; i<num_cluster1; i++){
            printf("%d ", cluster1[i]);
        }
        printf("\nCentroid 1: %.2f, %.2f\nCost 1: %.2f\n\nCluster 2: ", C1_x, C1_y, cost1);
        for(int i=0; i<num_cluster2; i++){
            printf("%d ", cluster2[i]);
        }
        printf("\nCentroid 2: %.2f, %.2f\nCost 2: %.2f\n\n", C2_x, C2_y, cost2);

        //check if there is any change in cost function
        if(fabs(prevCost1 - cost1) < 0.00001 && fabs(prevCost2 - cost2) < 0.00001){
            break;
        }
        prevCost1 = cost1;
        prevCost2 = cost2;
    }while(iterations < 10); //run a maximum of 10 iterations

    return 0;
}