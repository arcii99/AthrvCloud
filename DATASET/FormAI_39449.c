//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

#define NUM_RECORDS 200
#define NUM_FEATURES 10

float data[NUM_RECORDS][NUM_FEATURES];

/*
A simple program to demonstrate data mining in C.

The data represents 200 records of 10 different features. The program calculates the mean and standard deviation of each feature in the data.

To run the program, simply compile and execute it. The output will print the mean and standard deviation for each feature.
*/

float get_mean(int feature){
    int i;
    float sum = 0;

    for(i=0; i<NUM_RECORDS; i++){
        sum += data[i][feature];
    }

    return sum / NUM_RECORDS;
}

float get_standard_deviation(int feature){
    int i;
    float sum = 0;
    float mean = get_mean(feature);

    for(i=0; i<NUM_RECORDS; i++){
        sum += (data[i][feature] - mean) * (data[i][feature] - mean);
    }

    return sqrt(sum / (NUM_RECORDS-1));
}

int main(){
    int i, j;

    // Generate random data
    for(i=0; i<NUM_RECORDS; i++){
        for(j=0; j<NUM_FEATURES; j++){
            data[i][j] = rand() % 100;
        }
    }

    // Print data
    printf("Data:\n");
    for(i=0; i<NUM_RECORDS; i++){
        for(j=0; j<NUM_FEATURES; j++){
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }

    // Calculate and print mean and standard deviation
    printf("\nMean:\n");
    for(i=0; i<NUM_FEATURES; i++){
        printf("%f ", get_mean(i));
    }

    printf("\n\nStandard Deviation:\n");
    for(i=0; i<NUM_FEATURES; i++){
        printf("%f ", get_standard_deviation(i));
    }

    return 0;
}