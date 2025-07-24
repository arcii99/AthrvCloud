//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {

    srand(time(NULL));      // set random seed to the current time
    
    float num_array[10];     // declare an array of 10 floating point numbers
    int i;

    printf("Here are 10 randomly generated numbers between 1 and 100:\n");

    // fill the array with random numbers
    for (i = 0; i < 10; i++) {
        num_array[i] = (rand() % 100) + 1;      // generate random number between 1 and 100
        printf("%.2f ", num_array[i]);           // print out each number with 2 decimal points of precision
    }

    printf("\n\n");

    float mean = 0;
    float sum = 0;

    // calculate the mean of the array
    for (i = 0; i< 10; i++) {
        sum += num_array[i];
    }
    mean = sum / 10;

    printf("The mean of the numbers is: %.2f\n", mean);

    float variance = 0;

    // calculate the variance of the array
    for (i = 0; i < 10; i++) {
        variance += pow(num_array[i] - mean, 2);
    }
    variance = variance / 10;

    printf("The variance of the numbers is: %.2f\n", variance);

    float std_deviation = sqrt(variance);

    printf("The standard deviation of the numbers is: %.2f\n", std_deviation);

    return 0;
}