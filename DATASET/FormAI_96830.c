//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr_size = 1000000;
    int arr[arr_size];
    clock_t start_time, end_time;
    double time_elapsed;

    // Populate array with random numbers
    for(int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 1000;
    }

    // Bubble sort algorithm
    int temp;
    start_time = clock();
    for(int i = 0; i < arr_size; i++) {
        for(int j = 0; j < arr_size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end_time = clock();

    // Calculate time elapsed
    time_elapsed = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Bubble sort performed on array of size %d\n", arr_size);
    printf("Time elapsed: %f seconds\n", time_elapsed);

    return 0;
}