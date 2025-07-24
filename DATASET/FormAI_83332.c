//FormAI DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define NUM_ROWS 10
#define NUM_COLS 5

// function to calculate the mean of an array
float mean(float arr[], int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// function to calculate the standard deviation of an array
float std_dev(float arr[], int size) {
    float m = mean(arr, size);
    float var = 0.0;
    for (int i = 0; i < size; i++) {
        var += pow(arr[i] - m, 2);
    }
    return sqrt(var / size);
}

// struct for storing the data
typedef struct {
    float data[NUM_COLS];
    bool is_class1;
} Record;

int main() {
    // create an array to hold the records
    Record data[NUM_ROWS];

    // populate the array with random data
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            data[i].data[j] = (float) rand() / RAND_MAX;
        }

        // randomly assign the class label
        if (data[i].data[0] < 0.5) {
            data[i].is_class1 = true;
        } else {
            data[i].is_class1 = false;
        }
    }

    // calculate the means and standard deviations for each column
    float means[NUM_COLS], std_devs[NUM_COLS];
    for (int i = 0; i < NUM_COLS; i++) {
        float arr[NUM_ROWS];
        for (int j = 0; j < NUM_ROWS; j++) {
            arr[j] = data[j].data[i];
        }
        means[i] = mean(arr, NUM_ROWS);
        std_devs[i] = std_dev(arr, NUM_ROWS);
    }

    // print out the means and standard deviations for each column
    printf("Means: ");
    for (int i = 0; i < NUM_COLS; i++) {
        printf("%.2f ", means[i]);
    }
    printf("\n");

    printf("Standard deviations: ");
    for (int i = 0; i < NUM_COLS; i++) {
        printf("%.2f ", std_devs[i]);
    }
    printf("\n");

    return 0;
}