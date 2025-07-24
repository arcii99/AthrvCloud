//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 // number of rows in dataset
#define COLS 5 // number of columns in dataset

// function to find minimum value of an attribute
float minValue(float dataset[][COLS], int colIndex) {
    float minVal = dataset[0][colIndex];
    for(int i=0; i<ROWS; i++) {
        if(dataset[i][colIndex] < minVal) {
            minVal = dataset[i][colIndex];
        }
    }
    return minVal;
}

// function to find maximum value of an attribute
float maxValue(float dataset[][COLS], int colIndex) {
    float maxVal = dataset[0][colIndex];
    for(int i=0; i<ROWS; i++) {
        if(dataset[i][colIndex] > maxVal) {
            maxVal = dataset[i][colIndex];
        }
    }
    return maxVal;
}

// function to normalize a given attribute in the dataset
void normalizeAttribute(float dataset[][COLS], int colIndex) {
    float minVal = minValue(dataset, colIndex);
    float maxVal = maxValue(dataset, colIndex);
    for(int i=0; i<ROWS; i++) {
        dataset[i][colIndex] = (dataset[i][colIndex] - minVal) / (maxVal - minVal);
    }
}

int main() {
    srand(time(NULL));
    float dataset[ROWS][COLS]; // dataset with random values 
    printf("Original Dataset:\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            dataset[i][j] = (float)rand()/(float)(RAND_MAX/100); // random values between 0 and 100
            printf("%.2f\t", dataset[i][j]);
        }
        printf("\n");
    }
    printf("\nNormalized Dataset:\n");
    for(int j=0; j<COLS; j++) {
        normalizeAttribute(dataset, j);
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%.2f\t", dataset[i][j]);
        }
        printf("\n");
    }
    return 0;
}