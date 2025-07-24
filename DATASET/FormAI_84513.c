//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#define MAX 50 // Maximum number of clusters
#define POINTS 1000 // Number of points

int main()
{
    int points[POINTS], clusters[MAX], count[MAX];
    int i,j,k,min_dis,dis,temp,index;
    // Initializing points and clusters
    for(i=0;i<POINTS;i++)
        points[i] = rand()%100; // Randomly assigning points
    for(i=0;i<MAX;i++){
        clusters[i] = rand()%100; // Randomly assigning clusters
        count[i] = 0;
    }
    // Clustering Algorithm
    for(i=0;i<POINTS;i++){
        min_dis = abs(points[i] - clusters[0]); // Initalizing minimum distance
        index = 0;
        for(j=0;j<MAX;j++){
            dis = abs(points[i] - clusters[j]);
            if(dis < min_dis){
                min_dis = dis;
                index = j;
            }
        }
        // Assigning point to the nearest cluster
        count[index]++;
    }
    // Printing the clusters
    for(i=0;i<MAX;i++){
        printf("Cluster %d: ", i+1);
        for(j=0;j<count[i];j++){
            printf("%d ", clusters[i]);
        }
        printf("\n");
    }

    return 0;
}