//FormAI DATASET v1.0 Category: Benchmarking ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 1000000

int main()
{
    int i, sum = 0;
    clock_t t1, t2;
    double time_diff;
    int array[SIZE];

    // initialize array with random values
    for(i = 0; i < SIZE; i++)
        array[i] = rand() % 100 + 1;

    // Method 1: Loop through array using array indexing
    t1 = clock();
    for(i = 0; i < SIZE; i++)
        sum += array[i];
    t2 = clock();
    time_diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Method 1: Sum is %d, Time taken: %f seconds\n\n", sum, time_diff);

    sum = 0; // reset sum variable

    // Method 2: Loop through array using pointer arithmetic
    int *ptr = &array[0];
    t1 = clock();
    for(i = 0; i < SIZE; i++)
    {
        sum += *ptr;
        ptr++;
    }
    t2 = clock();
    time_diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Method 2: Sum is %d, Time taken: %f seconds\n\n", sum, time_diff);

    sum = 0; // reset sum variable

    // Method 3: Loop through array using pointer arithmetic with pre-increment
    ptr = &array[0];
    t1 = clock();
    for(i = 0; i < SIZE; i++, ptr++)
        sum += *ptr;
    t2 = clock();
    time_diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Method 3: Sum is %d, Time taken: %f seconds\n\n", sum, time_diff);

    sum = 0; // reset sum variable

    // Method 4: Loop through array using pointer arithmetic with array size checking
    ptr = &array[0];
    int *end = &array[SIZE];
    t1 = clock();
    while(ptr < end)
    {
        sum += *ptr;
        ptr++;
    }
    t2 = clock();
    time_diff = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Method 4: Sum is %d, Time taken: %f seconds\n\n", sum, time_diff);

    return 0;
}