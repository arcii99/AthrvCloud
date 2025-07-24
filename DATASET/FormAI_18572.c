//FormAI DATASET v1.0 Category: Math exercise ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int array[10] = {5, 8, 2, 9, 3, 6, 1, 7, 4, 0}; // initialize an array with 10 integers
    float mean, variance; // declare mean and variance variables

    printf("The given array is: ");
    // print all the integers in array
    for(int i=0; i<10; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    // calculate the mean of the array
    for(int i=0; i<10; i++){
        mean += array[i];
    }
    mean /= 10.0;
    printf("The mean of the array is: %0.2f\n", mean);

    // calculate the variance of the array
    for(int i=0; i<10; i++){
        variance += pow((array[i]-mean), 2);
    }
    variance /= 10.0;
    printf("The variance of the array is: %0.2f\n", variance);

    // calculate the standard deviation of the array
    float standard_deviation = sqrt(variance);
    printf("The standard deviation of the array is: %0.2f\n", standard_deviation);

    return 0; // end of program
}