//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Linus Torvalds
#include <stdio.h>

#define CLUSTER_NUM 3
#define DATA_NUM 10

/* Euclidean Distance Calculation Function */
float dist(float a[2], float b[2]){
    float res = 0;
    for(int i=0; i<2; i++){
        res += (a[i]-b[i])*(a[i]-b[i]);
    }
    return res;
}

/* Recursive Clustering Function */
void cluster(float data[DATA_NUM][2], int assign[DATA_NUM], float clusters[CLUSTER_NUM][2], int index){
    // assign data points to clusters
    for(int i=0; i<DATA_NUM; i++){
        float min_d = 99999;
        int min_c = 0;
        for(int j=0; j<CLUSTER_NUM; j++){
            float d = dist(data[i], clusters[j]);
            if(d < min_d){
                min_d = d;
                min_c = j;
            }
        }
        assign[i] = min_c;
    }

    // update cluster positions
    float new_clusters[CLUSTER_NUM][2] = {0};
    int c_count[CLUSTER_NUM] = {0};
    for(int i=0; i<DATA_NUM; i++){
        int c = assign[i];
        new_clusters[c][0] += data[i][0];
        new_clusters[c][1] += data[i][1];
        c_count[c]++;
    }
    for(int i=0; i<CLUSTER_NUM; i++){
        if(c_count[i] != 0){
            clusters[i][0] = new_clusters[i][0]/c_count[i];
            clusters[i][1] = new_clusters[i][1]/c_count[i];
        }
    }

    // termination condition
    if(index == 0){
        return;
    }

    // recursion
    cluster(data, assign, clusters, index-1);
}

int main(){
    float data[DATA_NUM][2] = {
        {2.0, 3.0},
        {4.0, 5.0},
        {1.0, 6.0},
        {3.0, 4.0},
        {5.0, 2.0},
        {6.0, 5.0},
        {8.0, 8.0},
        {9.0, 10.0},
        {7.0, 9.0},
        {10.0, 7.0}
    };
    int assign[DATA_NUM] = {0};
    float clusters[CLUSTER_NUM][2] = {
        {2.0, 3.0},
        {8.0, 8.0},
        {9.0, 10.0}
    };
    cluster(data, assign, clusters, 10);
    for(int i=0; i<DATA_NUM; i++){
        printf("Data point %d assigned to Cluster %d\n", i, assign[i]);
    }
    return 0;
}