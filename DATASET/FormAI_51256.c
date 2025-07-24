//FormAI DATASET v1.0 Category: Benchmarking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000
#define ITERATIONS 100

int main() {
    int *data = (int*)malloc(SIZE * sizeof(int));

    // fill the array with random integers
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        data[i] = rand() % SIZE;
    }

    double total_time = 0.0;
    clock_t start_time, end_time;
    for(int j=0; j<ITERATIONS; j++) {
        start_time = clock(); // start time

        // bubble sort algorithm
        int temp;
        for(int i=0; i<SIZE-1; i++) {
            for(int j=0; j<SIZE-i-1; j++) {
                if(data[j] > data[j+1]) {
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }

        end_time = clock(); // end time
        total_time += (double)(end_time - start_time) / CLOCKS_PER_SEC; // calculate elapsed time and add to total
    }

    double avg_time = total_time / ITERATIONS;
    printf("Average time taken for Bubble Sort: %f seconds", avg_time);

    free(data);
    return 0;
}