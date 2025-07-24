//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define K 2     // number of clusters to form
#define N 10    // number of data points to cluster

float data[N][2] = {{1,2},{1.5,3},{3,4},{5,6},{6,7},{7,8},{8,9},{9,10},{10,11},{11,12}};   // data points to cluster
float centroids[K][2] = {{2,3},{4,5}};                                                       // initial centroids
int clusters[K][N] = {0};                                                                   // clusters to store data points

float distance(float x1, float y1, float x2, float y2);                                      // helper function to calculate distance
void assignDataPoints();                                                                    // helper function to assign data points to clusters
void updateCentroids();                                                                     // helper function to update centroids

int main(){
    int i,j,k;
    printf("Initial centroids:\n");
    for(k=0; k<K; k++){
        for(i=0; i<2; i++){
            printf("%f ",centroids[k][i]);
        }
        printf("\n");
    }
    assignDataPoints();
    for(i=0; i<K; i++){
        printf("Cluster %d: ",i+1);
        for(j=0; j<N; j++){
            if(clusters[i][j]==1){
                printf("(%f,%f) ",data[j][0],data[j][1]);
            }
        }
        printf("\n");
    }
    updateCentroids();
    printf("\nUpdated centroids:\n");
    for(k=0; k<K; k++){
        for(i=0; i<2; i++){
            printf("%f ",centroids[k][i]);
        }
        printf("\n");
    }
    return 0;
}

float distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

void assignDataPoints(){
    int i,j,k,minIndex;
    float dist,minDist;
    for(i=0; i<N; i++){
        minIndex = 0;
        minDist = distance(data[i][0],data[i][1],centroids[0][0],centroids[0][1]);
        for(k=1; k<K; k++){
            dist = distance(data[i][0],data[i][1],centroids[k][0],centroids[k][1]);
            if(dist<minDist){
                minDist = dist;
                minIndex = k;
            }
        }
        for(j=0; j<N; j++){
            clusters[minIndex][j] = (j==i) ? 1 : clusters[minIndex][j];
        }
    }
}

void updateCentroids(){
    int i,j,k,sum=0;
    float xSum=0,ySum=0;
    for(k=0; k<K; k++){
        for(i=0; i<N; i++){
            if(clusters[k][i]==1){
                sum++;
                xSum += data[i][0];
                ySum += data[i][1];
            }
        }
        if(sum!=0){
            centroids[k][0] = xSum/sum;
            centroids[k][1] = ySum/sum;
        }
        sum = 0;
        xSum = 0;
        ySum = 0;
    }
}