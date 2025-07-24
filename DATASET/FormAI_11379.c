//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define K 3        //Number of Clusters
#define N 100      //Number of data points
#define M 2        //Number of features

double data[N][M];  //Data points
int assignment[N];  //Assigned cluster index
double centroids[K][M];  //Centroids of the clusters

double distance(double* p1, double* p2, int n){
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += pow(p1[i]-p2[i],2);
    }
    return sqrt(sum);
}

void init(){
    //Randomly initialize the centroids
    for(int i=0; i<K; i++){
        int idx = rand()%N;
        for(int j=0; j<M; j++){
            centroids[i][j] = data[idx][j];
        }
    }
}

void kMeans(){
    int maxIter = 100;
    for(int iter=0; iter<maxIter; iter++){
        //Assign each data point to the closest centroid
        for(int i=0; i<N; i++){
            double minDist = 1e9;
            int minIdx = -1;
            for(int j=0; j<K; j++){
                double dist = distance(data[i], centroids[j], M);
                if(dist<minDist){
                    minDist = dist;
                    minIdx = j;
                }
            }
            assignment[i] = minIdx;
        }

        //Update the centroids of each cluster
        for(int k=0; k<K; k++){
            int count = 0;
            double sum[M] = {0};
            for(int i=0; i<N; i++){
                if(assignment[i]==k){
                    for(int j=0; j<M; j++){
                        sum[j] += data[i][j];
                    }
                    count++;
                }
            }
            if(count>0){
                for(int j=0; j<M; j++){
                    centroids[k][j] = sum[j]/count;
                }
            }
        }
    }
}

int main(){
    //Generate random data points
    srand(time(0));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            data[i][j] = (double)rand()/RAND_MAX;
        }
    }

    init();
    kMeans();

    //Print the assigned cluster index for each data point
    for(int i=0; i<N; i++){
        printf("%d ", assignment[i]);
    }
    return 0;
}