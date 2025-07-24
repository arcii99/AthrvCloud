//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // initialize random seed

    int sum = 0;
    double avg = 0;
    int arr[10000];

    // generate random numbers
    for(int i=0; i<10000; i++){
        arr[i] = rand() % 100;
    }

    clock_t start = clock(); // get start time

    // calculate sum
    for(int i=0; i<10000; i++){
        sum += arr[i];
    }

    // calculate average
    avg = (double)sum / 10000;

    clock_t end = clock(); // get end time
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sum: %d\n", sum);
    printf("Average: %f\n", avg);
    printf("Time taken: %f seconds\n", time_spent);

    return 0;
}