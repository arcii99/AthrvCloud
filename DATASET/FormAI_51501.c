//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    clock_t start_t, end_t;
    double cpu_time_used;

    int arr[100000];
    int i, j, temp;

    for (i = 0; i < 100000; i++) {
        arr[i] = rand() % 1000;
    }

    start_t = clock();
    for (i = 0; i < 99999; i++) {
        for (j = 0; j < 99999-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end_t = clock();

    cpu_time_used = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;
    printf("The time taken by bubble sort is %lf seconds.", cpu_time_used);

    return 0;
}