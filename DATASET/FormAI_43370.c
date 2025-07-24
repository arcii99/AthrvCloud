//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define ROWS 50
#define COLS 2
#define CENTROID_ROWS 3
#define CENTROID_COLS 2
#define CLUSTER_SIZE 20

float data[ROWS][COLS] = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}, {11,12}, {13,14}, {15,16}, {17,18}, {19,20},
                          {21,22}, {23,24}, {25,26}, {27,28}, {29,30}, {31,32}, {33,34}, {35,36}, {37,38}, {39,40},
                          {41,42}, {43,44}, {45,46}, {47,48}, {49,50}, {2,3}, {4,5}, {6,7}, {8,9}, {10,11},
                          {12,13}, {14,15}, {16,17}, {18,19}, {20,21}, {22,23}, {24,25}, {26,27}, {28,29}, {30,31},
                          {32,33}, {34,35}, {36,37}, {38,39}, {40,41}, {42,43}, {44,45}, {46,47}, {48,49}, {50, 51}};

float centroids[CENTROID_ROWS][CENTROID_COLS] = {{5,6}, {15,16}, {30,31}};

int cluster_assignment[ROWS];

int main(int argc, char* argv[]){
    for(int k=0; k<1000; k++){
        // assign each data point to the closest centroid
        for(int i=0; i<ROWS; i++){
            float min_distance = INFINITY;
            int centroid_index;
            for(int j=0; j<CENTROID_ROWS; j++){
                float x_distance = data[i][0] - centroids[j][0];
                float y_distance = data[i][1] - centroids[j][1];
                float distance = sqrt(x_distance*x_distance + y_distance*y_distance);
                if(distance < min_distance){
                    min_distance = distance;
                    centroid_index = j;
                }
            }
            cluster_assignment[i] = centroid_index;
        }
        // recalculate centroids
        for(int i=0; i<CENTROID_ROWS; i++){
            float sum_x = 0;
            float sum_y = 0;
            int count = 0;
            for(int j=0; j<ROWS; j++){
                if(cluster_assignment[j] == i){
                    sum_x += data[j][0];
                    sum_y += data[j][1];
                    count++;
                }
            }
            centroids[i][0] = sum_x / count;
            centroids[i][1] = sum_y / count;
        }
    }
    // print final cluster assignments
    for(int i=0; i<CENTROID_ROWS; i++){
        printf("Cluster %d:\n", i);
        for(int j=0; j<ROWS; j++){
            if(cluster_assignment[j] == i){
                printf("(%f,%f)\n", data[j][0], data[j][1]);
            }
        }
    }
    return 0;
}