//FormAI DATASET v1.0 Category: Data mining ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

#define SIZE 1000 //set the maximum size for dataset

/* structure to store each data point */
typedef struct DataPoint{
    int id;
    float x;
    float y;
}DataPoint;

/* function to initialize the dataset with random data */
void initializeDataset(DataPoint dataset[]){
    for(int i=0; i<SIZE; ++i){
        dataset[i].id = i+1;
        dataset[i].x = ((float)rand()/(float)(RAND_MAX)) * 100; //generate random x value between 0 and 100
        dataset[i].y = ((float)rand()/(float)(RAND_MAX)) * 100; //generate random y value between 0 and 100
    }
}

/* function to print the dataset */
void printDataset(DataPoint dataset[]){
    printf("ID\tX\tY\n");
    for(int i=0; i<SIZE; ++i){
        printf("%d\t%.2f\t%.2f\n", dataset[i].id, dataset[i].x, dataset[i].y);
    }
}

/* function to find the data point with the highest x value */
DataPoint findMaxX(DataPoint dataset[]){
    DataPoint maxX = dataset[0];
    for(int i=1; i<SIZE; ++i){
        if(dataset[i].x > maxX.x){
            maxX = dataset[i];
        }
    }
    return maxX;
}

/* function to find the data point with the lowest y value */
DataPoint findMinY(DataPoint dataset[]){
    DataPoint minY = dataset[0];
    for(int i=1; i<SIZE; ++i){
        if(dataset[i].y < minY.y){
            minY = dataset[i];
        }
    }
    return minY;
}

/* main function */
int main(){
    DataPoint dataset[SIZE];
    initializeDataset(dataset);
    printf("Initial Dataset:\n");
    printDataset(dataset);
    DataPoint maxX = findMaxX(dataset);
    printf("\nData point with the highest X value: %d %.2f %.2f\n", maxX.id, maxX.x, maxX.y);
    DataPoint minY = findMinY(dataset);
    printf("Data point with the lowest Y value: %d %.2f %.2f\n", minY.id, minY.x, minY.y);
    return 0;
}