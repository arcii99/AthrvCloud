//FormAI DATASET v1.0 Category: Benchmarking ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

// Function to initialize an array with random values
void initialize_array(int *arr) {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++)
        arr[i] = rand() % 1000 + 1;
}

// Function to calculate the sum of elements in an array using a loop
int sum_using_loop(int *arr) {
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
        sum += arr[i];
    return sum;
}

// Function to calculate the sum of elements in an array using recursion
int sum_using_recursion(int *arr, int index) {
    if (index == ARRAY_SIZE - 1)
        return arr[index];
    return arr[index] + sum_using_recursion(arr, index+1);
}

int main() {
    int array[ARRAY_SIZE];
    initialize_array(array);
    
    clock_t start = clock(); // start timer
    
    int sum = 0;
    sum = sum_using_loop(array); // benchmarking loop
    
    clock_t stop = clock(); // stop timer
    double time_elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The sum using loop is: %d, Time elapsed: %f seconds\n", sum, time_elapsed);
    
    start = clock(); // reset timer
    
    sum = sum_using_recursion(array, 0); // benchmarking recursion
    
    stop = clock(); // stop timer
    time_elapsed = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("The sum using recursion is: %d, Time elapsed: %f seconds\n", sum, time_elapsed);
    
    return 0;
}