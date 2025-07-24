//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define K 3 //Number of clusters
#define MAX_ITERATIONS 100 //Number of iterations to converge
#define N 10 //Number of data points to be clustered

//Fucntion to generate random data points
void generate_points(float *data_points) {
  for(int i=0;i<N;i++){
      *(data_points+i)=rand()%100; //Data point is between range 0-100
  }
}

//Function to calculate distance between two points
float euclidean_distance(float *point1, float *point2) {
  float distance=0.0f;
  for(int i=0;i<K;i++){
        distance += pow(point1[i]-point2[i],2);
  }
  return sqrt(distance);
}

//Function to return the index of the closest centroid
int closest_centroid(float *data_point, float **centroids) {
    float distance = euclidean_distance(data_point, centroids[0]);
    int index = 0;
    for(int i=1;i<K;i++){
        float temp_distance = euclidean_distance(data_point, centroids[i]);
        if(temp_distance < distance){
            distance = temp_distance;
            index = i;
        }
    }
    return index;
}

//Function to generate initial centroids
void init_kmeans(float **data, float **centroids) {
    for(int i=0;i<K;i++){
        for(int j=0;j<N/K;j++){
            centroids[i][j] = data[i][j];
        }
    }
}

//Main function
int main() {
    float *data_points[N];
    for(int i=0;i<N;i++){
        data_points[i] = (float *)calloc(K,sizeof(float)); //Allocate dynamic memory
    }
    generate_points(data_points[0]);
    generate_points(data_points[1]);
    generate_points(data_points[2]);

    //Initialize centroids
    float *centroids[K];
    for(int i=0;i<K;i++){
        centroids[i] = (float *)calloc(N/K,sizeof(float)); //Allocate dynamic memory
    }
    init_kmeans(data_points, centroids);

    int iterations=0;
    int index=0;
    float old_centroids[K][N/K];
    while(iterations < MAX_ITERATIONS) {
        //Assign data points to their closest centroid
        for(int i=0;i<N;i++) {
            index=closest_centroid(data_points[i], centroids);
          for(int j=0;j<K;j++) {
              if(j == index){
                  //Naive Check for assignment, if data point already in correct cluster, then skip the update
                  break;
              }
              if( j == (K-1) ) {
                    //Copy data point to other centroid
                    for(int k=0;k<K;k++){
                        old_centroids[k][i] = centroids[k][i/K];
                        if(k==index){
                            centroids[k][i/K] = data_points[i][k];
                        }
                        else{
                            centroids[k][i/K] = old_centroids[k][i];
                        }
                    }
              }
          }
        }
    iterations++;
    }
  
    //Print final locations for centroids
    printf("\nFinal Centroids\n");
    for(int i=0;i<K;i++){
        printf("\nCentroid %d: \n",i+1);
        for(int j=0;j<N/K;j++){
            printf("%f ", centroids[i][j]);
        }
    }
    return 0;
}