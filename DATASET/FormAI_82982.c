//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// define size of dataset
#define DATA_SIZE 10000

// function to generate random dataset
void randomDataGenerator(float dataset[], int size) {

    for(int i=0; i<size; i++) {
        dataset[i] = (float)rand()/(float)(RAND_MAX/100.0);
    }

}

int main() {

    // initialize dataset
    float dataset[DATA_SIZE];

    // generate random dataset
    randomDataGenerator(dataset, DATA_SIZE);

    // calculate the average of the dataset
    float sum = 0, average = 0;
    for(int i=0; i<DATA_SIZE; i++) {
        sum += dataset[i];
    }
    average = sum / DATA_SIZE;

    // calculate the standard deviation of the dataset
    float variance = 0, std_dev = 0;
    for(int i=0; i<DATA_SIZE; i++) {
        variance += (dataset[i] - average)*(dataset[i] - average);
    }
    variance /= DATA_SIZE;
    std_dev = sqrtf(variance);

    // print the results
    printf("Average: %f\n", average);
    printf("Standard Deviation: %f\n", std_dev);

    return 0;
}