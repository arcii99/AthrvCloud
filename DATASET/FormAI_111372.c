//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
#define K 3 // number of clusters
 
int main(){
    float data[] = { 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5 };
    int n = sizeof(data)/sizeof(data[0]);
    float centers[K] = { 1.0, 3.0, 5.0 }; // initial centroids
 
    float distances[K];
    int labels[n];
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < K; j++){
            distances[j] = fabs(data[i] - centers[j]);
        }
        int min_label = 0;
        float min_distance = distances[0];
        for(int j = 1; j < K; j++){
            if(distances[j] < min_distance){
                min_label = j;
                min_distance = distances[j];
            }
        }
        labels[i] = min_label;
    }
 
    // update centroids
    float sums[K] = { 0 };
    int counts[K] = { 0 };
    for(int i = 0; i < n; i++){
        sums[labels[i]] += data[i];
        counts[labels[i]]++;
    }
    for(int j = 0; j < K; j++){
        centers[j] = sums[j] / counts[j];
    }
 
    return 0;
}