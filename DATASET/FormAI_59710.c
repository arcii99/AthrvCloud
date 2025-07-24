//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: introspective
/**
 * Program: find_max.c
 * Description: This program finds the maximum number out of an array of positive 
 *              integers.
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int main() {
    int double_array[ARRAY_SIZE]; // declare an array of size 1000000
    int i, max;

    // fill the array with random positive integers
    for(i = 0; i < ARRAY_SIZE; i++) {
        double_array[i] = rand() % 1000000 + 1;
    }

    max = double_array[0]; // set the maximum to the first element in the array

    // iterate through the array to find the maximum element
    for(i = 1; i < ARRAY_SIZE; i++) {
        // if the current element is larger than the current maximum, update the maximum
        if(double_array[i] > max) {
            max = double_array[i];
        }
    }

    printf("The maximum number in the array is: %d\n", max);

    return 0;
}