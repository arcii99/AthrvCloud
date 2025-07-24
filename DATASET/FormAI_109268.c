//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
/* This program takes in two arrays of integers, performs a dot product operation and returns the result.
 It is designed to be optimized for performance, using C compiler optimization flags.*/
 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ARRAY_SIZE 10000 // Size of arrays

// Function to perform dot product
uint64_t dot_product(int32_t *a, int32_t *b, uint32_t size) 
{
    uint64_t result = 0;
    for (uint32_t i = 0; i < size; i++) 
    {
        result += (uint64_t)a[i] * b[i];
    }
    return result;
}

int main(int argc, char *argv[]) 
{
    int32_t array1[ARRAY_SIZE];
    int32_t array2[ARRAY_SIZE];
    uint64_t result;

    // Initialize arrays with random numbers
    for (uint32_t i = 0; i < ARRAY_SIZE; i++)
    {
        array1[i] = rand() % 1000;
        array2[i] = rand() % 1000;
    }

    // Call dot product function and get result
    result = dot_product(array1, array2, ARRAY_SIZE);

    // Print result
    printf("Dot Product: %lld\n", result);

    return 0;
}