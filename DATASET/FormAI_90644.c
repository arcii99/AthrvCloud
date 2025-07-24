//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to perform benchmarking */
void benchmark(int input_size, int num_runs) {
    int i, j, *arr;
    double start_time, end_time, total_time = 0.0;
    printf("Performing benchmark for input size = %d and number of runs = %d\n", input_size, num_runs);
    for (i = 0; i < num_runs; i++) {
        arr = (int*)malloc(input_size * sizeof(int)); // allocate memory for array
        for (j = 0; j < input_size; j++) {
            arr[j] = rand(); // fill array with random values
        }
        start_time = (double)clock() / CLOCKS_PER_SEC; // record start time
        /* Insert your algorithm here */
        // For example, let's perform a bubble sort
        int temp;
        for (int k = 0; k < input_size - 1; k++) {
            for (int l = 0; l < input_size - k - 1; l++) {
                if (arr[l] > arr[l + 1]) {
                    temp = arr[l];
                    arr[l] = arr[l + 1];
                    arr[l + 1] = temp;
                }
            }
        }
        /* End of algorithm */
        end_time = (double)clock() / CLOCKS_PER_SEC; // record end time
        total_time += (end_time - start_time); // calculate total time
        free(arr); // free allocated memory
    }
    double avg_time = total_time / num_runs;
    printf("Average time taken: %lf seconds\n", avg_time);
}

/* Main function */
int main() {
    srand(time(0)); // seed random number generator
    benchmark(1000, 5);
    benchmark(10000, 5);
    benchmark(100000, 5);
    return 0;
}