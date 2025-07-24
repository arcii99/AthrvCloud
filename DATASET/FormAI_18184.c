//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define MIN_NUM 50000
#define MAX_NUM 100000

int main() {

    int i, j;
    int sum = 0;
    struct timeval start_time, end_time;

    srand(time(NULL));

    int n = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
    int *arr = (int *) malloc(n * sizeof(int));

    for(i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    gettimeofday(&start_time, NULL);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            sum += arr[i] * arr[j];
        }
    }

    gettimeofday(&end_time, NULL);

    double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1e6;
    time_taken = (time_taken + (end_time.tv_usec - 
                  start_time.tv_usec)) * 1e-6;
    printf("Matrix multiplication of size %d took %lf seconds\n", n, time_taken);

    free(arr);

    return 0;
}